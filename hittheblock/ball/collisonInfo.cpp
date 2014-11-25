#include "collisonInfo.h"
D3DXVECTOR3 Ball::collisonInfo::Normal() const
{
	return mNormal;
}

void Ball::collisonInfo::Normal( D3DXVECTOR3 val )
{
	mNormal = val;
}

D3DXVECTOR3 Ball::collisonInfo::Intersection() const
{
	return mIntersection;
}

void Ball::collisonInfo::Intersection( D3DXVECTOR3 val )
{
	mIntersection = val;
}

float Ball::collisonInfo::PassRatio() const
{
	return mPassRatio;
}

void Ball::collisonInfo::PassRatio( float val )
{
	mPassRatio = val;
}



D3DXVECTOR3 Ball::collisonInfo::Incident() const
{
	return mIncident;
}

void Ball::collisonInfo::Incident( D3DXVECTOR3 val )
{
	mIncident = val;
}

Ball::obj2dBox* Ball::collisonInfo::CollisonObj() const
{
	return mCollisonObj;
}

void Ball::collisonInfo::CollisonObj( Ball::obj2dBox* val )
{
	mCollisonObj = val;
}

Ball::ball * Ball::collisonInfo::Ball() const
{
	return mBall;
}

void Ball::collisonInfo::Ball( Ball::ball * val )
{
	mBall = val;
}

Ball::Segment Ball::collisonInfo::CollisonSegment() const
{
	return mCollisonSegment;
}

void Ball::collisonInfo::CollisonSegment( Segment val )
{
	mCollisonSegment = val;
}
