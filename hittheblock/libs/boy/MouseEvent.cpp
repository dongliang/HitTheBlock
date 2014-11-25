#include "MouseEvent.h"

Boy::MouseEvent::MouseEvent()
{
	init();
}


Boy::MouseEvent::MouseEvent( int type, EventDispatcher *target )
{
   init();
   mType=type;
   mTarget=target;
}

void Boy::MouseEvent::init()
{	
	mType=TYPE_Undefined;
	mTarget=0;
	mRightButtonDown=false;
	mAltKey=false;
	mCtrlKey=false;
	mDelta=0;
	mLeftButtonDown=false;
	mMiddleButtonDown=false;
	mShiftKey=false;
	mX=0;
	mY=0;
}


Boy::MouseEvent::~MouseEvent()
{

}



bool Boy::MouseEvent::MiddleButtonDown() const
{
	return mMiddleButtonDown;
}

void Boy::MouseEvent::MiddleButtonDown( bool val )
{
	mMiddleButtonDown = val;
}

float Boy::MouseEvent::X() const
{
	return mX;
}

void Boy::MouseEvent::X( float val )
{
	mX = val;
}

float Boy::MouseEvent::Y() const
{
	return mY;
}

void Boy::MouseEvent::Y( float val )
{
	mY = val;
}

bool Boy::MouseEvent::CtrlKey() const
{
	return mCtrlKey;
}

void Boy::MouseEvent::CtrlKey( bool val )
{
	mCtrlKey = val;
}

int Boy::MouseEvent::Delta() const
{
	return mDelta;
}

void Boy::MouseEvent::Delta( int val )
{
	mDelta = val;
}

bool Boy::MouseEvent::ShiftKey() const
{
	return mShiftKey;
}

void Boy::MouseEvent::ShiftKey( bool val )
{
	mShiftKey = val;
}

bool Boy::MouseEvent::AltKey() const
{
	return mAltKey;
}

void Boy::MouseEvent::AltKey( bool val )
{
	mAltKey = val;
}

bool Boy::MouseEvent::LeftButtonDown() const
{
	return mLeftButtonDown;
}

void Boy::MouseEvent::LeftButtonDown( bool val )
{
	mLeftButtonDown = val;
}

bool Boy::MouseEvent::RightButtonDown() const
{
	return mRightButtonDown;
}

void Boy::MouseEvent::RightButtonDown( bool val )
{
	mRightButtonDown = val;
}
