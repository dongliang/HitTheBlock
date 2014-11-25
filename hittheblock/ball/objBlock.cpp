#include "objBlock.h"
#include "demo1.h"
Ball::objBlock::objBlock()
{

}

Ball::objBlock::objBlock( string src )
{
	mSrc=src;
}

Ball::objBlock::~objBlock()
{

}

void Ball::objBlock::endOfCollisionEvt( Segment collisionEdge )
{
	destruct();
}

void Ball::objBlock::destruct()
{
	Demo1::instance()->BallCollisonController()->removeObsacleBox(this);
	Demo1::instance()->ObjectMamager()->removeObject(this);
}
