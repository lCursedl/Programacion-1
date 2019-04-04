#include "CWeapon.h"

CWeapon::CWeapon(){}

CWeapon::CWeapon(int ID, int HP)
{
	mID = ID;
	mHP = HP;
	if (ID == 0)
	{
		mName = "Sword";
	}
	else if (ID == 1)
	{
		mName = "Mace";
	}
	else if (ID == 2)
	{
		mName = "Lance";
	}
}

CWeapon::~CWeapon()
{
}

void CWeapon::Set(int ID, int HP)
{
	mID = ID;
	mHP = HP;
	if (ID == 0)
	{
		mName = "Sword";
	}
	else if (ID == 1)
	{
		mName = "Mace";
	}
	else if (ID == 2)
	{
		mName = "Lance";
	}
}