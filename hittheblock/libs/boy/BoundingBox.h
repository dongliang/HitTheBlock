#pragma once
#include <d3dx9math.h>

namespace Boy{

	class BoundingBox{

	public:
		BoundingBox();
		~BoundingBox();
		D3DXVECTOR3 Min() const { return mMin; }
		void Min(D3DXVECTOR3 val) { mMin = val; }
		D3DXVECTOR3 Max() const { return mMax; }
		void Max(D3DXVECTOR3 val) { mMax = val; }
	protected:
		D3DXVECTOR3 mMin;
		D3DXVECTOR3 mMax;
	};

}