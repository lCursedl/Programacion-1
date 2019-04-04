#include "CPlayer.h"

CPlayer::CPlayer(){}

CPlayer::CPlayer(int PlayerHP, int WeaponID, int WeaponHP)
{
	std::cout << "Input your player name: ";
	std::cin >> mName;
	HP = PlayerHP;
	PlayerWeapon = new CWeapon(WeaponID, WeaponHP);
}

CPlayer::~CPlayer()
{
	if (PlayerWeapon != nullptr)
	{
		delete PlayerWeapon;
		PlayerWeapon = nullptr;
	}
}

void CPlayer::SetPos(int Y, int X)
{
	xPos = X;
	yPos = Y;
}