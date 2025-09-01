#include "BoxObject.h"
#include "BoxBuffer.h"

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
	return E_NOTIMPL;
}

HRESULT CBoxObject::Add_Component()
{
	CBoxBuffer* pBoxBuf = CBoxBuffer::Create(m_pDevice, m_pContext);
	if (!pBoxBuf) {
		MSG_BOX("BoxObject can't create BoxBuffer");
		return E_FAIL;
	}

	m_componentMap.emplace(L"BoxBuffer", pBoxBuf);

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

	pBoxBuf->Bind();
	pBoxBuf->Render();

	return E_NOTIMPL;
}

CBoxObject* CBoxObject::Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
{
	CBoxObject* pBoxObject = new CBoxObject(_pDevice, _pContext);

	if (FAILED(pBoxObject->Init())) {
		MSG_BOX("CBoxObject Created Failed!!");
	}

	return nullptr;
}
