#pragma once
#include "d3dUtil.h"
#include "Component.h"

namespace Layout {
	static const D3D11_INPUT_ELEMENT_DESC PosColor[] = {
		{"POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0},
		{"COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0},
	};

	static const _uint PosColorCnt = _countof(PosColor);
}

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

	const D3D11_INPUT_ELEMENT_DESC* 
							m_tDesces{ nullptr };
	_uint					m_iDescCnt{};
	D3D11_PRIMITIVE_TOPOLOGY m_eTopology{};

protected:
	// CComponent을(를) 통해 상속됨
	void Free() override;

public:
	virtual HRESULT Init() PURE;
	virtual void Bind() PURE;
	virtual void Render() PURE;

	const D3D11_INPUT_ELEMENT_DESC* Get_Desc() const {
		return m_tDesces;
	}

	_uint Get_DescCnt() const {
		return m_iDescCnt;
	}

	D3D11_PRIMITIVE_TOPOLOGY Get_Topology() const {
		return m_eTopology;
	}
};

