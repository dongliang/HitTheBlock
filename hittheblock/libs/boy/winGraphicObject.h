#pragma once
#include "winBase.h"
#include "BoundingSphere.h"
#include "BoundingBox.h"
namespace Boy{

	class winGraphicObject{

	public:
		winGraphicObject();
		winGraphicObject(
				ID3DXMesh* mesh,
				std::vector<D3DMATERIAL9> mtrls,
				std::vector<IDirect3DTexture9*> textures,
				bool state
			) ;
		~winGraphicObject() ;
		ID3DXMesh* getMesh();
		BoundingSphere getBoundingSphere();
		BoundingBox getBoundingBox();
		D3DXMATRIX  getWorldMatrix();
		void setWorldMatrix(D3DXMATRIX matrix);
		std::vector<D3DMATERIAL9> getMtrls();
		std::vector<IDirect3DTexture9*> getTextures();
		void setStandTextureName(std::string str);
		std::string getStandTextureName();
		
		void show(); 
		void init(ID3DXMesh* mesh,
			std::vector<D3DMATERIAL9> mtrls,
			std::vector<IDirect3DTexture9*> textures,
			bool state);
		void cleanup();
	protected:
	ID3DXMesh* mMesh;
	std::vector<D3DMATERIAL9> mMtrls;
	std::string mStandTextureName;
	std::vector<IDirect3DTexture9*> mTextures;
	D3DXMATRIX mWorldMatrix;
	bool mShow;
	};
}