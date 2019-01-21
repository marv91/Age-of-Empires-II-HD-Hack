#include "stdafx.h"
#include "Console.h"

Console* g_pConsole = new Console();

auto Console::Init() -> void
{
	Resize();
	PrintInfo();
}

auto Console::Resize() -> void
{
	system("mode con COLS=70 LINES=20");
}

auto Console::PrintInfo() -> void
{
	cout << green << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	cout << white << "   ___       ____________    __ _____    ______         _\n";
	cout << "  / _ |___  / __/  _/  _/___/ // / _ \\  /_  __/______ _(_)__  ___ ____\n";
	cout << " / __ / _ \\/ _/_/ /_/ //___/ _  / // /   / / / __/ _ `/ / _ \\/ -_) __/\n";
	cout << "/_/ |_\\___/___/___/___/   /_//_/____/   /_/ /_/  \\_,_/_/_//_/\\__/_/ \n\n";
	cout << green << "**********************************************************************\n";
	cout << "**********************************************************************\n";
	cout << white << "shift+F1:" << red << " Wood\n"; 
	cout << white << "shift+F2:" << red << " Food\n";
	cout << white << "shift+F2:" << red << " Gold\n";
	cout << white << "shift+F2:" << red << " Stone";
}
