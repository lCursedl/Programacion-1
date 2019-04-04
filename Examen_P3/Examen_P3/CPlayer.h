#pragma once
#include "CWeapon.h"
#include <iostream>
class CPlayer
{
public:
	int HP;
	int xPos;
	int yPos;
	CWeapon* PlayerWeapon;
	std::string mName;
	CPlayer();
	CPlayer(int PlayerHP, int WeaponID, int WeaponHP);
	~CPlayer();
	void SetPos(int X, int Y);
};