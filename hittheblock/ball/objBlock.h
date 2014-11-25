#pragma once
#include "obj2dBox.h"

namespace Ball{

	class objBlock:public obj2dBox{
	public:
		objBlock();
		~objBlock();
		objBlock(string src);
		void destruct();

		virtual void endOfCollisionEvt(Segment collisionEdge);
	};


}