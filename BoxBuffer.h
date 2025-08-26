#pragma once
#include "VIBuffer.h"

class CBoxBuffer final : public CVIBuffer
{
private:
	CBoxBuffer() = default;
	CBoxBuffer(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	~CBoxBuffer();

public:
	// CVIBuffer��(��) ���� ��ӵ�
	static CBoxBuffer* Create(ID3D11Device* _pDevice, ID3D11DeviceContext* _pContext);
	HRESULT Init() override;
	void Bind() override;
	void Render() override;
	void Free() override;
};

