#if defined(UNICODE) && !defined(_UNICODE)
    #define _UNICODE
#elif defined(_UNICODE) && !defined(UNICODE)
    #define UNICODE
#endif
#include <iostream>
#include <tchar.h>
#include <windows.h>
#include <string>
#include <stdlib.h>
using namespace std;

/*  Declare Windows procedure  */
LRESULT CALLBACK WindowProcedure (HWND, UINT, WPARAM, LPARAM);
HWND TextBox;

/*  Make the class name into a global variable  */
TCHAR szClassName[ ] = _T("CodeBlocksWindowsApp");
char n[6],l[6];

int WINAPI WinMain (HINSTANCE hThisInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR lpszArgument,
                     int nCmdShow)
{
    HWND hwnd;               /* This is the handle for our window */
    MSG messages;            /* Here messages to the application are saved */
    WNDCLASSEX wincl;        /* Data structure for the windowclass */

    /* The Window structure */
    wincl.hInstance = hThisInstance;
    wincl.lpszClassName = szClassName;
    wincl.lpfnWndProc = WindowProcedure;      /* This function is called by windows */
    wincl.style = CS_DBLCLKS;                 /* Catch double-clicks */
    wincl.cbSize = sizeof (WNDCLASSEX);

    /* Use default icon and mouse-pointer */
    wincl.hIcon = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hIconSm = LoadIcon (NULL, IDI_APPLICATION);
    wincl.hCursor = LoadCursor (NULL, IDC_ARROW);
    wincl.lpszMenuName = NULL;                 /* No menu */
    wincl.cbClsExtra = 0;                      /* No extra bytes after the window class */
    wincl.cbWndExtra = 0;                      /* structure or the window instance */
    /* Use Windows's default colour as the background of the window */
    wincl.hbrBackground = (HBRUSH) COLOR_BACKGROUND;

    /* Register the window class, and if it fails quit the program */
    if (!RegisterClassEx (&wincl))
        return 0;

    /* The class is registered, let's create the program*/
    hwnd = CreateWindowEx (
           0,                   /* Extended possibilites for variation */
           szClassName,         /* Classname */
           _T("Code::Blocks Template Windows App"),       /* Title Text */
           WS_OVERLAPPEDWINDOW, /* default window */
           CW_USEDEFAULT,       /* Windows decides the position */
           CW_USEDEFAULT,       /* where the window ends up on the screen */
           544,                 /* The programs width */
           375,                 /* and height in pixels */
           HWND_DESKTOP,        /* The window is a child-window to desktop */
           NULL,                /* No menu */
           hThisInstance,       /* Program Instance handler */
           NULL                 /* No Window Creation data */
           );

    /* Make the window visible on the screen */
    ShowWindow (hwnd, nCmdShow);

    /* Run the message loop. It will run until GetMessage() returns 0 */
    while (GetMessage (&messages, NULL, 0, 0))
    {
        /* Translate virtual-key messages into character messages */
        TranslateMessage(&messages);
        /* Send message to WindowProcedure */
        DispatchMessage(&messages);
    }

    /* The program return-value is 0 - The value that PostQuitMessage() gave */
    return messages.wParam;
}


/*  This function is called by the Windows function DispatchMessage()  */

  int serie(int n)
        {
            unsigned  s=0;
            for(int i=1;i<=n;i++)
            {
                int x;
                cin >> x;
                s+=x;
            }
            return s;
        }
        float paralel(int n)
        {
            float s=0;
            for(int i=1;i<=n;i++)
            {
                float x;
                cin >> x;
                s+=1/x;
            }
            return 1/s;
        }
LRESULT CALLBACK WindowProcedure (HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)                  /* handle the messages */
    {
    case WM_CREATE:
        CreateWindow(TEXT("button"),TEXT("Serie"),WS_VISIBLE | WS_CHILD ,10,10,80,25,hwnd,(HMENU)1,NULL,NULL);
        CreateWindow(TEXT("button"),TEXT("Paralel"),WS_VISIBLE | WS_CHILD ,10,40,80,25,hwnd,(HMENU)2,NULL,NULL);
        break;
    case WM_COMMAND:
        switch(LOWORD(wParam))
        {
            case 1:
{
           TextBox = CreateWindow("EDIT","",WS_VISIBLE | WS_BORDER | WS_CHILD,100,10,80,25,hwnd,NULL,NULL,NULL);
            CreateWindow("button","Salvati",WS_VISIBLE | WS_CHILD,200,10,80,25,hwnd,(HMENU) 3,NULL,NULL);
                break;
}

            case 2:
{
            TextBox = CreateWindow("EDIT","",WS_VISIBLE | WS_BORDER | WS_CHILD,100,40,80,25,hwnd,NULL,NULL,NULL);
            CreateWindow("button","Salvati",WS_VISIBLE | WS_CHILD,200,40,80,25,hwnd,(HMENU) 4,NULL,NULL);
             break;
}
            case 3:
                {
                int GWTstatus = 0;
                GWTstatus=GetWindowText(TextBox,&n[0],6);
                int x=atoi(n);
                cout << "Introduceti rezistentele" << endl;
                int suma=0;
                suma=serie(x);
                cout << "Rezistenta echivalenta in serie este " << suma << endl;
                FreeConsole();
                WM_QUIT;
                    break;
                }
            case 4:
                {
                    int GWTstatus = 0;
                GWTstatus=GetWindowText(TextBox,&n[0],6);
                int x=atoi(n);
                cout << "Introduceti rezistentele" << endl;
                float suma=0;
                suma=paralel(x);
                cout << "Rezistenta echivalenta in paralel este " << suma << endl;
                FreeConsole();
                WM_QUIT;
                    break;
                }
        }
        break;
        case WM_DESTROY:
            PostQuitMessage (0);       /* send a WM_QUIT to the message queue */
            break;
        default:                      /* for messages that we don't deal with */
            return DefWindowProc (hwnd, message, wParam, lParam);
    }

    return 0;
}
