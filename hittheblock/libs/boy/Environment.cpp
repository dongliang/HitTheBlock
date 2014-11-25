#pragma once
#include "winBase.h"
#include "Environment.h"
#include "WinEnvironment.h"
#include "Game.h"
#include "winGraphicObject.h"
#include "winGraphics.h"
using namespace Boy;
static winEnvironment sEnvObj;
Environment *Environment::gInstance = &sEnvObj;
Environment::Environment()
{
}
Environment::~Environment()
{
}

Environment *Environment::instance()
{
	
	return gInstance;
}
void Environment::init(Game *game, int screenWidth, int screenHeight, bool fullscreen,const TCHAR *windowTitle)
{
	mGame = game;
}
void Environment::destroy()
{
	mGame = NULL;
}


