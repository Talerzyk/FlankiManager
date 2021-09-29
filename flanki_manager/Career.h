#pragma once
#include "Match.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/array.hpp>
#include <sstream>
#include <fstream>

class Career
{
public:
	template <typename Archieve>
	void serialize(Archieve& ar, unsigned int version)
	{
		ar & name;
		ar & myTeam;
		ar & matchHistory;
	}

	Career();

	int AddToHistory(const int &result, Team opTeam);

	std::string GetName();
	void SetName(const std::string &n);
	Team & GetMyTeam();
	void SetMyTeam(const Team &t);
	std::vector<std::vector<std::string>> & GetMatchHistory();
	std::string PrintMatchHistory();

private:
	std::string name; //career name (manager name)
	Team myTeam;
	std::vector< std::vector<std::string>> matchHistory; //match history: [0] - win/lose, [1] - date, [2] - opponent
};

