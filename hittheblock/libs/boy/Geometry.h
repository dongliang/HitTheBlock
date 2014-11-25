#include "winBase.h"
#include <math.h>

namespace Boy{

	class Geometry
	{
	public:
		bool collisionXZ(D3DXVECTOR3 pos1,D3DXVECTOR3 dir1,D3DXVECTOR3 pos2,D3DXVECTOR3 dir2,D3DXVECTOR3 * intersection);
		bool collisionBallWithSegmentXZ(float radius,D3DXVECTOR3 pos1,D3DXVECTOR3 dir1,D3DXVECTOR3 pos2,D3DXVECTOR3 dir2,D3DXVECTOR3 * intersection,D3DXVECTOR3 * normal,float *r_passRatio);
		void cramerXZ(float a1,float b1,float c1,float a2, float b2, float c2,float *s,float* t);
	protected:

	};
};

