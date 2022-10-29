#include <iostream>
#include <Windows.h>
#include <string>

#include "Engine.h"
#include "ConsoleUtils.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR, int nCmdShow)
{
    // Create or connect to console if debugging=
#ifndef NDEBUG
    ReconnectIO(true);
#endif
    
    std::cout << "Hello, World!" << std::endl;
    
    Engine(800, 600, "Sample by Mark's Offline");

    return 0;
}