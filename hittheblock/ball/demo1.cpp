#include "Demo1.h"
#include "boy/object.h"
#include "objBall.h"
#include "Boy/Environment.h"
#include "Boy/winGraphicObject.h"
#include "Boy/winGraphics.h"
#include "Boy/winD3DFont.h"

#include <time.h>
#include "boy/BoundingSphere.h"

using namespace Boy;
using namespace Ball;
using namespace std;
Demo1 *Demo1::gInstance = NULL;
Demo1::Demo1()
{
}
Demo1::~Demo1()
{

}
Demo1 *Demo1::instance()
{
	if (gInstance==NULL)
	{
		gInstance = new Demo1();
	}
	return gInstance;
}
void Demo1::load()
{	
	mObjectMamager->load();
}
void Demo1::destroy()
{
	delete gInstance;
	gInstance = NULL;
}
void Demo1::update(float dt)
{	
		collision(dt);
       mObjectMamager->update(dt);

}
void Demo1::draw()
{
	Boy::Environment::instance()->getGraphics()->draw();
}
void Demo1::init()
{	
	//初始化鼠标监听器
	mShipMouseListener=new shipMouseListener(Boy::Environment::instance()->getMouse());
	mObjectMamager=new objectManager();	 
    mBallCollisonController=new ballCollisonController();


	mObjectMamager->createBall(/*位置*/new D3DXVECTOR3(10.1f,0.0f,10.1f),/*方向*/new D3DXVECTOR3(0.0f,0.0f,1.0f));

	//地板
	mFieldObj= new objField(TEXT("field.x"));
	mFieldObj->scaling(1/2.0f);
	mFieldObj->setPos(new D3DXVECTOR3(0.0f,-6.0f,0.0f));
	mObjectMamager->addObject(mFieldObj);
	mBallCollisonController->addObstaclesBox(mFieldObj);
	//边界
	mFieldBorderObj= new object(TEXT("field_border.x"));
	mFieldBorderObj->scaling(1/2.0f);
	mFieldBorderObj->setPos(new D3DXVECTOR3(.0f,-6.0f,0.0f));
	mObjectMamager->addObject(mFieldBorderObj);

	//挡板
	mShipObj= new objShip(TEXT("ship.x"));
	mShipObj->scaling(70.0f);

	mObjectMamager->addObject(mShipObj);	
	mShipObj->setPos(new D3DXVECTOR3(-75.0f,0.0f,-70.0f));
	mBallCollisonController->addObstaclesBox(mShipObj);
	//初始化  block

	objBlock * testBlock=new objBlock(TEXT("block.x"));
	testBlock->scaling(15.0f);
		testBlock->setPos(new D3DXVECTOR3(-70.0f,0.0f,70.0f));

	mObjBlockList.push_back(testBlock);
	for (int i=0;i<(int)mObjBlockList.size();i++)
	{
		mObjectMamager->addObject(mObjBlockList[i]);
		mBallCollisonController->addObstaclesBox(mObjBlockList[i]);
	}





}
void Demo1::loadComplete(){
	
}
void Demo1::collision(float dt)
{
	mBallCollisonController->collision(dt);
}

objShip * Demo1::ShipObj() const
{
	return mShipObj;
}

void Demo1::ShipObj( objShip * val )
{
	mShipObj = val;
}

void Demo1::testOutPut()
{
cout<<"测试 外部调用demo1成功";
}

ballCollisonController * Demo1::BallCollisonController() const
{
	return mBallCollisonController;
}

void Demo1::BallCollisonController( ballCollisonController * val )
{
	mBallCollisonController = val;
}

objectManager * Demo1::ObjectMamager() const
{
	return mObjectMamager;
}

void Demo1::ObjectMamager( objectManager * val )
{
	mObjectMamager = val;
}
