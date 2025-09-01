#pragma once
#include "GameObject.h"

class CBoxObject final :public CGameObject
{
private:
	CBoxObject(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CBoxObject(CBoxObject& _pPrototype);
	virtual ~CBoxObject() = default;

public:
	// CGameObject을(를) 통해 상속됨
	HRESULT Init()			override;
	HRESULT Add_Component() override;
	_uint Pre_Update()		override;
	_uint Update(_float _fDeltaTime)			override;
	_uint Late_Update()		override;
	HRESULT Render()		override;
	static CBoxObject* Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
};

