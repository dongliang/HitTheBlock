#pragma once

//==================================================================================================================================================
//һ�������,�����ļ���Ӧ�ð�����ͷ�ļ�
//������Ϸ�������õ�ȫ���������,�궨��,��ȫ�ֱ���������

//==================================================================================================================================================
//ͷ�ļ�
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





//��ĵ���
#ifndef _IMPORT_DIRECTX_
#define _IMPORT_DIRECTX_

#pragma comment(lib,"d3d9.lib")
#pragma comment(lib,"d3dx9.lib")
#pragma comment(lib,"winmm.lib")

#endif

namespace func
{


	//�ͷ�COM�ӿ�
	template<class COM> 
	inline void Release(COM x)								
	{
		if(x != NULL)
			x->Release();
	}

	//ɾ��ָ�����
	template<class POINT>
	inline void Delete(POINT t)									
	{
		if(t != NULL)
			delete t;
	}

};