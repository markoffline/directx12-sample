#include "EngineUtils.h"

#include <stdexcept>
#include <string>

void ThrowIfFailed(HRESULT hr)
{
    if (FAILED(hr))
    {
        throw std::runtime_error("HRESULT: " + std::to_string(hr));
    }
}