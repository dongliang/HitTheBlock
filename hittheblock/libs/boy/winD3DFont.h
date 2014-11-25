#pragma once
#include "winBase.h"

#pragma warning (disable: 4244 4996)



using namespace std;
namespace Boy{
	class winD3DFont
	{
	public:
		winD3DFont(){}
		winD3DFont(IDirect3DDevice9* pDevice)
		{
			m_pFont		= NULL;
			D3DXFONT_DESC fd;//初始化字体
			ZeroMemory(&fd,sizeof(fd));
			fd.Height			= 17.5;
			fd.Width			= 8.5;
			fd.Weight			= 550;

			_tcscpy(fd.FaceName,TEXT("新宋体"));

			HRESULT hr = D3DXCreateFontIndirect(pDevice,&fd,&m_pFont);

		}
		virtual ~winD3DFont()
		{
			func::Release(m_pFont);
		}

		void drawText(LPRECT lprc,DWORD style,DWORD color)
		{
			m_pFont->DrawText(
				NULL,
				mShowInfo.c_str(),
				-1,
				lprc,
				style,
				color);
		}
		string getInfo()
		{
			return mShowInfo;
		}
		void setInfo(string str)
		{
			mShowInfo=str;
		}
		void addInfo(string str)
		{
			mShowInfo.append(str);
		}
		void clearInfo()
		{
			mShowInfo.clear();
		}

	protected:

		ID3DXFont*	m_pFont;
		IDirect3DDevice9*	m_pDevice;
		string mShowInfo;
	};
}
