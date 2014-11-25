#include "obj2dBox.h"
#include "collisonInfo.h"
using namespace Ball;
std::vector<D3DXVECTOR3> obj2dBox::getPoints()
{	
	updatePoints();
	return mFieldPoints;
}

std::vector<Segment> Ball::obj2dBox::getSegments()
{
		updateSegments();
		return mSegments;
}

void obj2dBox::updatePoints()
{
	BoundingBox bb=getBoundingBox();
	D3DXVECTOR3 point_left_far=D3DXVECTOR3(bb.Min().x,bb.Min().y ,bb.Max().z );	//左上
	D3DXVECTOR3 point_left_near=bb.Min();		//左下
	D3DXVECTOR3 point_right_far=bb.Max();	//右上
	D3DXVECTOR3 point_right_near=D3DXVECTOR3(bb.Max().x,bb.Max().y ,bb.Min().z );	//右下

	mFieldPoints.clear();
	mFieldPoints.push_back(point_left_far);
	mFieldPoints.push_back(point_right_far);
	mFieldPoints.push_back(point_right_near);
	mFieldPoints.push_back(point_left_near);
}

void obj2dBox::load()
{
	object::load();
	updateSegments();
}

obj2dBox::obj2dBox( string src )
{
	mSrc=src;
}

obj2dBox::~obj2dBox()
{
	
}


Ball::obj2dBox::obj2dBox()
{

}

void Ball::obj2dBox::updateSegments()
{
	updatePoints();
	INT32 pointsNum=(INT32)mFieldPoints.size();
	mSegments.clear();
	for (INT32 i=0;i<pointsNum;i++)
	{
		D3DXVECTOR3 startingPoint=mFieldPoints[i];
		D3DXVECTOR3 endPoint;
		
		if ((i==pointsNum-1))
		{
			endPoint=mFieldPoints[0];
		}
		else
		{
			endPoint=mFieldPoints[i+1];
		}
		startingPoint.y=0.0f;
		endPoint.y=0.0f;
		D3DXVECTOR3 directionVector=endPoint-startingPoint;
		
		Segment s1;
		s1.StartPoint(startingPoint);
		s1.Endpoint(endPoint);
		s1.DirectionVector(directionVector);


		mSegments.push_back(s1);
	}
}

D3DXVECTOR3 Ball::obj2dBox::analysisReflectiveNormal(collisonInfo *ci)
{

		return ci->Normal();
		
}

void Ball::obj2dBox::endOfCollisionEvt( Segment collisionEdge )
{
	cout<<"test";
}
