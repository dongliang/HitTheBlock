#pragma once
#include "boy/winBase.h"
namespace Ball{

	class Segment{

	public:
		D3DXVECTOR3 StartPoint();
		void StartPoint(D3DXVECTOR3 val);
		D3DXVECTOR3 Endpoint();
		void Endpoint(D3DXVECTOR3 val);
		D3DXVECTOR3 DirectionVector();
		void DirectionVector(D3DXVECTOR3 val);
	protected:
		D3DXVECTOR3 mStartPoint;
		D3DXVECTOR3 mEndpoint;
		D3DXVECTOR3 mDirectionVector;

	};
}
