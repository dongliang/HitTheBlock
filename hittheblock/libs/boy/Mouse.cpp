#include "Mouse.h"
#include "Environment.h"
#include "MouseListener.h"
#include "MouseEvent.h"
#include <algorithm>

using namespace Boy;
using namespace std;

Mouse::Mouse(){

	mButtonsEnabled = true;
	mIsButtonDown[BUTTON_LEFT] = false;
	mIsButtonDown[BUTTON_RIGHT] = false;
	mIsButtonDown[BUTTON_MIDDLE] = false;
	mEvent=CreateMouseEvent();

}
Mouse::~Mouse()
{
}
void Mouse::setPosition(float x,float y)
{
	mX=x;
	mY=y;
}
bool Mouse::getButtonsEnabled() 
{ 
	return mButtonsEnabled; 
}
void Mouse::setButtonsEnabled(bool enabled) 
{ 
	//	envDebugLog("-----------> mouse %d: buttons=%d\n",mId,enabled);
	mButtonsEnabled = enabled; 
}
bool Mouse::isButtonDown(Button button)
{
	//assert(button==BUTTON_LEFT || button==BUTTON_RIGHT || button==BUTTON_MIDDLE);
	return mIsButtonDown[button];
}

void Mouse::fixButtonState(WPARAM wParam,UINT msg)
{
	//	wParam ���� ���������  ʹ�÷�ʽ wparam & MK_SHIFT  �������true ������
	// 	MK_LBUTTON ������� MK_MBUTTON �����м�
	// 	MK_RBUTTON �����Ҽ� MK_SHIFT ����Shift��  MK_CONTROL ����Ctrl��
	INT32 keyBtnFlag;
	keyBtnFlag = msg!=WM_MOUSEWHEEL ? wParam : HIWORD (wParam);
	//	��ֵ����״̬
	mIsButtonDown[BUTTON_LEFT]=keyBtnFlag&MK_LBUTTON;
	mIsButtonDown[BUTTON_RIGHT]=keyBtnFlag&MK_RBUTTON;
	mIsButtonDown[BUTTON_MIDDLE]=keyBtnFlag&MK_MBUTTON;
	mIsButtonDown[BUTTON_SHIFT]=keyBtnFlag&MK_SHIFT;
	mIsButtonDown[BUTTON_CTRL]=keyBtnFlag&MK_CONTROL;	
}
void Mouse::MouseCallBack(UINT msg,WPARAM wParam,LPARAM lParam)
{	
//	��ȡ���λ��
	int x= (int)LOWORD (lParam);
	int y=(int)HIWORD (lParam);
	setPosition(x,y);
	//	��������״̬ wParam ���� ���������
	fixButtonState(wParam,msg);     
	//����Event���󣬱����� ������λ������֮����Ϊ�¼������з�װ����Щ���ݡ�
	fixMouseEvent();
	

	switch(msg)
	{
		case WM_MOUSEMOVE:
	
			mEvent->Type(MouseEvent::TYPE_MOUSE_MOVE);
			dispatchEvent(mEvent);
			break;
		case 	WM_LBUTTONDOWN:
			mEvent->Type(MouseEvent::TYPE_LEFT_MOUSE_DOWN);
			dispatchEvent(mEvent);
			break;
		case WM_LBUTTONUP:
			mEvent->Type(MouseEvent::TYPE_LEFT_MOUSE_UP);
			dispatchEvent(mEvent);
			break;
//		case 	WM_LBUTTONDBLCLK:
		case 	WM_MBUTTONDOWN:
			mEvent->Type(MouseEvent::TYPE_MIDELE_MOUSE_DOWN);
			dispatchEvent(mEvent);
			break;
		case 	WM_MBUTTONUP:
			mEvent->Type(MouseEvent::TYPE_MIDDLE_MOUSE_UP);
			dispatchEvent(mEvent);
			break;
//		case 	WM_MBUTTONDBLCLK:
		case 	WM_RBUTTONDOWN:
			mEvent->Type(MouseEvent::TYPE_RIGHT_MOUSE_DOWN);
			dispatchEvent(mEvent);
			break;
		case 	WM_RBUTTONUP:
			mEvent->Type(MouseEvent::TYPE_RIGHT_MOUSE_UP);
			dispatchEvent(mEvent);
			break;
//		case 	WM_RBUTTONDBLCLK:
		case WM_MOUSEWHEEL:
			INT32 delta=(SHORT)HIWORD(wParam);
			mEvent->Type(MouseEvent::TYPE_MOUSE_WHEEL);
			mEvent->Delta(delta);
			dispatchEvent(mEvent);			
		break;
	}
}



MouseEvent *Boy::Mouse::CreateMouseEvent()
{
	MouseEvent *evt=new MouseEvent();
	evt->Target(this);
	evt->AltKey(mIsButtonDown[BUTTON_ALT]);
	evt->CtrlKey(mIsButtonDown[BUTTON_CTRL]);
	evt->LeftButtonDown(mIsButtonDown[BUTTON_LEFT]);
	evt->RightButtonDown(mIsButtonDown[BUTTON_RIGHT]);
	evt->MiddleButtonDown(mIsButtonDown[BUTTON_MIDDLE]);
	evt->ShiftKey(mIsButtonDown[BUTTON_SHIFT]);
	evt->X(mX);
	evt->Y(mY);
	return evt;
}

float Boy::Mouse::Y() const
{
	return mY;
}

void Boy::Mouse::Y( float val )
{
	mY = val;
}

void Boy::Mouse::X( float val )
{
	mX = val;
}

float Boy::Mouse::X() const
{
	return mX;
}

void Boy::Mouse::fixMouseEvent()
{
	mEvent->AltKey(mIsButtonDown[BUTTON_ALT]);
	mEvent->CtrlKey(mIsButtonDown[BUTTON_CTRL]);
	mEvent->LeftButtonDown(mIsButtonDown[BUTTON_LEFT]);
	mEvent->RightButtonDown(mIsButtonDown[BUTTON_RIGHT]);
	mEvent->MiddleButtonDown(mIsButtonDown[BUTTON_MIDDLE]);
	mEvent->ShiftKey(mIsButtonDown[BUTTON_SHIFT]);
	mEvent->X(mX);
	mEvent->Y(mY);
	setChanged();
}
