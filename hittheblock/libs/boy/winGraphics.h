#pragma once
#include "winGraphicObject.h"
#include <algorithm>
namespace Boy{

	class winGraphics{

	public:
		winGraphics() ;
		winGraphics(IDirect3DDevice9* pDevice) ;
		virtual ~winGraphics() ;
		 void draw();
		 void addObj(winGraphicObject *obj);
		 winGraphicObject* loadObject(std::string src,bool isShow,std::string standTexture);
		 void setup();
		IDirect3DDevice9* GetDevice();
		void removeObj(winGraphicObject *obj);
		 D3DLIGHT9 InitDirectionalLight(D3DXVECTOR3* direction, D3DXCOLOR* color);
	protected:
		std::vector<winGraphicObject*> mObjList;
		IDirect3DDevice9* mpDevice;
	};
}