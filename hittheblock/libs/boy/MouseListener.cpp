#include "MouseListener.h"
#include "MouseEvent.h"
#include<iostream>



void Boy::MouseListener::handleEvent( Event *evt )
{

	if (MouseEvent *mouseEvt=dynamic_cast<MouseEvent*>(evt))
	{
		switch (mouseEvt->Type())
		{
		case MouseEvent::TYPE_LEFT_MOUSE_DOWN:
			leftButtonDown(mouseEvt);
			break;
		case MouseEvent::TYPE_LEFT_MOUSE_UP:
			leftButtonUp(mouseEvt);
			break;
		case MouseEvent::TYPE_MIDDLE_MOUSE_UP:
			 middleButtonUp(mouseEvt);
			break;
		case MouseEvent::TYPE_MIDELE_MOUSE_DOWN:
			middleButtonDown(mouseEvt);
			break;
		case MouseEvent::TYPE_RIGHT_MOUSE_DOWN:
			rightButtonDown(mouseEvt);
			break;
		case MouseEvent::TYPE_RIGHT_MOUSE_UP:
			rightButtonUp(mouseEvt);
			break;
		case MouseEvent::TYPE_MOUSE_MOVE:
			mouseMove(mouseEvt);
	
			break;
		case MouseEvent::TYPE_MOUSE_WHEEL:
			mouseWheel(mouseEvt);
			break;
		default:
			std::cout<<"event TYPE_Undefined";
			break;		
		}
	} 
	else { 
		std::cout<<" mouseListener: it's not a MouseEvent object| location : MouseListener.cpp  -line 36";
	} 


}