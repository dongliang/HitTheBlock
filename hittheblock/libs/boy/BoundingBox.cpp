#include "BoundingBox.h"
using namespace Boy;

Boy::BoundingBox::BoundingBox()
{
	mMax.x=-FLT_MAX;
	mMax.y=-FLT_MAX;
	mMax.z=-FLT_MAX;
	mMin.x=FLT_MAX;
	mMin.y=FLT_MAX;
	mMin.z=FLT_MAX;
}
Boy::BoundingBox::~BoundingBox()
{
	
}