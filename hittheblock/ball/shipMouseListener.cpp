#include "shipMouseListener.h"
#include "boy/winBase.h"
#include "boy/Vector2.h"
#include "boy/Mouse.h"
#include "demo1.h"
#include "boy/Environment.h"
#include "boy/MouseEvent.h"
using namespace Ball;
using namespace Boy;

void Ball::shipMouseListener::mouseMove( MouseEvent *evt )
{	
float shipWidth=48;
float fieldWidth=195;
float screenWidth=Environment::instance()->ScreenWidth();
float mouseX=evt->X();
cout<<"\n"<<mouseX<<"\n";
D3DXVECTOR3 *shipPos=Demo1::instance()->ShipObj()->getPos();		
//printf("\n%f\n",screenWidth/2);
shipPos->x=(mouseX-screenWidth/2)*(fieldWidth-shipWidth)/screenWidth;
}

Ball::shipMouseListener::shipMouseListener()
{

}

Ball::shipMouseListener::shipMouseListener( EventDispatcher *evtDpr )
{
	init(evtDpr);
}

Ball::shipMouseListener::~shipMouseListener()
{

}

void Ball::shipMouseListener::leftButtonUp( MouseEvent *evt )
{

}

void Ball::shipMouseListener::leftButtonDown( MouseEvent *evt )
{

}

void Ball::shipMouseListener::rightButtonUp( MouseEvent *evt )
{

}

void Ball::shipMouseListener::rightButtonDown( MouseEvent *evt )
{

}

void Ball::shipMouseListener::middleButtonUp( MouseEvent *evt )
{

}

void Ball::shipMouseListener::middleButtonDown( MouseEvent *evt )
{

}



void Ball::shipMouseListener::mouseWheel( MouseEvent *evt )
{
	
}
