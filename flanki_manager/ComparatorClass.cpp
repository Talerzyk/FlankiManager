#include "ComparatorClass.h"
#include "Team.h"
#include "Player.h"

const bool ComparatorClass::ComparePlayers(Player p1, Player p2)
{
	if (p1.GetFirstName() != p2.GetFirstName())
		return 0;

	if (p1.GetLastName() != p2.GetLastName())
		return 0;

	if (p1.GetAccuracy() != p2.GetAccuracy())
		return 0;

	return 1;
}

const int ComparatorClass::FindPlayer(Player p, Team team, int squad)
{
	int index = -1;

	for (int i = 0; i < team.GetTeam(squad).size(); i++)
	{
		if (ComparePlayers(team.GetTeam(squad)[i], p))
			return i;
	}
}