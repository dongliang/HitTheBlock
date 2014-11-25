#pragma once
#include <windows.h>
#include <stdlib.h>
#include "boy/Environment.h"
#include "demo1.h"
int WINAPI	WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd )
{
	// initialize the platform:
	Boy::Environment::instance()->init(
		Demo1::instance(),
		1024, // width
		768, // height
		true, // fullscreen
		TEXT("demo1") // window title
		); 

	// start the main loop
	Boy::Environment::instance()->startMainLoop();

	// destroy the game:
	Demo1::destroy();

	// destroy the environment:
	Boy::Environment::instance()->destroy();

	return 0;
}