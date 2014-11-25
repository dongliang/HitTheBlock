#pragma once
#include "boy/object.h"
#include <vector>
#include "segment.h"

namespace Ball{
   class collisonInfo;
	class obj2dBox:public object{
	public:
		obj2dBox();
		obj2dBox(string src);
		virtual ~obj2dBox();
		void updatePoints();
		void updateSegments();
		void load();
		std::vector<D3DXVECTOR3> getPoints();
		std::vector<Segment> getSegments();
		virtual	D3DXVECTOR3 analysisReflectiveNormal(collisonInfo *ci);
		virtual void endOfCollisionEvt(Segment collisionEdge);

	protected:
		std::vector<D3DXVECTOR3>  mFieldPoints;
		std::vector<Segment> mSegments;
	};
}