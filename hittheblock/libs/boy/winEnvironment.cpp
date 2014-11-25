#include "winEnvironment.h"
#include "Game.h"
#include "winBase.h"
#include "Mouse.h"

using namespace Boy;
using namespace std;

winEnvironment::winEnvironment() {}
winEnvironment::~winEnvironment() {}

void winEnvironment::init(Game *game, int screenWidth, int screenHeight, bool fullscreen, const TCHAR *windowTitle)
{ mIsD3Dsetup=false;
	mLastUpdate = getTicks();
	mT0=getTicks();
	mUpdateCount=0;
	mIntervalFrameCount=0;
	//不想关闭程序 所以设置false
	mShutdownRequested=false;
	// remember the game:
	mGame = game;
	mMouse=new Mouse();
	mMaxFrameRate=180;
	Environment::init(game,screenWidth,screenHeight,fullscreen,windowTitle);
	initHinstane();
	// windows size
	mScreenWidth=screenWidth;
	mScreenHeight=screenHeight;
	mbWindowed=fullscreen;
	initWindow(windowTitle);
	initDirect3D();
	mD3DFont = new winD3DFont(mpDevice); 
	// graphics:
	mGraphics = new winGraphics(mpDevice);
	mGeometry=new Geometry();

}
bool winEnvironment::initWindow(const TCHAR* szTitle){
    WNDCLASSEX  wndclass ;
	wndclass.cbSize  = sizeof (wndclass) ;
	DWORD wndStyle = WS_POPUP;
	if(mbWindowed)
	{
		wndStyle = WS_OVERLAPPEDWINDOW;
	}
	wndclass.style         = CS_HREDRAW | CS_VREDRAW;
	wndclass.lpfnWndProc   = WndProc;
	wndclass.cbClsExtra    = 0 ;
	wndclass.cbWndExtra    = 0 ;
	wndclass.hInstance     = mHinstane;
	wndclass.hIcon         = LoadIcon(NULL,IDI_APPLICATION) ;// (wndclass.hInstance, MAKEINTRESOURCE(IDI_DGE) ) ;
	wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
	wndclass.hbrBackground = (HBRUSH) GetStockObject(BLACK_BRUSH) ;
	wndclass.lpszMenuName  = NULL;
	wndclass.lpszClassName = TEXT("D3DCreateWnd"); 
	wndclass.hIconSm       = LoadIcon(NULL,IDI_APPLICATION);//(wndclass.hInstance, MAKEINTRESOURCE(IDI_DGE) ) ;
	// Register the class
	RegisterClassEx(&wndclass);
	// Create a window
	HWND hWnd = CreateWindowEx(
		0,  // Extended style
		wndclass.lpszClassName,
		szTitle,
		wndStyle,       // Window style
		300,              // Horizontal origin  
		200,              // Vertical origin
		mScreenWidth,//GetSystemMetrics(SM_CXSCREEN), // x size
		mScreenHeight,//GetSystemMetrics(SM_CYSCREEN), // y size
		NULL,            // Handle of parent
		NULL,            // Handle to menu
		wndclass.hInstance,//hInstance,       // Application instance
		NULL);           // Additional data
	if (!hWnd)
	{	
		return NULL;
	}
	::ShowWindow(hWnd,SW_SHOW);
	::UpdateWindow(hWnd);
	mHwnd=hWnd;
	return hWnd != NULL; 
}
void winEnvironment::initHinstane()
{	
	mHinstane=GetModuleHandle(NULL);
}

LRESULT CALLBACK winEnvironment::WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	HDC	 hdc;
	RECT * sizingRect;
	PAINTSTRUCT	 ps;
	switch(msg)
	{
	case WM_CREATE:
		AllocConsole();
		SetConsoleTitle("调试信息");
// 		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
// 		STARTUPINFO   si; 
// 		ZeroMemory(&si,   sizeof(si)); 
// 		si.cb   =   sizeof(STARTUPINFO) ;
// 		si.dwX=0;
// 		si.dwY=0;
		

		freopen("CONOUT$","w+t",stdout);
		freopen("CONIN$","r+t",stdin);  
		printf("WM_CREATE\n");
		break;
	case WM_SIZING:
	    	sizingRect=(RECT*)lParam;
			Boy::Environment::instance()->ScreenWidth(sizingRect->right-sizingRect->left);
				Boy::Environment::instance()->ScreenHeight(sizingRect->bottom-sizingRect->top);
			
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_CLOSE:
		Boy::Environment::instance()->stopMainLoop();
		break;
	case WM_MOUSEMOVE:
	case 	WM_LBUTTONDOWN:
	case WM_LBUTTONUP:
	case 	WM_LBUTTONDBLCLK:
	case 	WM_MBUTTONDOWN:
	case 	WM_MBUTTONUP:
	case 	WM_MBUTTONDBLCLK:
	case 	WM_RBUTTONDOWN:
	case 	WM_RBUTTONUP:
	case 	WM_RBUTTONDBLCLK:
	case WM_MOUSEWHEEL:

		Boy::Environment::instance()->getMouse()->MouseCallBack(msg,wParam,lParam);
		break;
	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	return 0;
}
bool winEnvironment::initDirect3D()
{
	//填充D3DPRESENT_PARAMETERS;	
	ZeroMemory(&mD3Dpp,sizeof(mD3Dpp));
	mD3Dpp.BackBufferWidth            = mScreenWidth;
	mD3Dpp.BackBufferHeight           = mScreenHeight;
	mD3Dpp.BackBufferFormat           = D3DFMT_A8R8G8B8;
	mD3Dpp.BackBufferCount            = 1;
	mD3Dpp.MultiSampleType            = D3DMULTISAMPLE_NONE;
	mD3Dpp.MultiSampleQuality         = 0;
	mD3Dpp.SwapEffect                 = D3DSWAPEFFECT_DISCARD; 
	mD3Dpp.hDeviceWindow              = mHwnd;
	mD3Dpp.Windowed                   = mbWindowed;
	mD3Dpp.EnableAutoDepthStencil     = true; 
	mD3Dpp.AutoDepthStencilFormat     = D3DFMT_D24S8;
	mD3Dpp.Flags                      = 0;
	mD3Dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	mD3Dpp.PresentationInterval       = D3DPRESENT_INTERVAL_IMMEDIATE;
	//initialize IDirect3DDevice
	HRESULT hr = 0;
	// Step 1: Create the IDirect3D9 object.
	mpDirect3D = NULL;
	mpDirect3D = Direct3DCreate9(D3D_SDK_VERSION);

	if( mpDirect3D == NULL )
	{
		MessageBox(0, TEXT("Direct3DCreate9() - FAILED"), 0, 0);
		return false;
	}
	// Step 2: Check for hardware vp
	D3DCAPS9 caps;
	mpDirect3D->GetDeviceCaps(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, &caps);

	int vp = 0;
	if( caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT )
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;
	else
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;


	//step 3 create device
	hr = mpDirect3D->CreateDevice(
		D3DADAPTER_DEFAULT, // primary adapter
		D3DDEVTYPE_HAL,         // device type
		mHwnd,               // window associated with device
		vp,                 // vertex processing
		&mD3Dpp,             // present parameters
		&mpDevice);            // return create
	if(FAILED(hr))
	{
		MessageBox(NULL,TEXT("Create Device failed !"),NULL,MB_OK);
		return false;
	}
	mIsD3Dsetup=true;
	return true;
}
void winEnvironment::destroy()
{
		Environment::destroy();
}
void winEnvironment::startMainLoop()
{	mGame->init();
	mGame->load();
	mGame->loadComplete();
	mT0=getTicks();
	mIntervalStartTime = getTicks();
	while (!mShutdownRequested)
	{
		MSG msg;
		msg.message = WM_NULL;
		while(PeekMessage( &msg, NULL, 0U, 0U, PM_REMOVE )!=0)
		{
			// Translate and dispatch the message
			TranslateMessage( &msg );
			DispatchMessage( &msg );
		}
		update();
		preDraw();
		draw();
		endDraw();
		// print some timing stats:
		updateTimingStats();
	}
}
void winEnvironment::stopMainLoop()
{
	mShutdownRequested = true;
}
float winEnvironment::getTime()
{
	return (float(timeGetTime()) - mT0) / 1000.0f;
}
void winEnvironment::update()
{	mD3DFont->clearInfo();
	//处理控制器
	//播放声音
	//计算update
	DWORD t = getTicks();
	float deltaTime=(float)(t-mLastUpdate);
	float minDelTime=2000/mMaxFrameRate;
	mGame->update(deltaTime/1000);
	DWORD t1 = getTicks();
	deltaTime=(float)(t1-mLastUpdate);
	if(deltaTime<minDelTime)
	{
		::Sleep(minDelTime-deltaTime);
	}
	mLastUpdate = t;
	mUpdateCount++;
	mIntervalFrameCount++;	
}
void winEnvironment::preDraw()
{
	mpDevice->Clear(0,NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		0xff000000,1.0f,0);
	mpDevice->BeginScene();
}
void winEnvironment::endDraw()
{
	mpDevice->EndScene();
	mpDevice->Present(0,0,0,0);
}
void winEnvironment::draw(){
	
	mGame->draw();
	printTimingStats();
}
//获取系统当前时间
DWORD winEnvironment::getTicks()
{
	return timeGetTime();
}
void winEnvironment::printTimingStats()
{	
	
	RECT	rect={0,0,mScreenWidth,mScreenHeight};
	TCHAR str[200];
	func::itoa(mFps,str);
	string string1=string(str);
	string title=string(TEXT("\nFPS:"));
	mD3DFont->addInfo(title.append(string1));
	mD3DFont->drawText(&rect,DT_TOP|DT_LEFT,0xcccccc00);
}
void winEnvironment::updateTimingStats()
{
	// if it's time to calculate framerates:
	//计算当前距离 上一次计时器计时所经过的时间
	float dt = getTicks() - mIntervalStartTime;
	if (dt > 1000)
	{
		// calculate fps/ups:
		//距离上次计数，渲染了多少针 除以经过了多少秒 得出每秒 渲染了多少帧
		float fps = (float)mIntervalFrameCount * 1000.0f / dt;		
		// reset counters:
		//计时器复位
		mIntervalStartTime = getTicks();
		//计数器复位
		mIntervalFrameCount = 0;	
		//设置FPS
		mFps=(UINT32)fps; 
	}
}


winD3DFont * winEnvironment::getD3DFont()
{
	return mD3DFont;
}
winGraphics* winEnvironment::getGraphics()
{
	return mGraphics;
}
Mouse* winEnvironment::getMouse()
{
	return mMouse;
}



IDirect3DDevice9* Boy::winEnvironment::getGraphicsDevice()
{
	return mpDevice;
}

long Boy::winEnvironment::ScreenWidth() const
{
	return mScreenWidth;
}

void Boy::winEnvironment::ScreenWidth( long val )
{
	mScreenWidth = val;
}

long Boy::winEnvironment::ScreenHeight() const
{
	return mScreenHeight;
}

void Boy::winEnvironment::ScreenHeight( long val )
{
	mScreenHeight = val;
}
