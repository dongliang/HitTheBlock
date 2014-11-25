#pragma once
#include "winGraphicObject.h"
#include "winGraphics.h"
#include "Vector3.h"
#include "boylib.h"
using namespace std;
using namespace Boy;
namespace Boy
{
	class object {
	public:	
		object();
		virtual ~object();
		object(string src);
		object(string src,D3DXVECTOR3 *pos,D3DXVECTOR3 *direction,float velocity);
		virtual void load();
		void init();
		void init(D3DXVECTOR3 *pos,D3DXVECTOR3 *direction,float velocity);
		void move(float dt);
		void scaling(float scalNum);
		void rot(float dt);
		void virtual update(float dt);
		winGraphicObject *getGraphicObj();
		D3DXVECTOR3 *getPos(){return mPos;};
		D3DXVECTOR3 *getDirection(){return mDirection;};
		float getVelocity(){return mVelocity;};
		void setPos(D3DXVECTOR3 *pos){mPos=pos;};
		void setDirection(D3DXVECTOR3 *direction){mDirection=direction;};
		void setVelocity(float velocity){ mVelocity=velocity;};
		void setAngleSpeed(float angle);
		float getAngleSpeed();
		void setStandTextureName(string str);
		string getStandTextureName();
		BoundingSphere getBoundingSphere();
		BoundingBox getBoundingBox();
		float ScalingY() const { return mScalingY; }
		void ScalingY(float val);
		float ScalingZ() const { return mScalingZ; }
		void ScalingZ(float val) ;
		float ScalingX() const { return mScalingX; }
		void ScalingX(float val);
		void removeGraphicObj();
		

	protected:
	
	string mSrc;	
	protected:
		D3DXVECTOR3 *mPos;
		D3DXVECTOR3 *mDirection;//方向
		float mAngleSpeed;
		D3DXMATRIX mPosMatrix;
		D3DXMATRIX mRotMatrix;
		D3DXMATRIX mScalMatrix;
		float mScalingX;

		float mScalingY;

		float mScalingZ;
	
		string mStandTextureName;
		bool mIsUseStandTexture;
		float mVelocity;//速率
		bool mIsLoaded;
		winGraphicObject *mpGraphicObj;
		BoundingBox * mBb;//原始边界框
		BoundingSphere * mBs;//原始边界球
		
	};

}