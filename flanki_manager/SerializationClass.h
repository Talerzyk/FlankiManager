#pragma once
#include "Team.h"
#include "Career.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <boost/serialization/array.hpp>
#include <sstream>
#include <fstream>

class SerializationClass
{
public:
	static const int SerializeTeam(Team t); //serializes team t and saves it as a <name of team>.bin file. Returns 0 on success
	static const int DeserializeTeam(Team &t, std::string f); //deserializes career c from file specified as an argument to career c. Returns 0 on success
	static const int SerializeCareer(Career c);
	static const int DeserializeCareer(Career &c, std::string f); // serializes career c and saves it as a <name of career>.bin file. Returns 0 on success
};

