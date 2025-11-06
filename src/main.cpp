// platform global variables
static bool running = true;

// platform functions
bool platform_create_window(char* title, int width, int height);

//windows platform implementation
// used if the target platform is windows by checking if windows 32 bit is the current operating system
#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

// windows global variables- adds variables for windows platform 

//windows platform implementations- makes the global function specific to windows platform
bool platform_create_window(char* title, int width, int height) 
{
    // gets the instance of the current module in order to process what is happening in the window
    HINSTANCE instance = GetModuleHandleA(0);

    WNDCLASSA wc = {};
    // sets the window class properties
    wc.hInstance = instance;
    // the icon for the window and the cursor style
    wc.hIcon = LoadIcon(instance, IDI_APPLICATION);
    wc.hCursor = LoadCursor(0, IDC_ARROW);
    wc.lpszClassName = title;// identifier of window not the title
    
    wc.lpfnWndProc = DefWindowProcA; // long funtion pointer to the window proc address // responsible for processing messages sent to the window

    //ALLOW FOR REGISTRATION OF THE WINDOW CLASS AND WINDOW CREATION
    if(!RegisterClassA(&wc)) {
        return false;
    }
    // WINDOWS CREATION DOCCUMENTATION - https://learn.microsoft.com/en-us/windows/win32/api/winuser/nf-winuser-createwindowexa
    int dwStyle = WS_OVERLAPPEDWINDOW;
    HWND window = CreateWindowExA(
        0,
        title,// name from wc.lpszClassName
        title, // window title
        dwStyle, // window style
        100, 100, // starting x and y position
        width, height, // width and height of window
        NULL, 
        NULL, 
        instance, //lpParam
        NULL );
        
   if (window == NULL) {
        return false;
    }
    ShowWindow(window, SW_SHOW);
    return true;
}

#endif



int main () {
    platform_create_window("Platformer Concept Demo", 1920, 1080);
    while (running)
    {
        // game loop code
    }
    return 0;
}