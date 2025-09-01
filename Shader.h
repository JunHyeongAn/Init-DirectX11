#pragma once
#include "Component.h"
class CShader :
    public CComponent
{
protected:
    CShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
    CShader(CShader& _pPrototype);
    virtual ~CShader() = default;

protected:
    LPD3D11EFFECT               m_pEffect{ nullptr };
    LPD3D11EFFECTTECHNIQUE      m_pTech{ nullptr };

    ID3DBlob*                   m_pCompiledShader{ nullptr };
    ID3DBlob*                   m_pCompliationMsgs{ nullptr };

    ID3D11InputLayout*          m_pInputLayout{ nullptr };

public:
    LPD3D11EFFECTTECHNIQUE Get_Tech() const;
    void                   Set_IL(ID3D11InputLayout* _pInputLayout);

protected:
    virtual HRESULT Init() PURE;

protected:
    // CComponent을(를) 통해 상속됨
    void Free() override;
};

