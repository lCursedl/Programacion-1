#include "CDungeon.h"
#include <stdlib.h>

std::ostream & operator << (std::ostream &os, const CDungeon &c)
{
	os << "HP: " << c.mPlayer->HP;
	if (c.mPlayer->PlayerWeapon != nullptr)
	{
		os << "\tWeapon: " << c.mPlayer->PlayerWeapon->mName << ". Durability: " << c.mPlayer->PlayerWeapon->mHP << ".";
	}
	os << "\n";
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			os << "[" << c.mDungeon[i][j]->RoomState << "]";
		}
		os << "\n";
	}
	return os;
}

int main()
{
	//Pointer of CDungeon to run the game
	CDungeon* MyDungeon = new CDungeon();
	std::cout << "Your name is " << MyDungeon->mPlayer->mName << " and you are trapped inside a dungeon.\nYou must find your way out while fighting against other monsters.\n";
	std::cout << "You are armed with a " << MyDungeon->mPlayer->PlayerWeapon->mName << " with " << MyDungeon->mPlayer->PlayerWeapon->mHP << " uses.\n";
	std::cout << "You have " << MyDungeon->mPlayer->HP << " health.\n";
	std::cin.ignore();
	std::cin.get();
	while (MyDungeon->GameCycle)
	{
		std::cout << *MyDungeon;
		MyDungeon->Update();
		std::cin.ignore();
		std::cin.get();
		system("cls");
	}
	delete MyDungeon;
	return 0;
}