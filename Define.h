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

typedef struct VertexPosColor {
	XMFLOAT3 Pos;
	XMFLOAT4 Color;
} VTX_POS_COLOR;

#define MSG_BOX(str) MessageBox(0, L##str, 0, 0);

#define	ENUM_CLASS(ENUM) static_cast<unsigned int>(ENUM)

#include "Macro.h"
#include "Enums.h"