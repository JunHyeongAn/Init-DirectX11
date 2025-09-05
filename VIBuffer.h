#pragma once
#include "d3dUtil.h"
#include "Component.h"

namespace Layout {
	static const _inputDesc PosColor[] = {
		{ "POSITION", 0, _inputFloat3, 0, 0,  D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR",    0, _inputFloat4, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	static const _uint PosColorCnt = _countof(PosColor);

	static const _inputDesc PosTexture1[] = {
		{ "POSITION", 0, _inputFloat3, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "TEXCOORD", 0, _inputFloat3, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
	};

	static const _uint PosTextureCnt = _countof(PosTexture1);
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
	// CComponent��(��) ���� ��ӵ�
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

