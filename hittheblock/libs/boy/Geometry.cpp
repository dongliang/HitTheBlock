#include "Geometry.h"
#include<math.h>
bool Boy::Geometry::collisionXZ( D3DXVECTOR3 pos1,D3DXVECTOR3 dir1,D3DXVECTOR3 pos2,D3DXVECTOR3 dir2,D3DXVECTOR3 * intersection )
{
	//v1e = v2e
	//=> v1b + s*v1 = v2b + t*v2
	//=> s*v1 - t*v2 = v2b - v1b
	float s , t,d,d1,d2 ; // 线段方程的两个参数;
	//s*dir1.x-t*dir2.x=pos2.x-pos1.x
	//s*dir1.z-t*dir2.z=pos2.z-pos1.z
	d=(dir1.x*(-dir2.z))-((-dir2.x)*dir1.z);
	d1=	((pos2.x-pos1.x)*(-dir2.z))-((-dir2.x)*(pos2.z-pos1.z));
	d2=(dir1.x*(pos2.z-pos1.z))-((pos2.x-pos1.x)*dir1.z);

	//判断d是否为零
	if( abs(d) < FLT_EPSILON) // 如果等于零做近似处理,abs()用于求绝对值
	d = FLT_EPSILON ; 

	//计算参量s,t
	s = d1/d ;
	t = d2/d ;
/*cramerXZ(dir1.x,dir2.x,pos2.x-pos1.x,dir1.z,dir2.z,pos2.z-pos1.z,&s,&t);*/

	if( 0.0f<= s && 1.0f >= s && 0.0f<= t && 1.0f >= t )
	{
		*intersection= pos1 + s*dir1;
		//printf("\s:%f,t:%f\n",s,t);
		return true ;
	}
	else
	{
		return false;
	}
}
/*
	测试一个小球，经过移动， 是否与线段发生碰撞，返回 是否碰撞 bool

	参数： pos1 球心原始位置
		   dir1  小球速度向量
		   pos2 线段起始点
		   dir2 线段向量，起始点经过此向量的移动得到第二个点
		   intersection 输出参数， 返回碰撞时 球心的位置
		   radius 小球半径

*/


bool Boy::Geometry::collisionBallWithSegmentXZ( float radius,D3DXVECTOR3 pos1,D3DXVECTOR3 dir1,D3DXVECTOR3 pos2,D3DXVECTOR3 dir2,D3DXVECTOR3 * intersection,D3DXVECTOR3 * normal,float *r_passRatio )
{	
/*
	设：
		发生碰撞时，圆心的位置为 p0
		线段上碰撞点位q0
		小球起始位置为 p
		线段起始位置为q
		小球速度向量为 v
		线段向量为v2
	则：		
	p0=p+s.v  未知量：p0 , s 已知量：v , p
	q0=q+tv2 未知量:q0,t 已知量：q , v2

	根据碰撞时圆心到碰撞点的距离等于半径 得到如下两个等式，R为半径，n与-n分别是线段的两个单位法向量，方向相反。
	1. p0-q0=n.R
	2.p0-q0=-n.R
*/
	// 1.求  障碍线段   单位法向量。
	D3DXVECTOR3 N1,N2,n1,n2;
	N1.x=-dir2.z;
	N1.y=dir2.y;
	N1.z=dir2.x;
	N2.x=dir2.z;
	N2.y=dir2.y;
	N2.z=-dir2.x;
	D3DXVec3Normalize(&n1,&N1);
	D3DXVec3Normalize(&n2,&N2);
	//2. 解方程组 求 s1,t1   s2,t2  判断 两组数据是否符合范围。
	float s1,t1,s2,t2;
	//n1 方程组 p0-q0=n1.R;
	//  dir1.x * s - dir2.x*t=n1.x*R-pos1.x+pos2.x
	//  dir1.z * s - dir2.z*t=n1.z*R-pos1.z+pos2.z
	cramerXZ(dir1.x,-dir2.x,n1.x*radius-pos1.x+pos2.x,dir1.z,-dir2.z,n1.z*radius-pos1.z+pos2.z,&s1,&t1);
	//n2 方程组 p0-q0=n2.R;
	//  dir1.x * s - dir2.x*t=n2.x*R-pos1.x+pos2.x
	//  dir1.z * s - dir2.z*t=n2.z*R-pos1.z+pos2.z
	cramerXZ(dir1.x,-dir2.x,n2.x*radius-pos1.x+pos2.x,dir1.z,-dir2.z,n2.z*radius-pos1.z+pos2.z,&s2,&t2);
	bool b1=false,b2=false;// 两个方向上 是否发生碰撞
	//n1 方向
	if( 0.0f<= s1 && 1.0f >= s1 && 0.0f<= t1 && 1.0f >= t1 )
	{
		b1 =true;
		*r_passRatio= s1;
		*normal=n1;
	}
	if( 0.0f<= s2 && 1.0f >= s2 && 0.0f<= t2 && 1.0f >= t2 )
	{
		b2 =true;
		*r_passRatio= s2;
		*normal=n2;
	}
	
	if(!(b1||b2))
	{	//没有碰撞
		return false;
	}
	else if(b1&&b2)
	{
		//两个碰撞点，比较得出先发生碰撞的点，并按第一个碰撞的点计算。
		if (s1<=s2)
		{
			*intersection=pos1 + s1*dir1;
			*normal=n1;
			*r_passRatio=s1;
			return true;
		}
		else
		{
			*intersection=pos1 + s2*dir1;
			*normal=n2;
			*r_passRatio=s2;
			return true;
		}
		
	}
	else if(b1)
	{
		*intersection=pos1 + s1*dir1;
		return true;
	}
	else if (b2)
	{
		*intersection=pos1 + s2*dir1;
		return true;
	}
	else
	{
		MessageBox(0, TEXT("错误：碰撞检测错误 代码：001"), 0, 0);
		return false;
	}
	
	

	









//3.比较两次判断 球心移动的距离。
//4.返回第一次相交时，圆心的位置。 
}

void Boy::Geometry::cramerXZ( float a1,float b1,float c1,float a2, float b2, float c2,float *s,float* t )
{
	//s*dir1.x-t*dir2.x=pos2.x-pos1.x
	//s*dir1.z-t*dir2.z=pos2.z-pos1.z
	/*
	  d=	a1 b1
		a2 b2
	 d1= c1 b1
		c2 b2
	d2= a1 c1
		a2 c2

	*/
	float d,d1,d2;
	d= a1*b2-b1*a2;
	d1=c1*b2-b1*c2;
	d2=a1*c2-c1*a2;
	if( abs(d) < FLT_EPSILON) // 如果等于零做近似处理,abs()用于求绝对值
	d = FLT_EPSILON ; 
	*s = d1/d;
	*t = d2/d;
}
