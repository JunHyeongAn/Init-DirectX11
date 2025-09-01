#include "VIBuffer.h"

CVIBuffer::CVIBuffer(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: CComponent(_pDevice, _pContext)
{
}

CVIBuffer::CVIBuffer(CVIBuffer& _pPrototype)
	: CComponent(_pPrototype)
	, m_pVB(_pPrototype.m_pVB)
	, m_pIB(_pPrototype.m_pIB)
	, m_iVertexNum(_pPrototype.m_iVertexNum)
	, m_iVertexStride(_pPrototype.m_iVertexStride)
	, m_iIndexNum(_pPrototype.m_iIndexNum)
{
	m_pVB->AddRef();
	m_pIB->AddRef();
}

void CVIBuffer::Free()
{
	__super::Free();
	m_pVB->Release();
	m_pIB->Release();
}
