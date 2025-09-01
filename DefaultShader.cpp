#include "DefaultShader.h"

CDefaultShader::CDefaultShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CShader(_pDevice, _pContext)
{
}

CDefaultShader::CDefaultShader(CDefaultShader& _pPrototype)
	:CShader(_pPrototype)
{
}

CDefaultShader* CDefaultShader::Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
{
	CDefaultShader* pShader = new CDefaultShader(_pDevice, _pContext);

	if (!pShader) {
		MSG_BOX("Default_Shader Create Failed!!");
		return nullptr;
	}

	if (FAILED(pShader->Init())) {
		MSG_BOX("Default_Shader init Failed!!");
		return nullptr;
	}

	return pShader;
}

HRESULT CDefaultShader::Init()
{
	_uint		iHlslFlag = {};

#ifdef _DEBUG
	iHlslFlag = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
	iHlslFlag = D3DCOMPILE_OPTIMIZATION_LEVEL1;
#endif	

	HRESULT hr = D3DX11CompileEffectFromFile(
		L"FX/"
		, nullptr
		, D3D_COMPILE_STANDARD_FILE_INCLUDE
		, iHlslFlag
		, 0
		, m_pDevice
		, &m_pEffect
		, &m_pCompliationMsgs
	);

	return E_NOTIMPL;
}

void CDefaultShader::Free()
{
}
