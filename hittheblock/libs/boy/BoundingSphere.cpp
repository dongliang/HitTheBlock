#include "BoundingSphere.h"
using namespace Boy;

BoundingSphere::BoundingSphere()
{
	mCenter.x=0;
	mCenter.y=0;
	mCenter.z=0;
	mRadius=0;
}
BoundingSphere::BoundingSphere(D3DXVECTOR3 *pCenter,float radius)
{
	mCenter=*pCenter;
	mRadius=radius;
}

D3DXVECTOR3 BoundingSphere::getCenterPos(){
	return mCenter;
}
void BoundingSphere::setCenterPos(D3DXVECTOR3 center){
	mCenter=center;
}
float BoundingSphere::getRadius(){
	return mRadius;
}
void BoundingSphere::setRadius(float radius)
{
	mRadius=radius;
}