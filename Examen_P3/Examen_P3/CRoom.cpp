#include "CRoom.h"

CRoom::CRoom()
{
	RoomState = ' ';
}

CRoom::~CRoom()
{
	if (mEnemy != nullptr)
	{
		delete mEnemy;
		mEnemy = nullptr;
	}
	if (mWeapon != nullptr)
	{
		delete mWeapon;
		mWeapon = nullptr;
	}
}

CWeapon * CRoom::GiveWeapon()
{
	CWeapon* Temp = mWeapon;
	delete mWeapon;
	mWeapon = nullptr;
	return Temp;
}

void CRoom::UpdateRoom()
{
	if (bDiscovered)
	{
		if (bPlayer)
		{
			RoomState = 'X';
		}
		else if (mEnemy != nullptr)
		{
			RoomState = 'M';
		}
		else if (mWeapon != nullptr)
		{
			RoomState = 'W';
		}
		else if (mExit)
		{
			RoomState = 'E';
		}
		else
		{
			RoomState = '0';
		}
	}
	else
	{
		if (bPlayer)
		{
			RoomState = 'X';
		}
	}
}