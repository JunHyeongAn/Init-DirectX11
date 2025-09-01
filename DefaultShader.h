#pragma once
#include "Shader.h"

class CDefaultShader final : public CShader
{
private:
	CDefaultShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CDefaultShader(CDefaultShader& _pPrototype);
	virtual ~CDefaultShader() = default;

public:
	static CDefaultShader* Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);

private:
	// CShader��(��) ���� ��ӵ�
	HRESULT Init() override;
	void Free() override;
};

