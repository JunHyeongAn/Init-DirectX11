#pragma once
#include "Base.h"

class CComponent : public CBase
{
protected:
	ID3D11Device*			m_pDevice;
	ID3D11DeviceContext*	m_pContext;

protected:
	CComponent(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CComponent(CComponent& _pPrototype);
	virtual ~CComponent() = default;

protected:
	// CBase을(를) 통해 상속됨
	void Free() override PURE;
};

