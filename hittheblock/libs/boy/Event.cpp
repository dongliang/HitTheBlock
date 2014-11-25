#include "Event.h"
#include "EventDispatcher.h"

Boy::Event::Event()
{

}

Boy::Event::~Event()
{

}



Boy::EventDispatcher * Boy::Event::Target() const
{
	return mTarget;
}

void Boy::Event::Target( EventDispatcher * val )
{
	mTarget = val;
}

int Boy::Event::Type() const
{
	return mType;
}

void Boy::Event::Type( int val )
{
	mType = val;
}
