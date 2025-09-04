//***************************************************************************************
// Init Direct3D.cpp by Frank Luna (C) 2011 All Rights Reserved.
//
// Demonstrates the sample framework by initializing Direct3D, clearing 
// the screen, and displaying frame stats.
//
//***************************************************************************************

#include "d3dApp.h"
#include "Define.h"
#include "BoxObject.h"
#include "Camera.h"

_matrix g_ViewMatrix;
_matrix g_ProjMatrix;

class InitDirect3DApp : public D3DApp
{
public:
	InitDirect3DApp(HINSTANCE hInstance);
	~InitDirect3DApp();

	bool Init();
	void OnResize();
	void Pre_UpdateScene(float dt);
	void UpdateScene(float dt);
	void Late_UpdateScene(float dt);
	void DrawScene();

	CBoxObject* m_pBoxObject{ nullptr };
	CCamera*	m_pCamera{ nullptr };
};

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE prevInstance,
				   PSTR cmdLine, int showCmd)
{
	// Enable run-time memory check for debug builds.
#if defined(DEBUG) | defined(_DEBUG)
	_CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );
#endif

	InitDirect3DApp theApp(hInstance);
	
	if( !theApp.Init() )
		return 0;

	return theApp.Run();
}

InitDirect3DApp::InitDirect3DApp(HINSTANCE hInstance)
: D3DApp(hInstance) 
{
}

InitDirect3DApp::~InitDirect3DApp()
{
}

bool InitDirect3DApp::Init()
{
	if(!D3DApp::Init())
		return false;

	m_pBoxObject = CBoxObject::Create(md3dDevice, md3dImmediateContext);
	m_pCamera = CCamera::Create(md3dDevice, md3dImmediateContext);

	return true;
}

void InitDirect3DApp::OnResize()
{
	D3DApp::OnResize();
}

void InitDirect3DApp::Pre_UpdateScene(float dt)
{
	m_pBoxObject->Pre_Update();
}

void InitDirect3DApp::UpdateScene(float dt)
{
	m_pCamera->Update(dt);
	g_ViewMatrix = m_pCamera->Get_View();
	g_ProjMatrix = m_pCamera->Get_Proj();

	if (GetAsyncKeyState(VK_UP)) {
		m_pCamera->Go_Up(dt);
	}
	if (GetAsyncKeyState(VK_DOWN)) {
		m_pCamera->Go_Down(dt);
	}
	if (GetAsyncKeyState(VK_LEFT)) {
		m_pCamera->Go_Left(dt);
	}
	if (GetAsyncKeyState(VK_RIGHT)) {
		m_pCamera->Go_Right(dt);
	}

	if (GetAsyncKeyState('W')) {
		m_pCamera->Move_Up(dt);
	}
	if (GetAsyncKeyState('S')) {
		m_pCamera->Move_Down(dt);
	}
	if (GetAsyncKeyState('A')) {
		m_pCamera->Move_Left(dt);
	}
	if (GetAsyncKeyState('D')) {
		m_pCamera->Move_Right(dt);
	}

	m_pBoxObject->Update(dt);
}

void InitDirect3DApp::Late_UpdateScene(float dt)
{
	m_pBoxObject->Late_Update();
}

void InitDirect3DApp::DrawScene()
{
	md3dImmediateContext->OMSetRenderTargets(1, &mRenderTargetView, mDepthStencilView);
	md3dImmediateContext->OMSetDepthStencilState(m_pDepthStencilState, 1);

	md3dImmediateContext->ClearRenderTargetView(mRenderTargetView, reinterpret_cast<const float*>(&Colors::Blue));
	md3dImmediateContext->ClearDepthStencilView(mDepthStencilView, D3D11_CLEAR_DEPTH|D3D11_CLEAR_STENCIL, 1.0f, 0);
	m_pBoxObject->Render();

	mSwapChain->Present(0, 0);
}