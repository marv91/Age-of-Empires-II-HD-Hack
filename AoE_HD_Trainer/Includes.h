#pragma once

#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>

#define KeyDown(x)  GetAsyncKeyState(x) & 0x8000 && GetAsyncKeyState(VK_SHIFT) & 0x8000