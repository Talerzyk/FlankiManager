#include "Team.h"
#include "ComparatorClass.h"
#include <vector>
#include <algorithm>

Team::Team()
{
	for (int i = 0; i < teamSize; i++)
	{
		Player p;
		AddPlayer(p, 0);
	}
	
	for (int i = 0; i < teamSize; i++)
	{
		Player p;
		AddPlayer(p, 1);
	}

	name = "sample_team";
}

Team::Team(Player p1, Player p2, Player p3, Player p4, Player p5)
{
	AddPlayer(p1, 0);
	AddPlayer(p2, 0);
	AddPlayer(p3, 0);
	AddPlayer(p4, 0);
	AddPlayer(p5, 0);
}

void Team::SetName(std::string n)
{
	name = n;
}

std::string Team::GetName()
{
	return name;
}


std::vector<Player>& Team::GetBase()
{
	return base;
}

std::vector<Player>& Team::GetReserve()
{
	return reserve;
}

int Team::AddPlayer(Player p, int squad)
{
	int success = 0;
	switch (squad)
	{
	case 0: //base team
		if (base.size() < teamSize)
		{
			base.push_back(p);
			success = 1;
		}
		break;

	case 1: //reserve team
		if (reserve.size() < teamSize)
		{
			reserve.push_back(p);
			success = 1;
		}
		break;
	}

	return success;
}

int Team::RemovePlayer(Player p, int squad)
{
	int success = 0;

	switch (squad)
	{
	case 0: //base team
		if (!base.empty())
		{
			std::vector<Player>::iterator i = base.begin() + ComparatorClass::FindPlayer(p, *this, 0);
			base.erase(i);
			success = 1;
		}
		break;
		
	case 1: //reserve team
		if (reserve.empty())
		{
			std::vector<Player>::iterator i = reserve.begin() + ComparatorClass::FindPlayer(p, *this, 1);
			reserve.erase(i);
			success = 1;
		}
		break;
	}

	return success;
}

std::string Team::Print(int squad)
{
	std::string data;

	data += name + "\n\n";

	switch (squad)
	{
	case 0: //base team
		for (int i = 0; i < base.size(); i++)
		{
			data += base[i].Print() + "\n";
		}
		break;

	case 1: //reserve team
		for (int i = 0; i < reserve.size(); i++)
		{
			data += reserve[i].Print() + "\n";
		}
		break;
	}

	return data;
}