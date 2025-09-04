#pragma once
#include "GameObject.h"

class CCamera :
    public CGameObject
{
public:
    typedef struct tagProjectionMatrix {
        _float fAngle;
        _float fAspect;
        _float fNearZ;
        _float fFarZ;
    }PROJ_DESC;

    typedef struct tagViewMatrix {
        _float4 vPos;
        _float4 vFocus;
        _float4 vUp;
    }VIEW_DESC;

private:
    CCamera(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
    CCamera(CCamera& _pPrototype);
    virtual ~CCamera() = default;

private:
    _float4x4 m_ProjMatrix{};
    _float4x4 m_ViewMatrix{};

    PROJ_DESC m_tProjDesc{};
    VIEW_DESC m_tViewDesc{};

    _float m_fSpeed = 5.f;

public:
    void Set_Lens(PROJ_DESC* _pProjDesc);
    void Look_At(VIEW_DESC* _tViewDesc);
    void Go_Up(_float _fDeltaTime);
    void Go_Down(_float _fDeltaTime);
    void Go_Left(_float _fDeltaTime);
    void Go_Right(_float _fDeltaTime);

    void Move_Up(_float _fDeltaTime);
    void Move_Down(_float _fDeltaTime);
    void Move_Left(_float _fDeltaTime);
    void Move_Right(_float _fDeltaTime);

public:
    // CGameObject을(를) 통해 상속됨
    HRESULT Init() override;
    HRESULT Add_Component() override;
    _uint Pre_Update() override;
    _uint Update(_float _fDeltaTime) override;
    _uint Late_Update() override;
    HRESULT Render() override;

    _matrix Get_View() const;
    _matrix Get_Proj() const;
    _matrix Get_ViewProjMatrix() const;

    static CCamera* Create(
        ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
};

