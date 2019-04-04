#pragma once
#include <string>

enum WEAPON_ID
{
	SWORD = 0,
	MACE,
	SPEAR
};

class CWeapon
{
public:
	int mID;
	int mHP;
	std::string mName;
	CWeapon();
	CWeapon(int ID, int HP);
	~CWeapon();
	void Set(int ID, int HP);
};