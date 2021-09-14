#pragma once
#include "ComparatorClass.h"
#include "Player.h"
#include "Team.h"
#include "Can.h"

class Match
{
public:
	Match(Team t1, Team t2, Can c, int dist);

	Team& GetA();
	Team& GetB();
	Can& GetCan();
	int GetDistance();

	int Play(); //the function of playing game, handle with care
	int CoinFlip(); //coin flip for picking team. 0 - t1, 1 - t2
	std::string Print();

private:
	Team b;
	Team a;
	Can can;
	int distance;
};

