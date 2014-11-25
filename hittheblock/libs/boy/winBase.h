#pragma once

//==================================================================================================================================================
//一般情况下,所有文件都应该包含此头文件
//包含游戏引擎所用的全部类的声明,宏定义,和全局变量的声明

//==================================================================================================================================================
//头文件
#include<d3dx9.h>
#include<d3d9.h>
#include<windows.h>
#include <TCHAR.h>
#include <stdio.h>
#include <vector>
#include <string.h>
#include <xstring>
#include <iostream>
#include <iosfwd>
#include "boylib.h"
#include <iterator> 
#include <float.h>





//库的导入
#ifndef _IMPORT_DIRECTX_
#define _IMPORT_DIRECTX_

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")

#endif

namespace func
{


	//释放COM接口
	template<class COM> 
	inline void Release(COM x)								
	{
		if(x != NULL)
			x->Release();
	}

	//删除指针对象
	template<class POINT>
	inline void Delete(POINT t)									
	{
		if(t != NULL)
			delete t;
	}

};