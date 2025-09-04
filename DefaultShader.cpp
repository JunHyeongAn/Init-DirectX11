#include "DefaultShader.h"

CDefaultShader::CDefaultShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CShader(_pDevice, _pContext)
{
}

CDefaultShader::CDefaultShader(CDefaultShader& _pPrototype)
	:CShader(_pPrototype)
{
}

CDefaultShader* CDefaultShader::Create(
	ID3D11Device* _pDevice
	, ID3D11DeviceContext* _pContext
	, SHADER_DESC& _pDesc
)
{
	CDefaultShader* pShader = new CDefaultShader(_pDevice, _pContext);

	if (!pShader) {
		MSG_BOX("Default_Shader Create Failed!!");
		return nullptr;
	}

	if (FAILED(pShader->Init(_pDesc))) {
		MSG_BOX("Default_Shader init Failed!!");
		return nullptr;
	}

	return pShader;
}

HRESULT CDefaultShader::Init(SHADER_DESC& _pDesc)
{
	_uint		iHlslFlag = {};
	m_tDesc.eTopology		= _pDesc.eTopology;
	m_tDesc.iElementNum		= _pDesc.iElementNum;
	m_tDesc.pElementDesc	= _pDesc.pElementDesc;
	m_tDesc.szFilePath		= _pDesc.szFilePath;
	m_tDesc.szTechName		= _pDesc.szTechName;

#ifdef _DEBUG
	iHlslFlag = D3DCOMPILE_DEBUG | D3DCOMPILE_SKIP_OPTIMIZATION;
#else
	iHlslFlag = D3DCOMPILE_OPTIMIZATION_LEVEL1;
#endif	

	HRESULT hr = D3DX11CompileEffectFromFile(
		_pDesc.szFilePath
		, nullptr
		, D3D_COMPILE_STANDARD_FILE_INCLUDE
		, iHlslFlag
		, 0
		, m_pDevice
		, &m_pEffect
		, &m_pCompliationMsgs
	);

	if (FAILED(hr)) {
		MSG_BOX("Fail to Create Shader");
		return E_FAIL;
	}

	if (!m_pEffect) {
		MSG_BOX("Fail to Create Effect");
		return E_FAIL;
	}

	D3DX11_TECHNIQUE_DESC tTechDesc;
	LPD3D11EFFECTTECHNIQUE pTech = m_pEffect->GetTechniqueByName(_pDesc.szTechName);

	if (!pTech || !pTech->IsValid()) {
		MSG_BOX("Tech is not valid!!");
		return E_FAIL;
	}

	pTech->GetDesc(&tTechDesc);

	m_iNumPasses = tTechDesc.Passes;

	for (size_t i = 0; i < m_iNumPasses; i++)
	{
		ID3D11InputLayout* pInputLayout{ nullptr };

		D3DX11_PASS_DESC tPassDesc;
		ID3DX11EffectPass* pPass = pTech->GetPassByIndex(i);

		pPass->GetDesc(&tPassDesc);

		m_pDevice->CreateInputLayout(
			_pDesc.pElementDesc
			, _pDesc.iElementNum
			, tPassDesc.pIAInputSignature
			, tPassDesc.IAInputSignatureSize
			, &pInputLayout
		);

		m_pInputLayouts.push_back(pInputLayout);
	}

	return S_OK;
}

void CDefaultShader::Begin(_uint _iPassNum)
{
	m_pContext->IASetInputLayout(m_pInputLayouts[_iPassNum]);
	m_pContext->IASetPrimitiveTopology(m_tDesc.eTopology);

	m_pEffect
		->GetTechniqueByName(m_tDesc.szTechName)
		->GetPassByIndex(_iPassNum)
		->Apply(0, m_pContext); 
}

void CDefaultShader::Free()
{
	__super::Free();
}