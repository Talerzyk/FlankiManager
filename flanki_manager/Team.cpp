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


std::vector<Player>& Team::GetTeam(int squad)
{
	return t[squad];
}

std::vector<std::string> Team::GetTeamMenu(int squad)
{
	std::vector<std::string> data;
	
	for (int i = 0; i < t[squad].size(); i++)
		data.push_back(t[squad][i].Print());
		
	data.push_back("Back");
	return data;
}

int Team::AddPlayer(Player p, int squad)
{
	if (t[squad].size() < teamSize)
	{
		t[squad].push_back(p);
		return 0;
	}

	return 1;
}

int Team::RemovePlayer(Player p, int squad)
{
	if (!t[squad].empty())
	{
		std::vector<Player>::iterator i = t[squad].begin() + ComparatorClass::FindPlayer(p, *this, 0);
		t[squad].erase(i);
		return 0;
	}

	return 1;
}

std::string Team::Print(int squad)
{
	std::string data;

	data += "Team " + name + "\n\n";
	for (int i = 0; i < t[squad].size(); i++)
	{
		data += t[squad][i].Print() + "\n";
	}

	return data;
}