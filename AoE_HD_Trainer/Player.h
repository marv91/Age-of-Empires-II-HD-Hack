#pragma once
#include "Memory.h"
#include "Offsets.h"

class Player
{
public:
	
	Player()	= default;
	~Player()	= default;

	auto AddFood()	->bool;
	auto AddGold()	->bool;
	auto AddStone()	->bool;
	auto AddWood()	->bool;

	auto GetPointer() -> bool;
	auto GetRessourcePointer() -> bool;

	const float m_flIncrement = 100.f;

	uintptr_t m_pRessource	= 0;
	uintptr_t m_pPlayer		= 0;

};

extern Player* g_pPlayer;

