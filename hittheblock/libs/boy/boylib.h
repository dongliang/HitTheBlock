#pragma once
#include <stdlib.h>
#include <TCHAR.h>
namespace func
{

	void itoa(int i_src,TCHAR * s_to);
	bool floatEquals(float lhs,float rhs);
	int getRand();


#define SAFE_DELETE(point){		if (point)delete point; point = 0;}	
}