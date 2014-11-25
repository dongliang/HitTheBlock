#include "objectManager.h"
#include <algorithm>
Ball::objectManager::objectManager():mBallFactory(0)
{
	mBallFactory=new BallFactory();
}

Ball::objectManager::~objectManager()
{
	SAFE_DELETE(mBallFactory);
}

void Ball::objectManager::addObject( object *obj )
{
	mObjectList.push_back(obj);
}


void Ball::objectManager::removeObject( object *obj )
{
	vector<object *>::iterator ite=mObjectList.begin();	
	while (ite!=mObjectList.end())
	{
		ite=find(ite,mObjectList.end(),obj);
		if (ite!=mObjectList.end())
		{  
			(**ite).removeGraphicObj();
	
			ite=mObjectList.erase(ite);
		}
	}
}

void Ball::objectManager::load()
{
	for (int i=0;i<mObjectList.size();i++)
	{
		mObjectList[i]->load();
	}
}

void Ball::objectManager::update( float dt )
{
	for (int i=0;i<mObjectList.size();i++)
	{
		mObjectList[i]->update(dt);	
	}		
}


void Ball::objectManager::createBall( D3DXVECTOR3 *pos,D3DXVECTOR3 *dir )
{
	mBallFactory->createBall(pos,dir);
}

list<Ball::ball *> Ball::objectManager::getBallsList()
{
	return mBallFactory->getBallsList();
}
