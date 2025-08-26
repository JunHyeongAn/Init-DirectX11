#pragma once
#include "d3dUtil.h"

class CVIBuffer abstract
{
protected:
	CVIBuffer();
	CVIBuffer(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	virtual ~CVIBuffer();

protected:
	ID3D11Device*			m_pDevice{ nullptr };
	ID3D11DeviceContext*	m_pContext{ nullptr };

	ID3D11Buffer*			m_pVB{ nullptr };
	ID3D11Buffer*			m_pIB{ nullptr };

	int						m_iVertexNum{};
	UINT					m_iVertexStride{};

	UINT					m_iIndexNum{};

protected:
	virtual HRESULT Init() = 0;
	virtual void Bind() = 0;
	virtual void Render() = 0;
	virtual void Free();
};

