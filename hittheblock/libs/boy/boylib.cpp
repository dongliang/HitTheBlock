#pragma once
#include "boylib.h"
#include <time.h>
#include <float.h>
#include <math.h>

void func::itoa(int i_src,TCHAR * s_to)
{  
	::itoa(i_src,s_to,10);
}
int func::getRand(){

	srand( (unsigned)time( NULL ) );
	return ::rand()%10;
	

}

bool func::floatEquals(float lhs,float rhs)
{
	bool res;
	res= fabs(lhs-rhs) <0.01f ? true : false;
	return res;
}