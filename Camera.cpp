#include "Camera.h"

CCamera::CCamera(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CGameObject(_pDevice, _pContext)
{
	ZeroMemory(&m_tProjDesc, sizeof(PROJ_DESC));
	ZeroMemory(&m_tViewDesc, sizeof(VIEW_DESC));
}

CCamera::CCamera(CCamera& _pPrototype)
	: CGameObject(_pPrototype)
	, m_ProjMatrix(_pPrototype.m_ProjMatrix)
	, m_ViewMatrix(_pPrototype.m_ViewMatrix)
	, m_tProjDesc(_pPrototype.m_tProjDesc)
	, m_tViewDesc(_pPrototype.m_tViewDesc)
{
	ZeroMemory(&m_tProjDesc, sizeof(PROJ_DESC));
	ZeroMemory(&m_tViewDesc, sizeof(VIEW_DESC));
}

void CCamera::Set_Lens(PROJ_DESC* _pProjDesc)
{
	memcpy(&m_tProjDesc, _pProjDesc, sizeof(PROJ_DESC));
}

void CCamera::Look_At(VIEW_DESC* _tViewDesc)
{
	memcpy(&m_tProjDesc, _tViewDesc, sizeof(VIEW_DESC));
}

void CCamera::Go_Up(_float _fDeltaTime)
{
	m_tViewDesc.vFocus.y += m_fSpeed * _fDeltaTime;
}

void CCamera::Go_Down(_float _fDeltaTime)
{
	m_tViewDesc.vFocus.y -= m_fSpeed * _fDeltaTime;
}

void CCamera::Go_Left(_float _fDeltaTime)
{
	m_tViewDesc.vFocus.x -= m_fSpeed * _fDeltaTime;
}

void CCamera::Go_Right(_float _fDeltaTime)
{
	m_tViewDesc.vFocus.x += m_fSpeed * _fDeltaTime;
}

void CCamera::Move_Up(_float _fDeltaTime)
{
	m_tViewDesc.vPos.y += m_fSpeed * _fDeltaTime;
}

void CCamera::Move_Down(_float _fDeltaTime)
{
	m_tViewDesc.vPos.y -= m_fSpeed * _fDeltaTime;
}

void CCamera::Move_Left(_float _fDeltaTime)
{
	m_tViewDesc.vPos.x -= m_fSpeed * _fDeltaTime;
}

void CCamera::Move_Right(_float _fDeltaTime)
{
	m_tViewDesc.vPos.x += m_fSpeed * _fDeltaTime;
}


HRESULT CCamera::Init()
{
	m_tProjDesc.fAngle		= 60.f;
	m_tProjDesc.fAspect		= static_cast<_float>(g_iWidth) / static_cast<_float>(g_iHeight);
	m_tProjDesc.fFarZ		= 1000.f;
	m_tProjDesc.fNearZ		= 0.1f;

	m_tViewDesc.vPos		= _float4(0.f, 5.f, -5.f, 1.f);
	m_tViewDesc.vFocus		= _float4(0.f, 0.f, 0.f, 0.f);
	m_tViewDesc.vUp			= _float4(0.f, 1.f, 0.f, 0.f);
	return S_OK;
}

HRESULT CCamera::Add_Component()
{
	return S_OK;
}

_uint CCamera::Pre_Update()
{
	return _uint();
}

_uint CCamera::Update(_float _fDeltaTime)
{
	_matrix ProjMatrix = XMMatrixPerspectiveFovLH(
		XMConvertToRadians(m_tProjDesc.fAngle)
		, m_tProjDesc.fAspect
		, m_tProjDesc.fNearZ
		, m_tProjDesc.fFarZ
	);

	XMStoreFloat4x4(&m_ProjMatrix, ProjMatrix);

	_matrix ViewMatrix = XMMatrixLookAtLH(
		XMLoadFloat4(&m_tViewDesc.vPos)
		, XMLoadFloat4(&m_tViewDesc.vFocus)
		, XMLoadFloat4(&m_tViewDesc.vUp)
	);

	if (GetAsyncKeyState('X')) {
		int i = 10;
	}

	XMStoreFloat4x4(&m_ViewMatrix, ViewMatrix);

	return 1;
}

_uint CCamera::Late_Update()
{
	return _uint();
}

HRESULT CCamera::Render()
{
	return E_NOTIMPL;
}

_matrix CCamera::Get_View() const
{
	return XMLoadFloat4x4(&m_ViewMatrix);
}

_matrix CCamera::Get_Proj() const
{
	return XMLoadFloat4x4(&m_ProjMatrix);
}

_matrix CCamera::Get_ViewProjMatrix() const
{
	return XMMatrixMultiply(
		XMLoadFloat4x4(&m_ViewMatrix)
		, XMLoadFloat4x4(&m_ProjMatrix)
	);
}

CCamera* CCamera::Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
{
	CCamera* pCamera = new CCamera(_pDevice, _pContext);

	if (!pCamera) {
		MSG_BOX("Failed to create Camera");
		return nullptr;
	}

	if (FAILED(pCamera->Init())) {
		MSG_BOX("Failed to Init Camera");
		return nullptr;
	}

	return pCamera;
}
