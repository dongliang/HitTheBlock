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
            ��init֮ǰ���ã��������� preInitDrawִ����Ҫ����Դ
		 * called by the framework before the game's init() method
		 * is called.  this gives the game an opportunity to load the
		 * resources for preInitDraw
		 */
		virtual void preInitLoad() {}

		/*
          ����Ϸ����ʽdraw����֮ǰ ��ʾһЩ��������Ļ�ϡ�
		 * called by the framework before the game's init() method
		 * is called.  this gives the game an opportunity to draw
		 * something to the screen that will be displayed until the
		 * first call to draw(), which will take place after the
		 * init() call.
		 */
		virtual void preInitDraw(Graphics *g) {}

		/*����ϵͳ������ɣ� loading����֮ǰ���á�   ������ʼ�������紴��loading��Ļ
		 * called by the framework after subsystems are initialized 
		 * but before the initial game loading commences.  this is
		 * where the bare-bones initialization tasks (e.g. creating
		 * the loading screen) should be performed. 
		 */
		virtual void init() {}

		/* �ڳ�ʼ����������ã�������Ϸ����Ĵ����ĳ�ʼ��������  ��������������Դ���أ� ������ͼ�γ�ʼ���� ������һ���������̣߳�������Ҫ��С�ĵ�����ִ�ж�����
		 * called after init().  this is where the game should do 
		 * the more beefy initialization work (e.g. heavy resource 
		 * loading, heavy graphics setup).  this call runs in a 
		 * separate thread, so be careful what you do here.  		 
		 */
		virtual void load() {}

		/*
            1.�����߳���ִ��
            2.��load�����������ʱ���á�

		 * called after load() finishes running.  this call runs in
		 * the main thread.
		 */
		virtual void loadComplete() {}

		/*
            1.��ѭ��ÿ�ε�������ִ��һ��update.
            2.����Ⱦ��֤֮ǰ����ִ��
            3.���� dt  �����һ��updata���õ� ���� ������
		 * this method is called by the framework once for every
		 * iteration of the game loop, immediately before rendering
		 * takes place.  dt is the amount of time that's passed 
		 * since the last update call.
		 */
		virtual void update(float dt) = 0;

		/* 1.ÿ�ε�����ִ��һ��
           2.ʵ����Ҫ ��Graphics ����  ��Ⱦ�����Լ� ��ÿһ�ε������������ʱ��
		 * called by the framework once for every iteration of the
		 * main loop.  implementations should draw themselves using 
		 * the Graphics object on every call to this method
		 */
		virtual void draw() = 0;

		/* �����ڴ�С�ı�ʱִ��
		 * called by the framework after window size has changed
		 */
		virtual void windowResized(int oldWidth, int oldHeight, int newWidth, int newHeight) {}

		/* 1.��ȫ���л�ʱִ��
           2.���� ���Ƿ�ǰΪȫ��
		 * called by the framework after a fullscreen toggle takes place
		 */
		virtual void fullscreenToggled(bool isFullscreen) {}

		/*1. ��Ϸ ������д ��������� ȥִ���κιر���Ϸʱ����Ҫ����������
          2.����ѭ���˳�ʱִ�С�
		 * the game can override this method to perform any cleanup 
		 * operations it needs to at shutdown.  it will be called
		 * after the main loop exits.
		 */
		virtual void preShutdown() {}

		/* ��һ��������Ϊ����ʱ����
		 * called by the framework when a new mouse object becomes available
		 */
		virtual void handleMouseAdded(int mouseId) {}

		/* ��һ���ִ���������Ϊ������ʱ����
		 * called by the framework when an existing mouse object becomes unavailable
		 */
		virtual void handleMouseRemoved(int mouseId) {}

		/* ���ֱ��ӵ�����
		 * called by the framework when a new game pad object becomes available
		 */
		virtual void handleGamePadAdded(int gamePadId) {}

		/* ��һ���ֱ��Ƴ�ʱ
		 * called by the framework when an existing game pad object becomes unavailable
		 */
		virtual void handleGamePadRemoved(int gamePadId) {}

		/* ������ʧȥ����ʱִ��
		 * called when the window loses focus
		 */
		virtual void focusLost() {}

		/* �� ���ڻ�ȡ����ʱִ��
		 * called when the window gains focus
		 */
		virtual void focusGained() {}

	};
}