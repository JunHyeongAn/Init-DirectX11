#include "VIBuffer.h"

CVIBuffer::CVIBuffer()
{
}

CVIBuffer::CVIBuffer(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	: m_pDevice(_pDevice)
	, m_pContext(_pContext)
{
}

CVIBuffer::~CVIBuffer()
{
}

void CVIBuffer::Free()
{
	ReleaseCOM(m_pDevice);
	ReleaseCOM(m_pContext);
	ReleaseCOM(m_pVB);
	ReleaseCOM(m_pIB);
}
