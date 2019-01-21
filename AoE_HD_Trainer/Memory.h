#pragma once
#include "Includes.h"

class Memory
{

public:

	Memory() = default;
	~Memory() = default;

	auto Init() -> bool;
	auto IsRunning() -> bool;

	auto Write(DWORD dwAddress, LPCVOID lpBuffer, DWORD dwSize) -> bool;
	auto Read(DWORD dwAddress, LPVOID lpBuffer, DWORD dwSize) -> bool;
	

	DWORD m_dwPID;
	DWORD m_dwBaseAddr;
	
};

extern Memory* g_pAOEMemory;



