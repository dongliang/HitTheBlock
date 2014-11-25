#include "Event.h"
#include "EventDispatcher.h"
#include <algorithm>

void Boy::EventDispatcher::addEventListener( EventListener *listener )
{
	mListeners.push_back(listener);
}

void Boy::EventDispatcher::removeEventListener( EventListener * listener )
{
	 mListeners.erase(remove(mListeners.begin(),mListeners.end(),listener),mListeners.end()) ;
}

bool Boy::EventDispatcher::hasEventListener( EventListener *listener )
{		std::vector<EventListener *>::iterator ite;
		ite=find(mListeners.begin(),mListeners.end(),listener);
		if (ite!=mListeners.end())
		{
			return true;
		}
		else
		{
			return false;
		}
}

void Boy::EventDispatcher::setChanged()
{
		mChanged=true;
}

void Boy::EventDispatcher::dispatchEvent( Event *evt )
{
	if (!mChanged)
	return;

	for(int i=0;i<(int)mListeners.size();i++)
	{
		mListeners[i]->handleEvent(evt);
	}
	mChanged=false;
}

