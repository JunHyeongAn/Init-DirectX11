#include "GameObject.h"
#include "Component.h"

CGameObject::CGameObject(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: m_pDevice(_pDevice), m_pContext(_pContext)
{
	m_pDevice->AddRef();
	m_pContext->AddRef();
}

CGameObject::CGameObject(CGameObject& _pPrototype)
	:	m_pDevice(_pPrototype.m_pDevice),
		m_pContext(_pPrototype.m_pContext),
		m_componentMap(_pPrototype.m_componentMap)
{
	m_pDevice->AddRef();
	m_pContext->AddRef();
}

void CGameObject::Free()
{
	m_pDevice->Release();
	m_pContext->Release();
}
