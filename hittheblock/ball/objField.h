#pragma once
#include "obj2dBox.h"
namespace Ball{
	
	class objField:public obj2dBox
	{
	public:
		objField();
		objField(string src);
		virtual ~objField();
		virtual void endOfCollisionEvt(Segment collisionEdge);
	};
}