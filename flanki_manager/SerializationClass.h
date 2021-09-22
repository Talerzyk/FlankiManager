#pragma once
#include "Team.h"

class SerializationClass
{
public:
	static const int SerializeTeam(Team t); //serializes team t and saves it as a <name of team>.bin file. Returns 0 on success
	static const int DeserializeTeam(Team &t, std::string f); //deserializes team t from file specified as an argument to team t. Returns 0 on success
};

