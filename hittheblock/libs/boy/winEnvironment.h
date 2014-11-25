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
		//��ȡ��Ϸ��ʼ�����ڵ�ʱ��
		virtual float getTime();
		//��ȡ��ǰϵͳʱ��
		virtual DWORD getTicks();
		//���ڹ��̺���
		static LRESULT CALLBACK WndProc(HWND hWnd,UINT msg,WPARAM wParam,LPARAM lParam);
		//�������
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
		//ÿ��ѭ������
		void 	update();
		void preDraw();
		void	draw();
		void endDraw();
		//���㶨ʱ�����Ϣ����FPS
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
		UINT32 mMaxFrameRate; //���֡��
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




