#include "Transform.h"

CTransform::CTransform(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CComponent(_pDevice, _pContext)
{
}

CTransform::CTransform(CTransform& _pPrototype)
	: CComponent(_pPrototype)
	, m_WorldMatrix(_pPrototype.m_WorldMatrix)
	, m_fSpeedPerSec(_pPrototype.m_fSpeedPerSec)
	, m_fRotatePerSec(_pPrototype.m_fRotatePerSec)
{
}

void CTransform::Move_Forward(_float _fDeltaTime)
{
	Move(TRANSITIONS_STATE::LOOK, _fDeltaTime);
}

void CTransform::Move_Left(_float _fDeltaTime)
{
	Move(TRANSITIONS_STATE::RIGHT, _fDeltaTime, TRUE);
}

void CTransform::Move_Right(_float _fDeltaTime)
{
	Move(TRANSITIONS_STATE::RIGHT, _fDeltaTime);
}

void CTransform::Move_Backward(_float _fDeltaTime)
{
	Move(TRANSITIONS_STATE::RIGHT, _fDeltaTime, TRUE);
}

void CTransform::Rotation(_fvector _vAxis, _float _fAngle, _float _fDeltaTime)
{
	Rotate(_vAxis, _fAngle, _fDeltaTime);
}

void CTransform::Turn(_fvector _vAxis, _float _fDeltaTime)
{
	Rotate(_vAxis, m_fRotatePerSec, _fDeltaTime);
}

_float3 CTransform::Get_Scale() const
{
	_float3 vScale = {
		XMVectorGetX(Get_State(TRANSITIONS_STATE::RIGHT))
		, XMVectorGetX(Get_State(TRANSITIONS_STATE::UP))
		, XMVectorGetX(Get_State(TRANSITIONS_STATE::LOOK))
	};

	return vScale;
}

_vector CTransform::Get_State(TRANSITIONS_STATE _eState) const
{
	return XMLoadFloat4x4(&m_WorldMatrix).r[ENUM_CLASS(_eState)];
}

void CTransform::Set_State(TRANSITIONS_STATE _eState, _fvector _vValue)
{
	XMStoreFloat4(reinterpret_cast<_float4*>(m_WorldMatrix.m[ENUM_CLASS(_eState)]), _vValue);
}

void CTransform::Move(TRANSITIONS_STATE _eDir, _float _fDeltaTime, _bool _bOpposite)
{
	_vector vPosition = Get_State(TRANSITIONS_STATE::POSITION);
	_vector vDir = Get_State(_eDir);

	vDir = XMVector4Normalize(vDir);

	if (_bOpposite) vDir *= -1;

	vPosition += vDir * _fDeltaTime * m_fSpeedPerSec;

	Set_State(TRANSITIONS_STATE::POSITION, vPosition);
}

void CTransform::Rotate(_fvector _vAxis, _float _fRotateRate, _float _fDeltaTime)
{
	_float3 vScale = Get_Scale();

	_vector vRight = Get_State(TRANSITIONS_STATE::RIGHT) * vScale.x;
	_vector vUp = Get_State(TRANSITIONS_STATE::UP) * vScale.y;
	_vector vLook = Get_State(TRANSITIONS_STATE::LOOK) * vScale.z;

	_matrix RotationMatrix = XMMatrixRotationAxis(_vAxis, _fRotateRate * _fDeltaTime);

	vRight = XMVector3TransformNormal(vRight, RotationMatrix);
	vUp = XMVector3TransformNormal(vUp, RotationMatrix);
	vLook = XMVector3TransformNormal(vLook, RotationMatrix);

	Set_State(TRANSITIONS_STATE::RIGHT, vRight);
	Set_State(TRANSITIONS_STATE::UP, vUp);
	Set_State(TRANSITIONS_STATE::LOOK, vLook);
}


void CTransform::Free()
{
	__super::Free();
}
