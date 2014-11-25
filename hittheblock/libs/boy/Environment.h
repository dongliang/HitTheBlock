#pragma once
#include "winBase.h"


namespace Boy
{
	class Game;
	class winGraphics;
	class winD3DFont;
	class Mouse;
	class Geometry;

	class Environment
	{
	public:

		// static access method:
		static Environment  *instance();
		// init and destroy
		virtual void init(Game *game, int screenWidth, int screenHeight, bool fullscreen,const TCHAR *windowTitle);
		virtual void destroy();
		virtual winGraphics* getGraphics()=0;
		virtual Geometry * getGeometry() =0;
		virtual IDirect3DDevice9* getGraphicsDevice()=0;
		virtual void setGeometry(Geometry * val) =0;
		virtual winD3DFont* getD3DFont()=0;
		virtual  Mouse* getMouse()=0;
		// main loop related:
		virtual void startMainLoop() = 0;
		virtual void stopMainLoop() = 0;
		virtual long ScreenWidth() const=0;
		virtual void ScreenWidth(long val)=0;
		virtual	long ScreenHeight() const=0;
		virtual	void ScreenHeight(long val)=0;
		// timing related:
		virtual float getTime() = 0;
	private:
		static Environment	*gInstance;
	protected:
		Environment();
		virtual ~Environment();
		// the game:
		Game	*mGame;
		winGraphics* mGraphics;
		Geometry * mGeometry;
        
		winD3DFont* mD3DFont;
		Mouse* mMouse;
	
	};
};