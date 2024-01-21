#include <windows.h>
#include <string>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    LPCWSTR url = L"microsoft-edge:///?ux=copilot&tcp=1&source=taskbar";
    HINSTANCE result = ShellExecute(NULL, L"open", url, NULL, NULL, SW_SHOWNORMAL);

    if ((int)result <= 32) {
        std::wstring errorMessage = L"Failed to open URL. Error: " + std::to_wstring((int)result);
        MessageBox(NULL, errorMessage.c_str(), L"Error", MB_ICONERROR | MB_OK);
    }

    return 0;
}