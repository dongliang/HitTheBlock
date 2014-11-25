#pragma once
#include "obj2dBox.h"
#include "segment.h"
namespace Ball{

	class objShip:public obj2dBox{
	public:
		objShip();
		~objShip();
		objShip(string src);
		void updateSegments();
		std::vector<Segment> getSegments();
		D3DXVECTOR3 analysisReflectiveNormal(collisonInfo *ci);
		void load();

	};

}

