#include "objShip.h"
#include "collisonInfo.h"

Ball::objShip::objShip()
{

}

Ball::objShip::objShip( string src )
{
	mSrc=src;
}

Ball::objShip::~objShip()
{

}

void Ball::objShip::updateSegments()
{
	updatePoints();

	//������ȡ�����߶�
	INT32 maxSegmentNum=1;
	INT32 pointsNum=(INT32)mFieldPoints.size();
	mSegments.clear();
	for (INT32 i=0;i<maxSegmentNum+1;i++)
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

std::vector<Ball::Segment> Ball::objShip::getSegments()
{
		updateSegments();
		return mSegments;
}

void Ball::objShip::load()
{
	object::load();
	updateSegments();
}

D3DXVECTOR3 Ball::objShip::analysisReflectiveNormal( collisonInfo *ci )
{
	//����ļ����е����⣬��Ϊ��Ҫ�����вٿ�С�����������
	//���ԣ��������ײ ������һ���н��ڣ�������ƽ�����䣬�����ǰ��վ��淴�䡣
	//����
			//printf("aa");
	D3DXVECTOR3 incident=ci->Incident();
	D3DXVECTOR3 negative=-incident;
	D3DXVECTOR3 F1;//�������
	Segment tempSegment=ci->CollisonSegment();
	D3DXVECTOR3 segmentN2=-ci->Normal();
	D3DXVECTOR3 centerPoint;
	centerPoint=tempSegment.StartPoint()+tempSegment.DirectionVector()/2+3*segmentN2;
	F1= ci->Intersection()-centerPoint;
	D3DXVECTOR3 NF1;//��׼���������
	D3DXVec3Normalize(&NF1,&F1);
	D3DXVECTOR3 N1;//����
	D3DXVECTOR3 pnn1;//��׼��ķ���
	N1=negative+(incident+NF1)/2;
	D3DXVec3Normalize(&pnn1,&N1);
	
	return pnn1;
}
