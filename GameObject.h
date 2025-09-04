#pragma once
#include "Base.h"
#include "Define.h"

class CComponent;
class CGameObject abstract :public CBase
{
protected:
	CGameObject(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CGameObject(CGameObject& _pPrototype);
	virtual ~CGameObject() = default;

protected:
	ID3D11Device*			m_pDevice;
	ID3D11DeviceContext*	m_pContext;

	class CTransform*		m_pTransformCom{ nullptr };

	unordered_map<wstring, CComponent*> m_componentMap;

public:
	virtual HRESULT Init()			PURE;
	virtual HRESULT Add_Component() PURE;
	virtual _uint	Pre_Update()	PURE;
	virtual _uint	Update(_float _fDeltaTime)		PURE;
	virtual _uint	Late_Update()	PURE;
	virtual HRESULT Render()		PURE;
	CComponent* Find_Component(const wstring& _pTag);
	void Set_Pos(_fvector _vPos);
	void Set_Scale(_fvector _vScale);

protected:
	// CBase을(를) 통해 상속됨
	void Free() override;
};

