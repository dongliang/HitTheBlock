#pragma once
#include "Boy/Game.h"
#include "boy/object.h"
#include "objBall.h"
#include "boy/winBase.h"
#include "objField.h"
#include "cameraMouseListener.h"
#include "obj2dBox.h"
#include "objShip.h"
#include "ballCollisonController.h"
#include "shipMouseListener.h"
#include "objBlock.h"
#include "objectManager.h"
using namespace Ball;
using namespace Boy;

class Demo1: public Boy::Game
{
public:
	Demo1();
	virtual ~Demo1();
	static Demo1 *instance();
	static void destroy();
	virtual void update(float dt);
	virtual void draw();
	virtual void load();
	virtual void init();
	virtual void loadComplete();
	virtual void collision(float dt);
	objShip * ShipObj() const;
	void ShipObj(objShip * val);
	void testOutPut();
	ballCollisonController * BallCollisonController() const;
	void BallCollisonController(ballCollisonController * val);
	objectManager * ObjectMamager() const;
	void ObjectMamager(objectManager * val);


private:
	static Demo1 *gInstance;
protected:
	ball *mBallObj;
	objField *mFieldObj;
	object *mFieldBorderObj;
	objShip *mShipObj;
	object* mSkyObj;
	vector<objBlock *> mObjBlockList;

	//Êó±ê¼àÌýÆ÷
	cameraMouseListener * mCameraMouseListener;
	shipMouseListener * mShipMouseListener;
	ballCollisonController *mBallCollisonController;
	objectManager * mObjectMamager;
};