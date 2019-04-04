#pragma once
#include <string>

enum ENEMY_ID
{
	SQUELETON = 0,
	MAGE,
	ORC,
	SPIDER,
	SLIME
};

class CEnemy
{
public:
	int mID;
	int mHP;
	std::string mName;
	CEnemy();
	CEnemy(int ID, int HP);
	~CEnemy();
	void ReceiveDamage(int Damage);
	void Set(int ID, int HP);
};