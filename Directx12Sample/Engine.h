#pragma once

#include <string>
#include <cinttypes>

// DirectX
#include <d3d12.h>
#include <dxgi1_6.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

// Microsoft
#include <wrl.h>



class Engine
{
public:
	Engine(uint16_t width, uint16_t height, std::string title);
	~Engine();


private:
	// DirectX 12 variables
	Microsoft::WRL::ComPtr<IDXGIFactory4> m_factory;

};

