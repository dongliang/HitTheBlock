#pragma once
#include "boy\object.h"

namespace Ball{

	class ball: public Boy::object
	{
	public:
		ball(){
			mIsLoaded=false;
		};
		ball(string src);
		ball(string src,D3DXVECTOR3 *pos,D3DXVECTOR3 *direction,float velocity,float angle);
		void  update(float dt);
		
		void load();
		Boy::BoundingSphere Bs() const { return mBs; }
		void Bs(Boy::BoundingSphere val) { mBs = val; }
		float PassRatio() const { return mPassRatio; }
		void PassRatio(float val) { mPassRatio = val; }
		virtual ~ball();	
		protected:
		BoundingSphere mBs;
		float mPassRatio;

	};


}