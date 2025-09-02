#pragma once
#include "d3dx11Effect.h"
#include <DirectXMath.h>
#include <d3dcompiler.h>
#include <map>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>

using namespace DirectX;
using namespace std;

#include "Macro.h"

typedef struct VertexPosColor {
	_float3 vPos;
	_float4 vColor;
} VTX_POS_COLOR;

#define MSG_BOX(str) MessageBox(0, L##str, 0, 0);

#define	ENUM_CLASS(ENUM) static_cast<unsigned int>(ENUM)

#include "Enums.h"