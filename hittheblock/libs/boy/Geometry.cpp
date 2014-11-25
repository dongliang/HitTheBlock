#include "Geometry.h"
#include<math.h>
bool Boy::Geometry::collisionXZ( D3DXVECTOR3 pos1,D3DXVECTOR3 dir1,D3DXVECTOR3 pos2,D3DXVECTOR3 dir2,D3DXVECTOR3 * intersection )
{
	//v1e = v2e
	//=> v1b + s*v1 = v2b + t*v2
	//=> s*v1 - t*v2 = v2b - v1b
	float s , t,d,d1,d2 ; // �߶η��̵���������;
	//s*dir1.x-t*dir2.x=pos2.x-pos1.x
	//s*dir1.z-t*dir2.z=pos2.z-pos1.z
	d=(dir1.x*(-dir2.z))-((-dir2.x)*dir1.z);
	d1=	((pos2.x-pos1.x)*(-dir2.z))-((-dir2.x)*(pos2.z-pos1.z));
	d2=(dir1.x*(pos2.z-pos1.z))-((pos2.x-pos1.x)*dir1.z);

	//�ж�d�Ƿ�Ϊ��
	if( abs(d) < FLT_EPSILON) // ��������������ƴ���,abs()���������ֵ
	d = FLT_EPSILON ; 

	//�������s,t
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
	����һ��С�򣬾����ƶ��� �Ƿ����߶η�����ײ������ �Ƿ���ײ bool

	������ pos1 ����ԭʼλ��
		   dir1  С���ٶ�����
		   pos2 �߶���ʼ��
		   dir2 �߶���������ʼ�㾭�����������ƶ��õ��ڶ�����
		   intersection ��������� ������ײʱ ���ĵ�λ��
		   radius С��뾶

*/


bool Boy::Geometry::collisionBallWithSegmentXZ( float radius,D3DXVECTOR3 pos1,D3DXVECTOR3 dir1,D3DXVECTOR3 pos2,D3DXVECTOR3 dir2,D3DXVECTOR3 * intersection,D3DXVECTOR3 * normal,float *r_passRatio )
{	
/*
	�裺
		������ײʱ��Բ�ĵ�λ��Ϊ p0
		�߶�����ײ��λq0
		С����ʼλ��Ϊ p
		�߶���ʼλ��Ϊq
		С���ٶ�����Ϊ v
		�߶�����Ϊv2
	��		
	p0=p+s.v  δ֪����p0 , s ��֪����v , p
	q0=q+tv2 δ֪��:q0,t ��֪����q , v2

	������ײʱԲ�ĵ���ײ��ľ�����ڰ뾶 �õ�����������ʽ��RΪ�뾶��n��-n�ֱ����߶ε�������λ�������������෴��
	1. p0-q0=n.R
	2.p0-q0=-n.R
*/
	// 1.��  �ϰ��߶�   ��λ��������
	D3DXVECTOR3 N1,N2,n1,n2;
	N1.x=-dir2.z;
	N1.y=dir2.y;
	N1.z=dir2.x;
	N2.x=dir2.z;
	N2.y=dir2.y;
	N2.z=-dir2.x;
	D3DXVec3Normalize(&n1,&N1);
	D3DXVec3Normalize(&n2,&N2);
	//2. �ⷽ���� �� s1,t1   s2,t2  �ж� ���������Ƿ���Ϸ�Χ��
	float s1,t1,s2,t2;
	//n1 ������ p0-q0=n1.R;
	//  dir1.x * s - dir2.x*t=n1.x*R-pos1.x+pos2.x
	//  dir1.z * s - dir2.z*t=n1.z*R-pos1.z+pos2.z
	cramerXZ(dir1.x,-dir2.x,n1.x*radius-pos1.x+pos2.x,dir1.z,-dir2.z,n1.z*radius-pos1.z+pos2.z,&s1,&t1);
	//n2 ������ p0-q0=n2.R;
	//  dir1.x * s - dir2.x*t=n2.x*R-pos1.x+pos2.x
	//  dir1.z * s - dir2.z*t=n2.z*R-pos1.z+pos2.z
	cramerXZ(dir1.x,-dir2.x,n2.x*radius-pos1.x+pos2.x,dir1.z,-dir2.z,n2.z*radius-pos1.z+pos2.z,&s2,&t2);
	bool b1=false,b2=false;// ���������� �Ƿ�����ײ
	//n1 ����
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
	{	//û����ײ
		return false;
	}
	else if(b1&&b2)
	{
		//������ײ�㣬�Ƚϵó��ȷ�����ײ�ĵ㣬������һ����ײ�ĵ���㡣
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
		MessageBox(0, TEXT("������ײ������ ���룺001"), 0, 0);
		return false;
	}
	
	

	









//3.�Ƚ������ж� �����ƶ��ľ��롣
//4.���ص�һ���ཻʱ��Բ�ĵ�λ�á� 
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
	if( abs(d) < FLT_EPSILON) // ��������������ƴ���,abs()���������ֵ
	d = FLT_EPSILON ; 
	*s = d1/d;
	*t = d2/d;
}
