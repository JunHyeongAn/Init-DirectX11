#pragma once
#include "Shader.h"

class CDefaultShader final : public CShader
{
private:
	CDefaultShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CDefaultShader(CDefaultShader& _pPrototype);
	virtual ~CDefaultShader() = default;

public:
	static CDefaultShader* Create(
		ID3D11Device* _pDevice
		, ID3D11DeviceContext* _pContext
		, SHADER_DESC& _pDesc
	);
	void Begin(_uint _iPassNum) override;

private:
	// CShader을(를) 통해 상속됨
	HRESULT Init(SHADER_DESC& _pDesc) override;
	void Free() override;
};

