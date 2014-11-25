#pragma once
#include "boy\object.h"
#include "BallFactory.h"
#include <vector>
#include <list>

namespace Ball{

	class objectManager
	{

	public:
		objectManager();
		~objectManager();
		void addObject(object *obj);
		void removeObject(object *obj);
		void createBall(D3DXVECTOR3 *pos,D3DXVECTOR3 *dir);
		list<ball *> getBallsList();


		
		void load();
		void update(float dt);
	protected:
		vector<object *> mObjectList;
		BallFactory *mBallFactory;



		




	};


}