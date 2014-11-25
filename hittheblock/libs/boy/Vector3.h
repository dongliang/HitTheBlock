#pragma once
#include <math.h>

namespace Boy
{
	class Vector3{
	public:  
		Vector3(){
			this->x=0;
			this->y=0;
			this->z=0;
		}
		Vector3(float fx, float fy, float fz):x(fx), y(fy), z(fz) 
		{  

		}     
		~Vector3(){}
		// Subtract  
		Vector3 operator - (const Vector3& v) const 
		{       
			return Vector3(x - v.x, y - v.y, z - v.z) ;   
		}     
		// add  
		Vector3 operator + (const Vector3& v) const 
		{       
			return Vector3(x + v.x, y + v.y, z + v.z) ;   
		}     
		Vector3 operator*(float t) const { return Vector3(t*x, t*y,t*z); }
		Vector3 operator/(float t) const { return Vector3(x/t, y/t,t*z); }
		Vector3 operator-() const { return Vector3(-x, -y,-z); }
		void operator+=(const Vector3 &v) { x+=v.x; y+=v.y; z+=v.z;}
		void operator-=(const Vector3 &v) { x-=v.x; y-=v.y;z-=v.z; }
		void operator*=(float t) { x*=t; y*=t; z*=t;}
		void operator/=(float t) { x/=t; y/=t;z/=t; }
		void operator=(const Vector3 &v) { x=v.x; y=v.y;z=v.z; }
		bool operator==(const Vector3 &v) { return x==v.x && y==v.y&&z==v.z; }
		bool operator!=(const Vector3 &v) { return x!=v.x || y!=v.y||z!=v.z; }

		// Dot product   
		float Dot(const Vector3& v) const    {
			return x * v.x + y * v.y + z * v.z ;
		}        // Cross product    
		Vector3 Cross(const Vector3& v) const    {
			return Vector3(y * v.z - z * v.y, z * v.x - x * v.z,x * v.y - y * v.x ) ;
		}
	public:   
		float x, y, z ;

	};
}