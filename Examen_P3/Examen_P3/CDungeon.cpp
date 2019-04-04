#include "CDungeon.h"

CDungeon::CDungeon()
{
	//Seed initialization
	srand(time(NULL));
	//Init of dungeon rooms
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mDungeon[i][j] = new CRoom();
		}
	}
	//Init of player
	mPlayer = new CPlayer(rand() % 25 + 50, rand() % 3, rand() % 31);
	//Init of enemies
	PlaceEnemies(4);
	//Init of weapons
	PlaceWeapons(5);
	//Player placement
	PlacePlayer();
	//Exit placement
	PlaceExit();
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mDungeon[i][j]->UpdateRoom();
		}
	}
}

CDungeon::~CDungeon()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			delete mDungeon[i][j];
		}
	}
	delete mPlayer;
}

//Function to place random enemies on dungeon
void CDungeon::PlaceEnemies(int Max)
{
	int row;
	int col;
	bool Repeat;
	for (int i = 0; i < Max; i++)
	{
		Repeat = true;
		while (Repeat)
		{
			row = rand() % 4;
			col = rand() % 4;
			if (mDungeon[col][row]->mEnemy == nullptr)
			{
				mDungeon[col][row]->mEnemy = new CEnemy(rand() % 5, rand() % 26 + 10);
				Repeat = false;
			}
		}
	}
}
//Function to place random weapons on dungeon
void CDungeon::PlaceWeapons(int Max)
{
	int row;
	int col;
	bool Repeat;
	for (int i = 0; i < Max; i++)
	{
		Repeat = true;
		while (Repeat)
		{
			row = rand() % 4;
			col = rand() % 4;
			if (mDungeon[col][row]->mWeapon == nullptr && mDungeon[col][row]->mEnemy == nullptr)
			{
				mDungeon[col][row]->mWeapon = new CWeapon(rand() % 3, rand() % 31);
				Repeat = false;
			}
		}
	}
}
//Function to place player in random position
void CDungeon::PlacePlayer()
{
	int row;
	int col;
	bool Repeat = true;
	while (Repeat)
	{
		row = rand() % 4;
		col = rand() % 4;
		if (mDungeon[col][row]->mEnemy == nullptr && mDungeon[col][row]->mWeapon == nullptr)
		{
			mPlayer->SetPos(col, row);
			mDungeon[col][row]->bPlayer = true;
			Repeat = false;
		}
	}
}
//Function to place dungeon exit in random position
void CDungeon::PlaceExit()
{
	int row;
	int col;
	bool Repeat = true;
	while (Repeat)
	{
		row = rand() % 4;
		col = rand() % 4;
		if (mDungeon[col][row]->mEnemy == nullptr && mDungeon[col][row]->mWeapon == nullptr && col != mPlayer->yPos && row != mPlayer->xPos)
		{
			mDungeon[col][row]->mExit = true;
			Repeat = false;
		}
	}
}

void CDungeon::Update()
{
	MovePlayer();
	if (mDungeon[mPlayer->yPos][mPlayer->xPos]->mExit)
	{
		std::cout << "Congratulations. You found the exit of the dungeon.\n";
		GameCycle = false;
	}
	else if (mDungeon[mPlayer->yPos][mPlayer->xPos]->mEnemy != nullptr)
	{
		Fight(mDungeon[mPlayer->yPos][mPlayer->xPos]->mEnemy);
	}
	else if (mDungeon[mPlayer->yPos][mPlayer->xPos]->mWeapon != nullptr)
	{
		ChangeWeapon(mDungeon[mPlayer->yPos][mPlayer->xPos]->mWeapon);
	}
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			mDungeon[i][j]->UpdateRoom();
		}
	}
}

void CDungeon::Fight(CEnemy * &Monster)
{
	bool bFight = true;
	std::string Temp;
	int TempHP;
	std::cout << "You encounter a " << Monster->mName << ".\n";
	do
	{
		std::cout << Monster->mName << " has " << Monster->mHP << " health left.\nYou have " << mPlayer->HP << " health left";
		if (mPlayer->PlayerWeapon != nullptr)
		{
			std::cout << " and your " << mPlayer->PlayerWeapon->mName << " has " << mPlayer->PlayerWeapon->mHP << " durability left.\n";
		}
		else
		{
			std::cout << ".\n";
		}
		std::cout << "What will you do?\n\tAttack/Flee\n";
		Temp = InputSelection("ATTACK", "FLEE");
		if (Temp == "ATTACK")
		{
			std::cout << "You attack the " << Monster->mName;
			if (mPlayer->PlayerWeapon != nullptr)
			{
				std::cout << " with your " << mPlayer->PlayerWeapon->mName << ".\n";
				TempHP = Monster->mHP;
				Monster->ReceiveDamage(mPlayer->PlayerWeapon->mHP);
				mPlayer->PlayerWeapon->mHP -= TempHP;
				if (mPlayer->PlayerWeapon->mHP < 0)
				{
					std::cout << "Your weapon breaks!\n";
					delete mPlayer->PlayerWeapon;
					mPlayer->PlayerWeapon = nullptr;
				}
				if (Monster->mHP < 1)
				{
					std::cout << "You defeated the " << Monster ->mName << "!";
					delete Monster;
					Monster = nullptr;
					if (mPlayer->HP < 1)
					{
						std::cout << " But you died whie fighting it...\n";
						bFight = false;
						GameCycle = false;
					}
					else
					{
						std::cout << "\n";
						bFight = false;
					}
				}
				else if (mPlayer->HP < 1)
				{
					std::cout << "You died whie fighting the " << Monster->mName << "...\n";
					bFight = false;
					GameCycle = false;
				}
			}
			else
			{
				std::cout << " with your bare fists.\n";
				TempHP = Monster->mHP;
				Monster->ReceiveDamage(mPlayer->HP);
				mPlayer->HP -= TempHP;
				if (Monster->mHP < 1)
				{
					std::cout << "You defeated the " << Monster->mName << "!";
					delete Monster;
					Monster = nullptr;
					if (mPlayer->HP < 1)
					{
						std::cout << " But you died whie fighting it...\n";
						bFight = false;
						GameCycle = false;
					}
					else
					{
						std::cout << "\n";
						bFight = false;
					}
				}
				else if (mPlayer->HP < 1)
				{
					std::cout << "You died whie fighting the " << Monster->mName << "...\n";
					bFight = false;
					GameCycle = false;
				}
			}
		}
		else
		{
			std::cout << "You try to flee from the " << Monster->mName << ".\n";
			int Chance = rand() % 10 + 1;
			if (Chance < 6)
			{
				std::cout << "The monster manages to hit you while fleeing!\n";
				std::cout << "You receive " << Monster->mHP << " damage.\n";
				mPlayer->HP -= Monster->mHP;
				bFight = false;
			}
			else
			{
				std::cout << "You manage to evade the " << Monster->mName << "'s attack.\n";
				bFight = false;
			}
		}
	} while (bFight);	
}

void CDungeon::ChangeWeapon(CWeapon * &Weapon)
{
	std::cout << "You find a " << Weapon->mName << " on the floor with " << Weapon->mHP << " durability.\n";
	if (mPlayer->PlayerWeapon != nullptr)
	{
		std::cout << "Do you want to change it for your " << mPlayer->PlayerWeapon->mName << " with " << mPlayer->PlayerWeapon->mHP << " durability?(Yes/No)\n";
		std::string Temp = InputSelection("YES", "NO");
		if (Temp == "YES")
		{
			CWeapon* TempWeap = new CWeapon(*mPlayer->PlayerWeapon);
			mPlayer->PlayerWeapon = Weapon;
			Weapon = TempWeap;
			delete TempWeap;
			std::cout << "You change your weapon.\n";
		}
		else
		{
			std::cout << "You keep your weapon.\n";
		}
	}
	else
	{
		std::cout << "You take it as it is better than fighting with your bare hands.\n";
		mPlayer->PlayerWeapon = Weapon;
		Weapon = nullptr;
	}
}

void CDungeon::MovePlayer()
{
	bool Moved = false;
	std::string Input;
	do
	{
		std::cout << "Type the direction you want to go (North, South, East West): ";
		Input = InputDir();
		if (Input == "NORTH")
		{
			if (mPlayer->yPos == 0)
			{
				std::cout << "You can't move further in that direction.\n";
			}
			else
			{
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = false;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bDiscovered = true;
				mPlayer->yPos--;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = true;
				Moved = true;
			}
		}
		else if (Input == "SOUTH")
		{
			if (mPlayer->yPos == 3)
			{
				std::cout << "You can't move further in that direction.\n";
			}
			else
			{
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = false;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bDiscovered = true;
				mPlayer->yPos++;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = true;
				Moved = true;
			}
		}
		else if (Input == "EAST")
		{
			if (mPlayer->xPos == 3)
			{
				std::cout << "You can't move further in that direction.\n";
			}
			else
			{
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = false;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bDiscovered = true;
				mPlayer->xPos++;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = true;
				Moved = true;
			}
		}
		else if (Input == "WEST")
		{
			if (mPlayer->xPos == 0)
			{
				std::cout << "You can't move further in that direction.\n";
			}
			else
			{
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = false;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bDiscovered = true;
				mPlayer->xPos--;
				mDungeon[mPlayer->yPos][mPlayer->xPos]->bPlayer = true;
				Moved = true;
			}
		}
		else if (Input == "ESC")
		{
			Moved = true;
			GameCycle = false;
		}
	} while (!Moved);
}

std::string CDungeon::InputWord()
{
	std::string Temp;
	std::cin >> Temp;
	for (int i = 0; i < Temp.size(); i++)
	{
		if (!isalpha(Temp[i]))
		{
			std::cout << "Invalid input. Please input letters.\n";
			return InputWord();
		}
		Temp[i] = toupper(Temp[i]);
	}
	return Temp;
}

std::string CDungeon::InputDir()
{
	std::string Temp = InputWord();
	if (Temp != NorthDir && Temp != SouthDir && Temp != EastDir && Temp != WestDir && Temp != Esc)
	{
		std::cout << "Invalid input. Please input valid directions.\n";
		return InputDir();
	}
	return Temp;
}

std::string CDungeon::InputSelection(std::string S1, std::string S2)
{
	std::string Temp = InputWord();
	if (Temp != S1 && Temp != S2)
	{
		std::cout << "Invalid decision. Please input a valid one.\n";
		return InputSelection(S1, S2);
	}
	return Temp;
}

void CDungeon::WriteFile()
{
}

void CDungeon::ReadFile()
{
}
