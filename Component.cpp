#include "Component.h"

CComponent::CComponent(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	:m_pDevice(_pDevice), m_pContext(_pContext)
{
	m_pDevice->AddRef();
	m_pContext->AddRef();
}

CComponent::CComponent(CComponent& _pPrototype)
	:	m_pDevice(_pPrototype.m_pDevice),
		m_pContext(_pPrototype.m_pContext)
{
	m_pDevice->AddRef();
	m_pContext->AddRef();
}

void CComponent::Free()
{
	m_pDevice->Release();
	m_pContext->Release();
}
