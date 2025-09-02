#include "Shader.h"

CShader::CShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CComponent(_pDevice, _pContext)
{
}

CShader::CShader(CShader& _pPrototype)
	:CComponent(_pPrototype)
	, m_pEffect(_pPrototype.m_pEffect)
	, m_pCompiledShader(_pPrototype.m_pCompiledShader)
	, m_pCompliationMsgs(_pPrototype.m_pCompliationMsgs)
{
	m_pEffect->AddRef();
	m_pCompiledShader->AddRef();
	m_pCompliationMsgs->AddRef();
}

void CShader::Free()
{
	m_pEffect->Release();
	m_pCompiledShader->Release();
	m_pCompliationMsgs->Release();
}
