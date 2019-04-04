#pragma once
#include "CRoom.h"
#include "CPlayer.h"
#include <stdlib.h>
#include <time.h>

class CDungeon
{
public:
	//Pointer to 2D array consisting of rooms
	CRoom* mDungeon[4][4];
	//Pointer to player
	CPlayer* mPlayer;
	//Variable for game cycle
	bool GameCycle = true;
	//Strings for comparison
	std::string NorthDir = "NORTH";
	std::string SouthDir = "SOUTH";
	std::string EastDir = "EAST";
	std::string WestDir = "WEST";
	std::string Esc = "ESC";
	/*--------------------------------------*/
	CDungeon();
	~CDungeon();
	//Class functions
	void PlaceEnemies(int Max);
	void PlaceWeapons(int Max);
	void PlacePlayer();
	void PlaceExit();
	void Update();
	void Fight(CEnemy* &Monster);
	void ChangeWeapon(CWeapon* &Weapon);
	void MovePlayer();
	std::string InputWord();
	std::string InputDir();
	std::string InputSelection(std::string S1, std::string S2);
	void WriteFile();
	void ReadFile();
};