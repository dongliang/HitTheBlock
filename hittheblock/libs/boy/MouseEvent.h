#pragma once
#include "Event.h"
#include <string>
namespace Boy{
	class EventDispatcher;
	class MouseEvent:public Event
	{
	public:

		static const int TYPE_Undefined=0;
		static const int TYPE_MOUSE_WHEEL=1;
		static const int TYPE_MOUSE_MOVE=2;
		static const int TYPE_LEFT_MOUSE_DOWN=3;
		static const int TYPE_LEFT_MOUSE_UP=4;
		static const int TYPE_MIDELE_MOUSE_DOWN=5;
		static const int TYPE_MIDDLE_MOUSE_UP=6;
		static const int TYPE_RIGHT_MOUSE_DOWN=7;
		static const int TYPE_RIGHT_MOUSE_UP=8;	
		MouseEvent();
		MouseEvent(int type, EventDispatcher *target);
		~MouseEvent();
		void init();
		float X() const;
		void X(float val);
		float Y() const;
		void Y(float val);
		bool CtrlKey() const;
		void CtrlKey(bool val);
		int Delta() const;
		void Delta(int val);
		bool ShiftKey() const;
		void ShiftKey(bool val);
		bool AltKey() const;
		void AltKey(bool val);
		bool LeftButtonDown() const;
		void LeftButtonDown(bool val);
		bool RightButtonDown() const;
		void RightButtonDown(bool val);
		bool MiddleButtonDown() const;
		void MiddleButtonDown(bool val);
	protected:
		float mX;
		float mY;		
		bool mCtrlKey;
		int mDelta;
		bool mShiftKey;
		bool mAltKey;
		bool mLeftButtonDown;
		bool mRightButtonDown;
		bool mMiddleButtonDown;	
	};
}