#include "BoxBuffer.h"
#include "Define.h"

CBoxBuffer::CBoxBuffer(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
	:CVIBuffer(_pDevice, _pContext)
{
}

CBoxBuffer::~CBoxBuffer()
{
	Free();
}

CBoxBuffer* CBoxBuffer::Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext)
{
	CBoxBuffer* pBoxBuffer = new CBoxBuffer(_pDevice, _pContext);

	if (FAILED(pBoxBuffer->Init())) {
		return nullptr;
	}

	return pBoxBuffer;
}

HRESULT CBoxBuffer::Init()
{
	HRESULT hr{};

	m_iVertexNum				= 8;
	m_iVertexStride				= sizeof(VTX_POS_COLOR);

#pragma region VERTEX
	VTX_POS_COLOR vertices[] = {
		{
			XMFLOAT3(-1.f, -1.f, -1.f)
			, XMFLOAT4(Colors::White.f[0], Colors::White.f[1], Colors::White.f[2], Colors::White.f[3])
		},
		{
			XMFLOAT3(-1.f, +1.f, -1.f)
			, XMFLOAT4(Colors::Black.f[0], Colors::Black.f[1], Colors::Black.f[2], Colors::Black.f[3])
		},
		{
			XMFLOAT3(+1.f, +1.f, -1.f)
			, XMFLOAT4(Colors::Red.f[0], Colors::Red.f[1], Colors::Red.f[2], Colors::Red.f[3])
		},
		{
			XMFLOAT3(+1.f, -1.f, -1.f)
			, XMFLOAT4(Colors::Green.f[0], Colors::Green.f[1], Colors::Green.f[2], Colors::Green.f[3])
		},
		{
			XMFLOAT3(-1.f, -1.f, +1.f)
			, XMFLOAT4(Colors::Blue.f[0], Colors::Blue.f[1], Colors::Blue.f[2], Colors::Blue.f[3])
		},
		{
			XMFLOAT3(-1.f, +1.f, +1.f)
			, XMFLOAT4(Colors::Yellow.f[0], Colors::Yellow.f[1], Colors::Yellow.f[2], Colors::Yellow.f[3])
		},
		{
			XMFLOAT3(+1.f, +1.f, +1.f)
			, XMFLOAT4(Colors::Cyan.f[0], Colors::Cyan.f[1], Colors::Cyan.f[2], Colors::Cyan.f[3])
		},
		{
			XMFLOAT3(+1.f, -1.f, +1.f)
			, XMFLOAT4(Colors::Magenta.f[0], Colors::Magenta.f[1], Colors::Magenta.f[2], Colors::Magenta.f[3])
		},
	};

	D3D11_BUFFER_DESC bufferDesc{};
	bufferDesc.ByteWidth = m_iVertexNum * m_iVertexStride;
	bufferDesc.Usage = D3D11_USAGE_IMMUTABLE;
	bufferDesc.BindFlags = D3D11_BIND_VERTEX_BUFFER;
	bufferDesc.CPUAccessFlags = 0;
	bufferDesc.MiscFlags = 0;
	bufferDesc.StructureByteStride = m_iVertexStride;

	D3D11_SUBRESOURCE_DATA resData{};
	resData.pSysMem = vertices;

	hr = m_pDevice->CreateBuffer(
		&bufferDesc
		, &resData
		, &m_pVB
	);

	if (FAILED(hr)) return E_FAIL;
#pragma endregion

#pragma region INDEX
	m_iIndexNum = 24;

	UINT indecies[] = {
		0,1,2,
		0,2,3,
		0,3,4,
		0,4,5,
		0,5,6,
		0,6,7,
		0,7,8,
		0,8,1
	};

	D3D11_BUFFER_DESC indexDesc{};
	indexDesc.ByteWidth = sizeof(UINT) * m_iIndexNum;
	indexDesc.Usage = D3D11_USAGE_IMMUTABLE;
	indexDesc.BindFlags = D3D11_BIND_INDEX_BUFFER;
	indexDesc.CPUAccessFlags = 0;
	indexDesc.MiscFlags = 0;
	indexDesc.StructureByteStride = 2;

	D3D11_SUBRESOURCE_DATA indexData{};
	indexData.pSysMem = indecies;

	hr = m_pDevice->CreateBuffer(
		&indexDesc,
		&indexData,
		&m_pIB
	);

	if (FAILED(hr)) {
		return E_FAIL;
	}

#pragma endregion

	return S_OK;
}

void CBoxBuffer::Bind()
{
	m_pContext->IASetVertexBuffers(
		0,
		1,
		&m_pVB,
		&m_iVertexStride,
		0
	);

	m_pContext->IASetIndexBuffer(
		m_pIB, DXGI_FORMAT_R32_UINT, 0
	);
}

void CBoxBuffer::Render()
{
}


void CBoxBuffer::Free()
{
	__super::Free();
}