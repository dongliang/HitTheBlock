#pragma once
#include "winBase.h"
#include "Environment.h"
#include "winD3DFont.h"
#include "winGraphics.h"
#include "Mouse.h"
#include "Geometry.h"
//#include "winGraphicObject.h"

namespace Boy{

	
	class winGraphicObject;
	class winEnvironment :public Environment
	{
	public:
		winEnvironment();
		virtual ~winEnvironment();
		// implementation of Environment:
		virtual void	init(Game *game, int screenWidth, int screenHeight, bool fullscreen,const TCHAR *windowTitle);
		virtual bool initWindow(const TCHAR* szTitle);
	    virtual bool initDirect3D();

		virtual void destroy();
		// main loop related:
		virtual void startMainLoop();
		virtual void stopMainLoop();
		// timing related:
		//获取游戏开始到现在的时间
		virtual float getTime();
		//获取当前系统时间
		virtual DWORD getTicks();
		//窗口过程函数
		static LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
		//窗口相关
		long ScreenWidth() const;
		void ScreenWidth(long val);
		long ScreenHeight() const;
		void ScreenHeight(long val);

		winD3DFont * getD3DFont();
		winGraphics* getGraphics();
		Geometry * getGeometry()  { return mGeometry; }
		void setGeometry(Geometry * val) { mGeometry = val; }
		Mouse* getMouse();
		 IDirect3DDevice9* getGraphicsDevice();


		
	protected:
		Mouse * mMouse;
		winD3DFont *mD3DFont;
		bool mShutdownRequested;
		virtual void initHinstane();
		//每次循环处理
		void 	update();
		void preDraw();
		void	draw();
		void endDraw();
		//计算定时检测信息，如FPS
		void updateTimingStats();
		void printTimingStats();
	



		//windows 
		HINSTANCE mHinstane;
		long mScreenWidth;

		long mScreenHeight;

		UINT32 mbWindowed;
		HWND mHwnd;
		UINT32 mFps;
		//time 
		float mT0;
		DWORD mLastUpdate;
		UINT32 mUpdateCount;
		UINT32 mMaxFrameRate; //最大帧数
		UINT32 mIntervalFrameCount;
		float mIntervalStartTime;
	// d3d
	IDirect3D9*				mpDirect3D;	
	IDirect3DDevice9*		mpDevice;
	D3DPRESENT_PARAMETERS	mD3Dpp;

	// subsystems:
	winGraphics* mGraphics;
	Geometry * mGeometry;

	bool mIsD3Dsetup;
	};

};




