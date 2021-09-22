#pragma once
#include "Player.h"
#include <vector>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/array.hpp>
#include <sstream>

class Team
{
public:
	template <typename Archieve>
	void serialize(Archieve& ar, unsigned int version)
	{
		ar & name;
		ar & t;
	}

	Team();
	Team(Player p1, Player p2, Player p3, Player p4, Player p5);

	int AddPlayer(Player p, int squad); //adds player to the chosen team. Outputs: 1 - team is full, 0 - success. Squad: 0 - base, 1 - reserve
	int RemovePlayer(Player p, int squad); //removes player from the chosen team. Outputs: 1 - team is empty, 0 - success. Squad: 0 - base, 1 - reserve

	void SetName(std::string n);
	std::string GetName();
	std::vector<Player>& GetTeam(int squad);
	std::vector<std::string> GetTeamMenu(int squad); //returns vector needed for menu displaying. squad: 0 - base, 1 - reserve

	std::string Print(int squad); //returns printable data of the whole team. Squad: 0 - base, 1 - reserve

	const static unsigned long int teamSize = 5;
private:
	std::string name;
	std::vector<Player> t[2]; //array of 2 teams. 0 - base team, 1 - reserve team
};

