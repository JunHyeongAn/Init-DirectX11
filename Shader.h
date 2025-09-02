#pragma once
#include "Component.h"
class CShader :
    public CComponent
{
public:
    typedef struct ShaderDesc {
        const _tchar* szFilePath;
        const char* szTechName;
        const D3D11_INPUT_ELEMENT_DESC* pElementDesc;
        _uint iElementNum;
        _uint iPassNum;
    } SHADER_DESC;

protected:
    CShader(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
    CShader(CShader& _pPrototype);
    virtual ~CShader() = default;

protected:
    LPD3D11EFFECT               m_pEffect{ nullptr };

    ID3DBlob*                   m_pCompiledShader{ nullptr };
    ID3DBlob*                   m_pCompliationMsgs{ nullptr };

    _uint                       m_iNumPasses{};

    vector<ID3D11InputLayout*>  m_pInputLayouts{};

public:
    LPD3D11EFFECTTECHNIQUE Get_Tech() const;
    void                   Set_IL(ID3D11InputLayout* _pInputLayout);

protected:
    virtual HRESULT Init(SHADER_DESC& _pDesc) PURE;

protected:
    // CComponent을(를) 통해 상속됨
    void Free() override;
};

