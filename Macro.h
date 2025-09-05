#pragma once

typedef unsigned int		_uint;
typedef float				_float;
typedef bool				_bool;
typedef wchar_t				_tchar;

// 저장용
typedef XMFLOAT4X4			_float4x4;
typedef XMFLOAT3			_float3;
typedef XMFLOAT4			_float4;

// 연산용
typedef XMMATRIX			_matrix;
typedef XMVECTOR			_vector;
typedef FXMVECTOR			_fvector;

// 셰이더용
typedef ID3DX11EffectMatrixVariable*	_lpEffectMatrix;
typedef D3D11_INPUT_ELEMENT_DESC		_inputDesc;

#define PURE = 0
#define _inputFloat3 DXGI_FORMAT_R32G32B32_FLOAT
#define _inputFloat4 DXGI_FORMAT_R32G32B32A32_FLOAT

#define TEXTURE_FILE_PATH TEXT("../Resource/Texture/")