#pragma once
#include "Player.h"
#include <vector>
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <sstream>

class Team
{
public:
	template <typename Archieve>
	void serialize(Archieve& ar, unsigned int version)
	{
		ar & name;
		ar & base;
		ar & reserve;
	}

	Team();
	Team(Player p1, Player p2, Player p3, Player p4, Player p5);

	int AddPlayer(Player p, int squad); //adds player to the chosen team. Outputs: 0 - team is full, 1 - success, squad: 0 - base, 1 - reserve
	int RemovePlayer(Player p, int squad); //removes player from the chosen team. Outputs: 0 - team is empty, 1 - success, squad: 0 - base, 1 - reserve

	void SetName(std::string n);
	std::string GetName();
	std::vector<Player>& GetBase();
	std::vector<Player>& GetReserve();

	std::string Print(int squad); //returns printable data of the whole team. Squad: 0 - base, 1 - reserve

private:

	std::string name;
	std::vector<Player> base;
	std::vector<Player> reserve;
	const static unsigned long int teamSize = 5;
};

