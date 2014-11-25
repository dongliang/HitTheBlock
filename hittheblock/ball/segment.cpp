#include "segment.h"

D3DXVECTOR3 Ball::Segment::StartPoint() 
{
	return mStartPoint;
}

void Ball::Segment::StartPoint( D3DXVECTOR3 val )
{
	mStartPoint = val;
}

D3DXVECTOR3 Ball::Segment::Endpoint() 
{
	return mEndpoint;
}

void Ball::Segment::Endpoint( D3DXVECTOR3 val )
{
	mEndpoint = val;
}

D3DXVECTOR3 Ball::Segment::DirectionVector() 
{
	return mDirectionVector;
}

void Ball::Segment::DirectionVector( D3DXVECTOR3 val )
{
	mDirectionVector = val;
}
