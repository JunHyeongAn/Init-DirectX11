#include "Texture.h"

CTexture::CTexture(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CComponent(_pDevice, _pContext)
{
}

CTexture::CTexture(CTexture& _pPrototype)
	: CComponent(_pPrototype)
{
}

HRESULT CTexture::Init(wstring& _szFileName, _uint _iFileCnt)
{ 
	ID3D11ShaderResourceView* pSVR = nullptr;

	wstring szFilePath = TEXTURE_FILE_PATH + _szFileName;
	
	HRESULT hr = CreateDDSTextureFromFile(
		m_pDevice
		, szFilePath.c_str()
		, nullptr
		, &pSVR
	);

	if (FAILED(hr)) {
		MSG_BOX("DDS Texture Create Failed!!");
		return E_FAIL;
	}

	return S_OK;
}

void CTexture::Free()
{
	__super::Free();
	 //CreateDDSTextureFromFile(,)
}
