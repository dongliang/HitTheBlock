#pragma once


namespace Boy
{
	class Graphics;

	/**
	 * game interface used by the framework to drive the main loop
	 */
	class Game
	{
	public:
		Game() {}
		virtual ~Game() {}

		/*
            在init之前调用，用来加载 preInitDraw执行需要的资源
		 * called by the framework before the game's init() method
		 * is called.  this gives the game an opportunity to load the
		 * resources for preInitDraw
		 */
		virtual void preInitLoad() {}

		/*
          让游戏在正式draw调用之前 显示一些东西在屏幕上。
		 * called by the framework before the game's init() method
		 * is called.  this gives the game an opportunity to draw
		 * something to the screen that will be displayed until the
		 * first call to draw(), which will take place after the
		 * init() call.
		 */
		virtual void preInitDraw(Graphics *g) {}

		/*在子系统加载完成， loading调用之前调用。   基础初始化任务，如创建loading屏幕
		 * called by the framework after subsystems are initialized 
		 * but before the initial game loading commences.  this is
		 * where the bare-bones initialization tasks (e.g. creating
		 * the loading screen) should be performed. 
		 */
		virtual void init() {}

		/* 在初始化结束后调用，加载游戏必须的大量的初始化工作。  比如重量级的资源加载， 重量级图形初始化。 运行在一个独立的线程，所以需要很小心的在这执行东西。
		 * called after init().  this is where the game should do 
		 * the more beefy initialization work (e.g. heavy resource 
		 * loading, heavy graphics setup).  this call runs in a 
		 * separate thread, so be careful what you do here.  		 
		 */
		virtual void load() {}

		/*
            1.在主线程中执行
            2.在load方法运行完成时调用。

		 * called after load() finishes running.  this call runs in
		 * the main thread.
		 */
		virtual void loadComplete() {}

		/*
            1.主循环每次迭代都会执行一次update.
            2.在渲染发证之前立即执行
            3.参数 dt  是最后一次updata调用的 总数 计数。
		 * this method is called by the framework once for every
		 * iteration of the game loop, immediately before rendering
		 * takes place.  dt is the amount of time that's passed 
		 * since the last update call.
		 */
		virtual void update(float dt) = 0;

		/* 1.每次迭代都执行一次
           2.实现需要 用Graphics 对象  渲染他们自己 在每一次调用这个方法的时候。
		 * called by the framework once for every iteration of the
		 * main loop.  implementations should draw themselves using 
		 * the Graphics object on every call to this method
		 */
		virtual void draw() = 0;

		/* 当窗口大小改变时执行
		 * called by the framework after window size has changed
		 */
		virtual void windowResized(int oldWidth, int oldHeight, int newWidth, int newHeight) {}

		/* 1.在全屏切换时执行
           2.参数 是是否当前为全屏
		 * called by the framework after a fullscreen toggle takes place
		 */
		virtual void fullscreenToggled(bool isFullscreen) {}

		/*1. 游戏 可以重写 这个方法， 去执行任何关闭游戏时，需要的清理操作
          2.在主循环退出时执行。
		 * the game can override this method to perform any cleanup 
		 * operations it needs to at shutdown.  it will be called
		 * after the main loop exits.
		 */
		virtual void preShutdown() {}

		/* 在一个新鼠标变为可用时调用
		 * called by the framework when a new mouse object becomes available
		 */
		virtual void handleMouseAdded(int mouseId) {}

		/* 当一个现存的鼠标对象变为不可用时调用
		 * called by the framework when an existing mouse object becomes unavailable
		 */
		virtual void handleMouseRemoved(int mouseId) {}

		/* 当手柄加到可用
		 * called by the framework when a new game pad object becomes available
		 */
		virtual void handleGamePadAdded(int gamePadId) {}

		/* 当一个手柄移除时
		 * called by the framework when an existing game pad object becomes unavailable
		 */
		virtual void handleGamePadRemoved(int gamePadId) {}

		/* 当窗口失去焦点时执行
		 * called when the window loses focus
		 */
		virtual void focusLost() {}

		/* 当 窗口获取焦点时执行
		 * called when the window gains focus
		 */
		virtual void focusGained() {}

	};
}
