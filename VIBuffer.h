#pragma once
#include "d3dUtil.h"
#include "Component.h"

class CVIBuffer :public CComponent
{
protected:
	CVIBuffer(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	CVIBuffer(CVIBuffer& _pPrototype);
	virtual ~CVIBuffer() = default;

protected:

	ID3D11Buffer*			m_pVB{ nullptr };
	ID3D11Buffer*			m_pIB{ nullptr };

	int						m_iVertexNum{};
	UINT					m_iVertexStride{};

	UINT					m_iIndexNum{};

protected:
	// CComponent��(��) ���� ��ӵ�
	void Free() override;

public:
	virtual HRESULT Init() PURE;
	virtual void Bind() PURE;
	virtual void Render() PURE;
};

