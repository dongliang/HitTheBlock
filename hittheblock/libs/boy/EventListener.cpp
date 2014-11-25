#include "EventListener.h"
#include "EventDispatcher.h"

void Boy::EventListener::init( EventDispatcher *evtDpr )
{
	evtDpr->addEventListener(this);
}

void Boy::EventListener::handleEvent( Event * evt )
{
	
}

Boy::EventListener::EventListener()
{

}

Boy::EventListener::~EventListener()
{

}
