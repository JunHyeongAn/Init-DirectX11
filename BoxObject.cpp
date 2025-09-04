#include "BoxObject.h"
#include "BoxBuffer.h"
#include "Shader.h"
#include "DefaultShader.h"

CBoxObject::CBoxObject(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CGameObject(_pDevice, _pContext)
{
}

CBoxObject::CBoxObject(CBoxObject& _pPrototype)
	:CGameObject(_pPrototype)
{
}

HRESULT CBoxObject::Init()
{
	if (FAILED(Add_Component())) {
		return E_FAIL;
	}
	return S_OK;
}

HRESULT CBoxObject::Add_Component()
{
	CBoxBuffer* pBoxBuf = CBoxBuffer::Create(m_pDevice, m_pContext);
	if (!pBoxBuf) {
		MSG_BOX("BoxObject can't create BoxBuffer");
		return E_FAIL;
	}

	CShader::SHADER_DESC tShaderDesc{};
	tShaderDesc.szFilePath = L"VertexShader.hlsl";
	tShaderDesc.szTechName = "DefaultTechnique";
	tShaderDesc.pElementDesc = pBoxBuf->Get_Desc();
	tShaderDesc.iElementNum = pBoxBuf->Get_DescCnt();
	tShaderDesc.eTopology = pBoxBuf->Get_Topology();

	CShader* pShader = CDefaultShader::Create(m_pDevice, m_pContext, tShaderDesc);
	if (!pShader) {
		MSG_BOX("BoxObject can't create pShader");
		return E_FAIL;
	}

	m_componentMap.emplace(L"BoxBuffer", pBoxBuf);
	m_componentMap.emplace(L"Shader", pShader);

	return S_OK;
}

_uint CBoxObject::Pre_Update()
{
	return _uint();
}

_uint CBoxObject::Update(_float _fDeltaTime)
{
	return _uint();
}

_uint CBoxObject::Late_Update()
{
	return _uint();
}

HRESULT CBoxObject::Render()
{
	CBoxBuffer* pBoxBuf = dynamic_cast<CBoxBuffer*>(
			m_componentMap.find(L"BoxBuffer")->second
		);

	CDefaultShader* pShader = dynamic_cast<CDefaultShader*>(
		m_componentMap.find(L"Shader")->second
	);

	pBoxBuf->Bind();
	pShader->Begin(0);
	pBoxBuf->Render();

	return E_NOTIMPL;
}

CBoxObject* CBoxObject::Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
{
	CBoxObject* pBoxObject = new CBoxObject(_pDevice, _pContext);

	if (FAILED(pBoxObject->Init())) {
		MSG_BOX("CBoxObject Created Failed!!");
		return nullptr;
	}

	return pBoxObject;
}
