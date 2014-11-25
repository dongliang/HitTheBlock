#pragma once
#include <d3dx9math.h>

namespace Boy{

	class BoundingSphere{

	public:
		BoundingSphere();
		BoundingSphere(D3DXVECTOR3 *pCenter,float radius);
		~BoundingSphere(){};
		D3DXVECTOR3 getCenterPos();
		void setCenterPos(D3DXVECTOR3 center);
		float getRadius();
		void setRadius(float Radius);

	protected:
		D3DXVECTOR3 mCenter;
		float mRadius;
	};

}