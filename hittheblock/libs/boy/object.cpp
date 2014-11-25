#include "object.h"
#include "Environment.h"
#include "Vector3.h"
winGraphicObject *object::getGraphicObj(){
	return  mpGraphicObj;
}
void object::load(){

	mpGraphicObj=Boy::Environment::instance()->getGraphics()->loadObject(mSrc.c_str(),true,mStandTextureName);
	*mBb=mpGraphicObj->getBoundingBox();
	*mBs=mpGraphicObj->getBoundingSphere();
	mIsLoaded=true;
}
void object::init(){	
	mPos=new D3DXVECTOR3(0.0f,0.0f,0.0f);
	mDirection=new D3DXVECTOR3(0.0f,0.0f,0.0f);
	mVelocity=0;
	D3DXMatrixIdentity(&mPosMatrix);
	D3DXMatrixIdentity(&mRotMatrix);
	D3DXMatrixIdentity(&mScalMatrix);
	mStandTextureName="";
	mIsUseStandTexture=false;
	mAngleSpeed=0.0f;
	mScalingX=1;
	mScalingY=1;
	mScalingZ=1;
	mBb=new BoundingBox();
	mBs=new BoundingSphere();
}
void object::init(D3DXVECTOR3 *pos,D3DXVECTOR3 *direction,float velocity){
	mPos=pos;
	mDirection=direction;
	mVelocity=velocity;
	D3DXMatrixIdentity(&mPosMatrix);
	D3DXMatrixIdentity(&mRotMatrix);
	D3DXMatrixIdentity(&mScalMatrix);
	mStandTextureName="";
	mIsUseStandTexture=false;
	mAngleSpeed=0.0f;
	mScalingX=1;
	mScalingY=1;
	mScalingZ=1;
	mBb=new BoundingBox();
	mBs=new BoundingSphere();
	
}

object::object(){
		mIsLoaded=false;
		init();
}
object::object(string src){
	mIsLoaded=false;
	mSrc=src;
	init();
}
object::object(string src,D3DXVECTOR3 *pos,D3DXVECTOR3 *direction,float velocity){
	mIsLoaded=false;
	mSrc=src;
	init(pos,direction,velocity);
}
object::~object(){};
void object::move(float dt)
{
	float ds=mVelocity * dt;
	D3DXVECTOR3 speed=*mDirection * ds;	
	*mPos+=speed;
	D3DXMATRIX moveMatrix;
	D3DXMatrixTranslation(&moveMatrix,mPos->x,mPos->y,mPos->z);
	mPosMatrix=moveMatrix;

}
void object::rot(float dt)
{
	D3DXMATRIX yRot;
	float y = 0.0f;
	y = dt*mAngleSpeed;
	D3DXMatrixRotationY(&yRot, y);
	mRotMatrix*=yRot;
}
void object::scaling(float scalNum)
{	
	mScalingX=scalNum;
	mScalingY=scalNum;
	mScalingZ=scalNum;
	D3DXMatrixScaling(&mScalMatrix,mScalingX,mScalingY,mScalingZ);
}



void object::update( float dt){
	
	rot(dt);
	move(dt);
	mpGraphicObj->setWorldMatrix(mScalMatrix*mRotMatrix* mPosMatrix);
}

void object::setStandTextureName( string str){
	mStandTextureName=str;
	mIsUseStandTexture=true;
}
string object::getStandTextureName(){

	return mStandTextureName;
}

void object::setAngleSpeed( float angle){

	mAngleSpeed=angle;
}
float object::getAngleSpeed(){

	return mAngleSpeed;
}
BoundingSphere object::getBoundingSphere()
{
	BoundingSphere bs;
	
	bs.setRadius(mBs->getRadius()*mScalingX);
	bs.setCenterPos(mBs->getCenterPos()+*mPos);
	return bs;
}

BoundingBox object::getBoundingBox()
{

	BoundingBox bb=*mBb;
	D3DXVECTOR3 bbMin;
	bbMin.x=bb.Min().x*mScalingX;
	bbMin.y=bb.Min().y*mScalingY;
	bbMin.z=bb.Min().z*mScalingZ;
	bb.Min(bbMin);
	D3DXVECTOR3 bbMax;
	bbMax.x=bb.Max().x*mScalingX;
	bbMax.y=bb.Max().y*mScalingY;
	bbMax.z=bb.Max().z*mScalingZ;
	bb.Max(bbMax);
	bb.Min(bb.Min()+*mPos);
	bb.Max(bb.Max()+*mPos);
	return bb;
}

void Boy::object::ScalingY( float val )
{
	mScalingY=val;
	D3DXMatrixScaling(&mScalMatrix,mScalingX,mScalingY,mScalingZ);
}

void Boy::object::ScalingZ( float val )
{
	mScalingZ=val;
	D3DXMatrixScaling(&mScalMatrix,mScalingX,mScalingY,mScalingZ);
}

void Boy::object::ScalingX( float val )
{
	mScalingX=val;
	D3DXMatrixScaling(&mScalMatrix,mScalingX,mScalingY,mScalingZ);
}

void Boy::object::removeGraphicObj()
{
		Boy::Environment::instance()->getGraphics()->removeObj(mpGraphicObj);
}

