#pragma once
#include "CEnemy.h"
#include "CWeapon.h"

class CRoom
{
public:
	CEnemy* mEnemy = nullptr;
	CWeapon* mWeapon = nullptr;
	bool mExit = false;
	bool bPlayer = false;
	bool bDiscovered = false;
	char RoomState;
	/*----------------------------------*/
	CRoom();
	~CRoom();

	CWeapon* GiveWeapon();
	void UpdateRoom();
};