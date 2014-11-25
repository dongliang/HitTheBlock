#pragma once
#include "Mouse.h"
#include "EventListener.h"

namespace Boy
{
	class MouseListener:public EventListener
	{
	public:
		MouseListener() {}
		virtual ~MouseListener() {}
		virtual void leftButtonUp(MouseEvent *evt) = 0;
		virtual void leftButtonDown(MouseEvent *evt) = 0;
		virtual void rightButtonUp(MouseEvent *evt) = 0;
		virtual void rightButtonDown(MouseEvent *evt) = 0;
		virtual void middleButtonUp(MouseEvent *evt) = 0;
		virtual void middleButtonDown(MouseEvent *evt) = 0;
		virtual void mouseMove(MouseEvent *evt) = 0;
		virtual void mouseWheel(MouseEvent *evt) = 0;
		void handleEvent(Event* evt);
	};
}

