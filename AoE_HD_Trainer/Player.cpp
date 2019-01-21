#include "stdafx.h"
#include "Player.h"

Player* g_pPlayer = new Player();

auto Player::GetPointer() -> bool
{
	return g_pAOEMemory->Read(g_pAOEMemory->m_dwBaseAddr + O::pPlayer, &m_pPlayer, 0x4);
}

auto Player::GetRessourcePointer() -> bool
{

	// ESI register holds class ptr

	// mov ecx, [esi+0x134]
	// add ebx, 0x4
	// push 00
	// mov ecx, [ecx+3C]

	GetPointer();

	uintptr_t dwECX;

	if (!g_pAOEMemory->Read(m_pPlayer + 0x134, &dwECX, 0x4))
		return false;

	if (!g_pAOEMemory->Read(dwECX + 0x3C, &dwECX, 0x4))
		return false;

	m_pRessource = dwECX;

}

auto Player::AddFood() -> bool
{
	GetRessourcePointer();
	
	float flCurrentFood;

	if (!g_pAOEMemory->Read(m_pRessource + O::flFood, &flCurrentFood, 0x4))
		return false;

	float flNewFood = flCurrentFood + m_flIncrement;

	if (!g_pAOEMemory->Write(m_pRessource + O::flFood, &flNewFood, 0x4))
		return false;

	return true;
}

auto Player::AddStone() -> bool
{
	GetRessourcePointer();

	float flCurrentStone;

	if (!g_pAOEMemory->Read(m_pRessource + O::flStone, &flCurrentStone, 0x4))
		return false;

	float flNewStone = flCurrentStone + m_flIncrement;

	if (!g_pAOEMemory->Write(m_pRessource + O::flStone, &flNewStone, 0x4))
		return false;

	return true;
}

auto Player::AddGold() -> bool
{
	GetRessourcePointer();

	float flCurrentGold;

	if (!g_pAOEMemory->Read(m_pRessource + O::flGold, &flCurrentGold, 0x4))
		return false;

	float flNewGold = flCurrentGold + m_flIncrement;

	if (!g_pAOEMemory->Write(m_pRessource + O::flGold, &flNewGold, 0x4))
		return false;

	return true;
}

auto Player::AddWood() -> bool
{
	GetRessourcePointer();

	float flCurrentWood;

	if (!g_pAOEMemory->Read(m_pRessource + O::flWood, &flCurrentWood, 0x4))
		return false;

	float flNewWood = flCurrentWood + m_flIncrement;

	if (!g_pAOEMemory->Write(m_pRessource + O::flWood, &flNewWood, 0x4))
		return false;

	return true;
}


