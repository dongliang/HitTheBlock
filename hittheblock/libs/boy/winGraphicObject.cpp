#include "winGraphicObject.h"

using namespace Boy;
using namespace std;

winGraphicObject::winGraphicObject() {
}
winGraphicObject::winGraphicObject(	
								   ID3DXMesh* mesh,
								   std::vector<D3DMATERIAL9> mtrls,
								   std::vector<IDirect3DTexture9*> textures,
								   bool state)
{
	init(mesh,mtrls,textures,state);
}

winGraphicObject::~winGraphicObject() {
	cleanup();
}
void winGraphicObject::cleanup()
{
	func::Release(mMesh);
	for(DWORD i = 0; i < mTextures.size(); i++)
	func::Release(mTextures[i]);
}
void winGraphicObject::init(
					   ID3DXMesh* mesh,
					   std::vector<D3DMATERIAL9> mtrls,
					   std::vector<IDirect3DTexture9*> textures,
					   bool state)
{
	mMesh=mesh;
	mMtrls=mtrls;
	mTextures=textures;
	mShow=state;

	D3DXMatrixIdentity(&mWorldMatrix);

}
void winGraphicObject::show()
{
	mShow=true;
}
ID3DXMesh* winGraphicObject::getMesh()
{
	return mMesh;
}
std::vector<D3DMATERIAL9> winGraphicObject::getMtrls()
{
	return  mMtrls;
}

std::vector<IDirect3DTexture9*> winGraphicObject::getTextures()
{
	return  mTextures;
}

D3DXMATRIX winGraphicObject::getWorldMatrix(){
	return mWorldMatrix;
}
void winGraphicObject::setWorldMatrix(D3DXMATRIX matrix){
	mWorldMatrix=matrix;
}

BoundingSphere winGraphicObject::getBoundingSphere()
{	
	HRESULT hr=0;
	BoundingSphere bs;
	D3DXVECTOR3 bsCenter;
	float bsRadius;
	BYTE * v=0;
	mMesh->LockVertexBuffer(0,(void **) &v);
	hr=D3DXComputeBoundingSphere(
		(D3DXVECTOR3*)v,
		mMesh->GetNumVertices(),
		D3DXGetFVFVertexSize(mMesh->GetFVF()),
		&bsCenter,
		&bsRadius);
	mMesh->UnlockVertexBuffer();
	if (FAILED(hr))
	{
		MessageBox(0, TEXT("D3DXComputeBoundingSphere- FAILED"), 0, 0);
	}
	bs.setCenterPos(bsCenter);
	bs.setRadius(bsRadius);
	return bs;
}

BoundingBox winGraphicObject::getBoundingBox()
{	
	HRESULT hr=0;
	BoundingBox bb;
	D3DXVECTOR3 bbMax;
	D3DXVECTOR3 bbMin;
	BYTE * v=0;
	mMesh->LockVertexBuffer(0,(void **) &v);
	hr=D3DXComputeBoundingBox(
		(D3DXVECTOR3*)v,
		mMesh->GetNumVertices(),
		D3DXGetFVFVertexSize(mMesh->GetFVF()),
		&bbMin,
		&bbMax);
	mMesh->UnlockVertexBuffer();
	if (FAILED(hr))
	{
		MessageBox(0, TEXT("D3DXComputeBoundingSphere- FAILED"), 0, 0);
	}

	bb.Min(bbMin);
	bb.Max(bbMax);

	cout<<"box:\n"<<"min: x:"<<bbMin.x<<" y:"<<bbMin.y<<" z:"<<bbMin.z<<"\n";
		cout<<"max: x:"<<bbMax.x<<" y:"<<bbMax.y<<" z:"<<bbMax.z<<"\n";
	return bb;
}

