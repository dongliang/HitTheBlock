#pragma once
#include "segment.h"
#include "obj2dBox.h"
#include "objBall.h"
namespace Ball{
	class collisonInfo	
	{
		public:

		D3DXVECTOR3 Normal() const;
		void Normal(D3DXVECTOR3 val);

		D3DXVECTOR3 Incident() const;
		void Incident(D3DXVECTOR3 val);

		D3DXVECTOR3 Intersection() const;
		void Intersection(D3DXVECTOR3 val);

		float PassRatio() const;
		void PassRatio(float val);

		Segment CollisonSegment() const;
		void CollisonSegment(Segment val);


		ball * Ball() const;
		void Ball(ball * val);

		obj2dBox* CollisonObj() const;
		void CollisonObj(obj2dBox* val);

		protected:
		D3DXVECTOR3 mNormal;
		D3DXVECTOR3 mIntersection;
		float mPassRatio;
		Segment mCollisonSegment;

		D3DXVECTOR3 mIncident;
		obj2dBox  *mCollisonObj;
		ball * mBall;

	};
}