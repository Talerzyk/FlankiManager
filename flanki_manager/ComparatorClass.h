#pragma once
#include "Team.h"
#include "Player.h"

class ComparatorClass
{
public:
	static const bool ComparePlayers(Player p1, Player p2);
	static const int FindPlayer(Player p, Team team, int squad); //int squad 0 - base, 1 - reserve
};
