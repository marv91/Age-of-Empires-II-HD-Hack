#pragma once
#include "Includes.h"
#include "ConsoleColor.h"

using namespace std;

class Console
{
public:
	Console() = default;
	~Console() = default;

	auto Init() -> void;

private:

	auto Resize()		-> void;
	auto PrintInfo()	-> void;
};

extern Console* g_pConsole;