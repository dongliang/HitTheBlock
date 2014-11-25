#include "winGraphics.h"
using namespace Boy;
using namespace std;

winGraphics::winGraphics() {
}
winGraphics::winGraphics(IDirect3DDevice9* pDevice) {
mpDevice=pDevice;
setup();
}
winGraphics::~winGraphics() {}

void winGraphics::draw(){
	 std::vector<winGraphicObject*>::iterator iter;
	for(iter=mObjList.begin();iter!=mObjList.end();iter++)
	{
		winGraphicObject* tempObj=*iter;
		std::vector<D3DMATERIAL9> tempMtrls=tempObj->getMtrls();
		std::vector<IDirect3DTexture9*> tempTextures=tempObj->getTextures();
		ID3DXMesh* tempMesh=tempObj->getMesh();
		for(DWORD i = 0; i < tempMtrls.size(); i++)
		{
			mpDevice->SetMaterial( &tempMtrls[i]);
			


			mpDevice->SetTexture(0, tempTextures[i]);
			mpDevice->SetTransform(D3DTS_WORLD,&tempObj->getWorldMatrix());
			tempMesh->DrawSubset(i);
		}	
	}		
};
void winGraphics::addObj(winGraphicObject *obj){

	mObjList.push_back(obj);

};
winGraphicObject*  winGraphics::loadObject(string src,bool isShow,string standTexture){
	
	ID3DXMesh*                      Mesh = 0;
	std::vector<D3DMATERIAL9>       Mtrls(0);
	std::vector<IDirect3DTexture9*> Textures(0);
	HRESULT hr = 0;
	ID3DXBuffer* adjBuffer  = 0;
	ID3DXBuffer* mtrlBuffer = 0;
	DWORD        numMtrls   = 0;
	hr = D3DXLoadMeshFromX(  
		src.c_str(),
		D3DXMESH_MANAGED,
		mpDevice,
		&adjBuffer,
		&mtrlBuffer,
		0,
		&numMtrls,
		&Mesh);

		if(FAILED(hr))
		{
			::MessageBox(0, TEXT("D3DXLoadMeshFromX() - FAILED"), 0, 0);
			return false;
		}
		if( mtrlBuffer != 0 && numMtrls != 0 )
		{
			D3DXMATERIAL* mtrls = (D3DXMATERIAL*)mtrlBuffer->GetBufferPointer();

			for(DWORD i = 0; i < numMtrls; i++)
			{
				// the MatD3D property doesn't have an ambient value set
				// when its loaded, so set it now:
				mtrls[i].MatD3D.Ambient = mtrls[i].MatD3D.Diffuse;

				// save the ith material
				Mtrls.push_back( mtrls[i].MatD3D );

				// check if the ith material has an associative texture
				string textureName;
				IDirect3DTexture9* tex = 0;
				if (standTexture.length()!=0)
				{
						textureName=standTexture;
						D3DXCreateTextureFromFile(
							mpDevice,
							textureName.c_str(),
							&tex);
						Textures.push_back( tex );
				}
				else if( mtrls[i].pTextureFilename != 0 )
				{
						// yes, load the texture for the ith subset						
						textureName=mtrls[i].pTextureFilename;
						D3DXCreateTextureFromFile(
							mpDevice,
							textureName.c_str(),
							&tex);
						// save the loaded texture
						Textures.push_back( tex );
				}
				else
				{
						// no texture for the ith subset
						Textures.push_back( 0 );
				}	
				
			}
		}
		func::Release(mtrlBuffer);
		//ÓÅ»¯
		hr = Mesh->OptimizeInplace(		
			D3DXMESHOPT_ATTRSORT |
			D3DXMESHOPT_COMPACT  |
			D3DXMESHOPT_VERTEXCACHE,
			(DWORD*)adjBuffer->GetBufferPointer(),
			0, 0, 0);
		func::Release(adjBuffer);
		if(FAILED(hr))
		{
			::MessageBox(0, TEXT("OptimizeInplace() - FAILED"), 0, 0);
			return false;
		}
		winGraphicObject *obj=new winGraphicObject( Mesh,Mtrls,Textures,isShow);
		
		addObj(obj);
		return obj;

}

void winGraphics::setup()
{
	//
	// Set texture filters.
	//

	mpDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);
	mpDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	mpDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_POINT);

	// 
	// Set Lights.
	//

	D3DXVECTOR3 dir(1.0f, -1.0f, 1.0f);
	D3DXCOLOR col(1.0f, 1.0f, 1.0f, 1.0f);
	D3DLIGHT9 light = InitDirectionalLight(&dir, &col);

	mpDevice->SetLight(0, &light);
	mpDevice->LightEnable(0, true);
	mpDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	mpDevice->SetRenderState(D3DRS_SPECULARENABLE, true);
	//mpDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME)  ;


	//
	// Set camera.
	//

	D3DXVECTOR3 pos(0.0f, 300, -300.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);

	D3DXMATRIX V;
	D3DXMatrixLookAtLH(
		&V,
		&pos,
		&target,
		&up);

	mpDevice->SetTransform(D3DTS_VIEW, &V);

	//
	// Set projection matrix.
	//

	D3DXMATRIX mat_proj;
	D3DXMatrixPerspectiveFovLH(&mat_proj, D3DX_PI/7.2, 1.333333333f, 2.0f, 10000.0f);
	mpDevice->SetTransform(D3DTS_PROJECTION, &mat_proj);
}

D3DLIGHT9 winGraphics::InitDirectionalLight(D3DXVECTOR3* direction, D3DXCOLOR* color)
{
	D3DLIGHT9 light;
	::ZeroMemory(&light, sizeof(light));

	light.Type      = D3DLIGHT_DIRECTIONAL;
	light.Ambient   = *color * 0.4f;
	light.Diffuse   = *color;
	light.Specular  = *color * 0.6f;
	light.Direction = *direction;

	return light;
}
IDirect3DDevice9* winGraphics::GetDevice()
{
	return mpDevice;
}

void Boy::winGraphics::removeObj( winGraphicObject *obj )
{
	vector<winGraphicObject *>::iterator ite=mObjList.begin();
	while(ite!=mObjList.end())
	{
		ite=find(ite,mObjList.end(),obj);
		if (ite!=mObjList.end())
		{
			ite=mObjList.erase(ite);
		}
	}
}
