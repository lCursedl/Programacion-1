#include "CEnemy.h"

CEnemy::CEnemy(){}

CEnemy::CEnemy(int ID, int HP)
{
	mID = ID;
	mHP = HP;
	if (mID == SQUELETON)
	{
		mName = "Squeleton";
	}
	else if (mID == MAGE)
	{
		mName = "Mage";
	}
	else if (mID == ORC)
	{
		mName = "Orc";
	}
	else if (mID == SPIDER)
	{
		mName = "Spider";
	}
	else if (mID == SLIME)
	{
		mName = "Slime";
	}
}

CEnemy::~CEnemy()
{
}

void CEnemy::ReceiveDamage(int Damage)
{
	mHP -= Damage;
}

void CEnemy::Set(int ID, int HP)
{
	mID = ID;
	mHP = HP;
	if (mID == SQUELETON)
	{
		mName = "Squeleton";
	}
	else if (mID == MAGE)
	{
		mName = "Mage";
	}
	else if (mID == ORC)
	{
		mName = "Orc";
	}
	else if (mID == SPIDER)
	{
		mName = "Spider";
	}
	else if (mID == SLIME)
	{
		mName = "Slime";
	}
}