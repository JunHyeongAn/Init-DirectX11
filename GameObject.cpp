#include "GameObject.h"
#include "Component.h"
#include "Transform.h"

CGameObject::CGameObject(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: m_pDevice(_pDevice), m_pContext(_pContext)
{
	m_pDevice->AddRef();
	m_pContext->AddRef();
}

CGameObject::CGameObject(CGameObject& _pPrototype)
	: m_pDevice(_pPrototype.m_pDevice),
	m_pContext(_pPrototype.m_pContext),
	m_pTransformCom(_pPrototype.m_pTransformCom),
	m_componentMap(_pPrototype.m_componentMap)
{
	m_pDevice->AddRef();
	m_pContext->AddRef();
}

CComponent* CGameObject::Find_Component(const wstring& _pTag)
{
	auto iter = m_componentMap.find(_pTag);

	if (iter == m_componentMap.end()) {
		return nullptr;
	}

	return iter->second;
}

void CGameObject::Set_Pos(_fvector _vPos) {
	m_pTransformCom->Set_Position(_vPos);
}

void CGameObject::Set_Scale(_fvector _vScale)
{
	m_pTransformCom->Set_Scale(_vScale);
}

void CGameObject::Free()
{
	m_pDevice->Release();
	m_pContext->Release();
}
