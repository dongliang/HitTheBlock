#include "ballCollisonController.h"
#include "obj2dBox.h"
#include "boy/Geometry.h"
#include "Boy/Environment.h"
#include "demo1.h"
#include "collisonInfo.h"
#include "boy/boylib.h"
#include <algorithm>
using namespace Ball;

void ballCollisonController::collision( float dt )
{
		list<ball *> ballList=Demo1::instance()->ObjectMamager()->getBallsList();

		list<ball *>::iterator ite_ballList =ballList.begin();

		while(ite_ballList!=ballList.end())
		{

			vector<collisonInfo> ciList;
			vector <collisonInfo> ciList_MinPassRatio;
			for (int i=0;i<(int)mObstaclesBoxes.size();i++)
			{	
				obj2dBox * tempBox=mObstaclesBoxes[i];
				std::vector<Segment> boxSegmentsList;	
				boxSegmentsList=tempBox->getSegments();
				INT32 segmentNum=(INT32)boxSegmentsList.size();
				for (INT32 i=0;i<segmentNum;i++)
				{		
					collisonInfo ci;
					ci.Ball(*ite_ballList);
					ci.CollisonObj(tempBox);
					bool isCollison=ballCollisionTest(boxSegmentsList[i],dt,&ci);
					if (isCollison)
					{
						ciList.push_back(ci);
					}
				}
			}

			if(ciList.size()<=0)
			{
				return;
			}
			if (ciList[0].PassRatio()<0.01F)
			{
				return;
			}
			ciList_MinPassRatio=getMinCollisonInfoList(ciList);
			collisionResponse(ciList_MinPassRatio,dt);
			fireEndOfCollisionEvt(ciList);

			ite_ballList++;

		}

	
	
	

}


std::vector<collisonInfo> Ball::ballCollisonController::getMinCollisonInfoList( vector<collisonInfo> ciList )
{
		collisonInfo ci_MinPassRatio;
		ci_MinPassRatio.PassRatio(1.1f);
		std::vector<collisonInfo> ciList_MinPassRatio;
		ciList_MinPassRatio.push_back(ci_MinPassRatio);

		for (	int i=0;i<(int)ciList.size();i++)
		{			
			if (func::floatEquals(ciList_MinPassRatio[0].PassRatio(),ciList[i].PassRatio()))
			{ 
				ciList_MinPassRatio.push_back(ciList[i]);
			}
			else
			{
				if (ciList_MinPassRatio[0].PassRatio()>ciList[i].PassRatio())
				{						
					ciList_MinPassRatio.clear();
					ciList_MinPassRatio.push_back(ciList[i]);
				}
			}			
		}
		return ciList_MinPassRatio;
	
}

bool Ball::ballCollisonController::ballCollisionTest( Segment segment,float dt ,collisonInfo *ci )
{	
	Ball:ball * ballItem=ci->Ball();
	float ds=ballItem->getVelocity() * dt;
	D3DXVECTOR3 speed= *ballItem->getDirection() * ds;
	float r=ballItem->getBoundingSphere().getRadius();
	D3DXVECTOR3 r_n1;
	D3DXVECTOR3  r_intersection;
	float r_passTime=dt;
	float r_passRatio=1;
	bool isCollision=Boy::Environment::instance()->getGeometry()->collisionBallWithSegmentXZ(r,*ballItem->getPos(),speed,segment.StartPoint(),segment.DirectionVector(),&r_intersection,&r_n1,&r_passRatio);
	if (isCollision)
	{

		ci->Intersection(r_intersection);
		ci->Normal(r_n1);
		ci->PassRatio(r_passRatio);
		ci->CollisonSegment(segment);
		ci->Incident(*ballItem->getDirection());
		return true;
	}
	else
	{
		return false;
	}
}

D3DXVECTOR3 Ball::ballCollisonController::analysisReflectiveVector( std::vector<collisonInfo> ciList )
{
		Ball:ball * ballItem=ciList[0].Ball();
	//开始->计算反射 
	D3DXVECTOR3 sumNormal;
	sumNormal.x=0.0f;
	sumNormal.y=0.0f;
	sumNormal.z=0.0f;
	D3DXVECTOR3 incident=*ballItem->getDirection();
	D3DXVECTOR3 negative=-*ballItem->getDirection();
	INT32 ciListNum=(INT32)ciList.size();
	for (INT32 i=0;i<ciListNum;i++)
	{	
		collisonInfo tempCi=ciList[i];
		sumNormal=sumNormal+tempCi.CollisonObj()->analysisReflectiveNormal(&tempCi);
	}
	D3DXVECTOR3 pnn;
	D3DXVec3Normalize(&pnn,&sumNormal);
	sumNormal=pnn;

	D3DXVECTOR3 n= D3DXVec3Dot(&negative,&sumNormal)*sumNormal;
	D3DXVECTOR3 F=incident+2*n;
	return F;
	
	//结束->计算反射
}

void Ball::ballCollisonController::fireEndOfCollisionEvt( vector<collisonInfo> ciList )
{
		for (int i=0;i<(int)ciList.size();i++)
		{
			collisonInfo currentCollisonInfo=ciList[i];
			currentCollisonInfo.CollisonObj()->endOfCollisionEvt(currentCollisonInfo.CollisonSegment());
		}
}

void Ball::ballCollisonController::removeObsacleBox( obj2dBox * box )
{
		vector<obj2dBox *>::iterator ite=mObstaclesBoxes.begin();
		
		while(ite!=mObstaclesBoxes.end())
		{
			ite=find(ite,mObstaclesBoxes.end(),box);
			if (ite!=mObstaclesBoxes.end())
			{
				ite=mObstaclesBoxes.erase(ite);
			}
		}		
}

void ballCollisonController::addObstaclesBox( obj2dBox * box )
{
	mObstaclesBoxes.push_back(box);
}

ballCollisonController::ballCollisonController()
{

}

ballCollisonController::~ballCollisonController()
{

}



void ballCollisonController::collisionResponse( std::vector<collisonInfo> ciList,float dt )
{		
	Ball:ball * ballItem=ciList[0].Ball();

	float passRatio=ciList[0].PassRatio();
	ballItem->PassRatio(passRatio);
	*ballItem->getPos()=ciList[0].Intersection();
	float st;
	st=dt*(1.0f-ciList[0].PassRatio());
	D3DXVECTOR3 F=analysisReflectiveVector(ciList);
	*ballItem->getDirection()=F;	
	//collision(st);
}

