#pragma once
#include "Component.h"
class CTransform final : public CComponent
{
protected:
	CTransform(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CTransform(CTransform& _pPrototype);
	virtual ~CTransform() = default;

private:
	_float4x4		m_WorldMatrix{};
	_float			m_fSpeedPerSec{};
	_float			m_fRotatePerSec{};

public:
	void Move_Forward(_float _fDeltaTime);
	void Move_Left(_float _fDeltaTime);
	void Move_Right(_float _fDeltaTime);
	void Move_Backward(_float _fDeltaTime);

	void Rotation(_fvector _vAxis, _float _fAngle, _float _fDeltaTime);
	void Turn(_fvector _vAxis, _float _fDeltaTime);

	_float3 Get_Scale() const;

	_vector Get_State(TRANSITIONS_STATE _eState) const;
	void	Set_State(TRANSITIONS_STATE _eState, _fvector _vValue);

private:
	void Move(TRANSITIONS_STATE _eDir, _float _fDeltaTime, _bool _bOpposite = FALSE);
	void Rotate(_fvector _vAxis, _float _fRotateRate, _float _fDeltaTime);

	// CComponent을(를) 통해 상속됨
	void Free() override;
};

