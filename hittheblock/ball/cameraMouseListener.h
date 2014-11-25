#include "boy/MouseListener.h"
#include "boy/Mouse.h"

using namespace Boy;
namespace Ball{

	class cameraMouseListener:public MouseListener
	{
	public:
		cameraMouseListener() {}
		virtual ~cameraMouseListener() {}
		virtual void leftButtonUp(MouseEvent *evt);
		virtual void leftButtonDown(MouseEvent *evt);
		virtual void rightButtonUp(MouseEvent *evt);
		virtual void rightButtonDown(MouseEvent *evt);
		virtual void middleButtonUp(MouseEvent *evt);
		virtual void middleButtonDown(MouseEvent *evt);
		virtual void mouseMove(MouseEvent *evt);
		virtual void mouseWheel(MouseEvent *evt);
	};
}