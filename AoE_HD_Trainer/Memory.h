#pragma once
#include "Includes.h"

class Memory
{

public:

	Memory() = default;
	~Memory() = default;

	bool Init();
	bool Write(DWORD dwAddress, LPCVOID lpBuffer, DWORD dwSize);
	bool Read(DWORD dwAddress, LPVOID lpBuffer, DWORD dwSize);
	bool IsRunning();

	DWORD m_dwPID;
	DWORD m_dwBaseAddr;
	
};

extern Memory* g_pAOEMemory;



