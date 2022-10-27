#include "ConsoleUtils.h"

bool ReconnectIO(bool OpenNewConsole)
{
    int hConHandle;
    long lStdHandle;
    FILE* fp;
    bool MadeConsole;

    MadeConsole = false;
    if (!AttachConsole(ATTACH_PARENT_PROCESS))
    {
        if (!OpenNewConsole)
            return false;

        MadeConsole = true;
        if (!AllocConsole())
            return false;   // Could throw here
    }

    // STDOUT to the console
    lStdHandle = (long)GetStdHandle(STD_OUTPUT_HANDLE);
    hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    fp = _fdopen(hConHandle, "w");
    *stdout = *fp;
    setvbuf(stdout, NULL, _IONBF, 0);

    // STDIN to the console
    lStdHandle = (long)GetStdHandle(STD_INPUT_HANDLE);
    hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    fp = _fdopen(hConHandle, "r");
    *stdin = *fp;
    setvbuf(stdin, NULL, _IONBF, 0);

    // STDERR to the console
    lStdHandle = (long)GetStdHandle(STD_ERROR_HANDLE);
    hConHandle = _open_osfhandle(lStdHandle, _O_TEXT);
    fp = _fdopen(hConHandle, "w");
    *stderr = *fp;
    setvbuf(stderr, NULL, _IONBF, 0);

    // C++ streams to console
    std::ios_base::sync_with_stdio();
    freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
    freopen_s((FILE**)stdin, "CONIN$", "r", stdin);

    return MadeConsole;
}
