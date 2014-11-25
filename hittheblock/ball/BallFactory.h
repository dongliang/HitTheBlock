#pragma once
#include <list>
#include "objBall.h"
using namespace std;
namespace Ball{
	class BallFactory
	{
		public:
			BallFactory();
			~BallFactory();
			void createBall(D3DXVECTOR3 *pos,D3DXVECTOR3 *dir);
			list<ball *> getBallsList();
			void destroy(ball * b);
			void clear();

		protected:
			list<ball *> mBallList;
			void remove (ball *b);
	};
}


