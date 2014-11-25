#pragma once
#include "objBall.h"
#include <vector>
#include "segment.h"
using namespace std;
namespace Ball{
	class obj2dBox;
	class collisonInfo;
	class ballCollisonController
	{
	public:
		ballCollisonController();
		~ballCollisonController();
		void collision(float dt);
		void collisionResponse(std::vector<collisonInfo> ciList,float dt);
		void addObstaclesBox(obj2dBox * box);
		void removeObsacleBox(obj2dBox * box);
		D3DXVECTOR3 analysisReflectiveVector(std::vector<collisonInfo> ciList);

		void fireEndOfCollisionEvt(vector<collisonInfo> ciList);
	protected:

		
		vector<obj2dBox *> mObstaclesBoxes;
		
		bool ballCollisionTest(Segment segment,float dt ,collisonInfo *ci);
		std::vector<collisonInfo> getMinCollisonInfoList(vector<collisonInfo> ciList);
	};
}