#include "objBall.h"
#include "boy/Geometry.h"
#include "Boy/Environment.h"

using namespace Ball;

Ball::ball::ball(string src)
{
	mSrc=src;
	mIsLoaded=false;

	mPassRatio=0;

}

Ball::ball::ball(string src,D3DXVECTOR3 *pos,D3DXVECTOR3 *direction,float velocity,float angle)
{
	mSrc=src;
	mIsLoaded=false;
	setDirection(direction);
	setPos(pos);
	setVelocity(velocity);
	setAngleSpeed(angle);

	mPassRatio=0;

}

void Ball::ball::update( float dt )
{	
	rot(dt);
	float surplusTime=dt*(1-mPassRatio);

	if (mPassRatio!=0)
	{
		move(surplusTime);
	}
	else
	{
		move(dt);
	}
	mpGraphicObj->setWorldMatrix(mScalMatrix*mRotMatrix* mPosMatrix);

	mPassRatio=0;
}
Ball::ball::~ball(){


};


void Ball::ball::load()
{  
	object::load();
	BoundingSphere bs=getBoundingSphere();
	mBs=bs;
}


