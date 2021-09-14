#include "ComparatorClass.h"
#include "Team.h"
#include "Player.h"

bool ComparatorClass::ComparePlayers(Player p1, Player p2)
{
	if (p1.GetFirstName() != p2.GetFirstName())
		return 0;

	if (p1.GetLastName() != p2.GetLastName())
		return 0;

	if (p1.GetAccuracy() != p2.GetAccuracy())
		return 0;

	return 1;
}

int ComparatorClass::FindPlayer(Player p, Team team, int squad)
{
	int index = -1;

	switch (squad)
	{
	case 0: //base team
		for (int i = 0; i < team.GetBase().size(); i++)
		{
			if (ComparePlayers(team.GetBase()[i], p))
				index = i;
		}
		break;

	case 1: //reserve team
		for (int i = 0; i < team.GetReserve().size(); i++)
		{
			if (ComparePlayers(team.GetReserve()[i], p))
				index = i;
		}
		break;
	}

	return index;
}