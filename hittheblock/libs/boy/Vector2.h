#pragma once
#include <math.h>
namespace Boy
{
	class Vector2
	{
	public:

		Vector2(float x=0, float y=0) { this->x = x; this->y = y; }
		Vector2(const Vector2 &vec) { x=vec.x; y=vec.y; }
		virtual ~Vector2() {}

		Vector2 operator+(const Vector2 &v) const { return Vector2(x+v.x, y+v.y); }
		Vector2 operator-(const Vector2 &v) const { return Vector2(x-v.x, y-v.y); }
		Vector2 operator-() const { return Vector2(-x, -y); }
		Vector2 operator*(float t) const { return Vector2(t*x, t*y); }
		Vector2 operator/(float t) const { return Vector2(x/t, y/t); }
		void operator+=(const Vector2 &v) { x+=v.x; y+=v.y; }
		void operator-=(const Vector2 &v) { x-=v.x; y-=v.y; }
		void operator*=(float t) { x*=t; y*=t; }
		void operator/=(float t) { x/=t; y/=t; }

		void operator=(const Vector2 &v) { x=v.x; y=v.y; }

		bool operator==(const Vector2 &v) { return x==v.x && y==v.y; }
		bool operator!=(const Vector2 &v) { return x!=v.x || y!=v.y; }

		float dot(const Vector2 &v) const { return x*v.x + y*v.y; }	

	public:

		float x;
		float y;
	};
}