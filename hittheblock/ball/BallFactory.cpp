#include "BallFactory.h"
#include "objectManager.h"
#include "demo1.h"
Ball::BallFactory::BallFactory()
{

}

Ball::BallFactory::~BallFactory()
{
	clear();
}

void Ball::BallFactory::createBall(D3DXVECTOR3 *pos,D3DXVECTOR3 *dir)
{
	//

	objectManager * objManager=	Demo1::instance()->ObjectMamager();
	ball * theBall=new ball(TEXT("ball.x"),pos,dir,/*ËÙÂÊ*/120.1f,D3DX_PI/4);
	theBall->scaling(1/1.5f);
	objManager->addObject(theBall);	
	mBallList.insert(mBallList.end(),theBall);
}
void Ball::BallFactory::destroy( Ball::ball * b)
{
	objectManager * objManager=	Demo1::instance()->ObjectMamager();
	SAFE_DELETE(b);
	remove(b);
	objManager->removeObject(b);    
}

void Ball::BallFactory::remove( ball *b )
{
	mBallList.remove(b);
}

void Ball::BallFactory::clear()
{

	list<ball *>::iterator ite=mBallList.begin();	
	while (ite!=mBallList.end())
	{
		destroy(*ite);
	}
}

list<ball *> Ball::BallFactory::getBallsList()
{
	return mBallList;
}
