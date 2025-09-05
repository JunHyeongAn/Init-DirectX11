#pragma once
#include "Component.h"
class CTexture final : public CComponent
{
private:
	CTexture(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CTexture(CTexture& _pPrototype);
	virtual ~CTexture() = default;

public:
	HRESULT Init(wstring& _szFileName, _uint _iFileCnt);

private:
	vector<ID3D11ShaderResourceView*> m_SVRVector;

private:
	// CComponent을(를) 통해 상속됨
	void Free() override;
};

