#pragma once
#include "ComparatorClass.h"
#include "Player.h"
#include "Team.h"
#include "Can.h"

class Match
{
public:
	Match(const Team &t1, const Team &t2, const int &dist);

	Team& GetA();
	Team& GetB();
	Can& GetCan();
	int GetDistance();

	int Play(); //the function of playing game, handle with care. Returns team that won (0 - player, 1 - AI)
	int CoinFlip(); //coin flip for picking team. 0 - t1, 1 - t2
	std::string Print();

private:
	Team teams[2]; //[0] - player's team, [1] - AI team
	Can can;
	int distance;
};

