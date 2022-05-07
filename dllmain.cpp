// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

DWORD WINAPI MessageBoxThread(LPVOID lpParam) //Create a thread
{
    MessageBox(0, "Dll Injected", "Hello World", MB_OK);
    return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH: //when dll attatches to the process run here
        CreateThread(0, 0, MessageBoxThread, 0, 0, 0); //Create our thread and pass MessageBox thread
        break;
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
