#include "Shader.h"

CShader::CShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CComponent(_pDevice, _pContext)
{
}

CShader::CShader(CShader& _pPrototype)
	:CComponent(_pPrototype)
	, m_pEffect(_pPrototype.m_pEffect)
	, m_pTech(_pPrototype.m_pTech)
	, m_pCompiledShader(_pPrototype.m_pCompiledShader)
	, m_pCompliationMsgs(_pPrototype.m_pCompliationMsgs)
	, m_pInputLayout(_pPrototype.m_pInputLayout)
{
	m_pEffect->AddRef();
	m_pCompiledShader->AddRef();
	m_pCompliationMsgs->AddRef();
	m_pInputLayout->AddRef();
}

LPD3D11EFFECTTECHNIQUE CShader::Get_Tech() const
{
	return m_pTech;
}

void CShader::Set_IL(ID3D11InputLayout* _pInputLayout)
{
	m_pInputLayout = _pInputLayout;
	m_pInputLayout->AddRef();
}

void CShader::Free()
{
	m_pEffect->Release();
	m_pCompiledShader->Release();
	m_pCompliationMsgs->Release();
	m_pInputLayout->Release();
}
