#pragma once
#include <vector>
#include "Vector2.h"
#include<windows.h>
#include "EventDispatcher.h"

namespace Boy{
	class MouseEvent;
	class MouseListener;
	class Mouse:public EventDispatcher
	{

	public:
		enum Button
		{
			BUTTON_LEFT = 0,
			BUTTON_MIDDLE = 1,
			BUTTON_RIGHT = 2,
			BUTTON_SHIFT=3,
			BUTTON_CTRL=4,
			BUTTON_ALT=5,
			BUTTON_UNKNOWN = 0xff
		};
		Mouse();
		virtual ~Mouse();
		void setPosition(float x,float y);
		bool getButtonsEnabled();
		void setButtonsEnabled(bool enabled);		
		void MouseCallBack(UINT msg,WPARAM wParam,LPARAM lParam);
		bool isButtonDown(Button button); 
		void fixButtonState(WPARAM wParam,UINT msg);

		MouseEvent *CreateMouseEvent();
		void fixMouseEvent();
		float Y() const;
		void Y(float val);
		float X() const;
		void X(float val);


	protected:
		Vector2 mPosition;
		bool mIsVisible;
		bool mButtonsEnabled;
		bool mIsButtonDown[6];
		float mX;
		float mY;
		MouseEvent * mEvent;


	};
}