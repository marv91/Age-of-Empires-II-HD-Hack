#pragma once
#include "stdafx.h"
#include "Memory.h"
#include <Windows.h>


using namespace std;

Memory* g_pAOEMemory = new Memory();

auto Memory::Init() -> bool
{
	
	HANDLE processSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(processSnap, &pe32))
	{
		CloseHandle(processSnap);
		return false;
	}

	do {

		if (strcmp(pe32.szExeFile, "AoK HD.exe") == 0) {
						
			m_dwPID = reinterpret_cast<DWORD>(pe32.th32ProcessID);

			MODULEENTRY32 me32;

			me32.dwSize = sizeof(MODULEENTRY32);

			HANDLE hModuleSnap = INVALID_HANDLE_VALUE;

			hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, m_dwPID);

			if (hModuleSnap == INVALID_HANDLE_VALUE)
			{
				return false;
			}

			Module32First(hModuleSnap, &me32);
			do {
				if (strcmp(me32.szModule, "AoK HD.exe") == 0) {
					m_dwBaseAddr = reinterpret_cast<DWORD>(me32.modBaseAddr);
					CloseHandle(hModuleSnap);
				}
			} while (Module32Next(hModuleSnap, &me32));
			
			CloseHandle(processSnap);
			break;
		}

	} while (Process32Next(processSnap, &pe32));

	return true;
}


auto Memory::Read(DWORD dwAddress, LPVOID lpBuffer, DWORD dwSize) -> bool
{
	HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_dwPID);
	SIZE_T temp;
	if (ReadProcessMemory(proc, (LPCVOID)dwAddress, lpBuffer, dwSize, &temp)) {
		CloseHandle(proc);
		return true;
	}
	CloseHandle(proc);
	return false;
}

auto Memory::Write(DWORD dwAddress, LPCVOID lpBuffer, DWORD dwSize) -> bool
{
	HANDLE proc = OpenProcess(PROCESS_ALL_ACCESS, FALSE, m_dwPID);
	if (WriteProcessMemory(proc, (LPCVOID*)dwAddress, lpBuffer, dwSize, NULL)) {
		CloseHandle(proc);
		return true;
	}
	CloseHandle(proc);
	return false;
}

auto Memory::IsRunning() -> bool
{
	return FindWindow(NULL, "Age of Empires II: HD Edition") != NULL;
}
