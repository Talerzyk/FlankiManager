#include "SerializationClass.h"
#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <sstream>
#include <fstream>
#include <iostream>


const int SerializationClass::SerializeTeam(Team t)
{
	if (t.GetName().empty())
		return 1;
	std::ofstream outputStream;
	outputStream.open("./Teams/" + t.GetName() + ".bin");
	boost::archive::binary_oarchive outputArchive(outputStream);
	outputArchive << t;
	outputStream.close();
	return 0;
}

const int SerializationClass::DeserializeTeam(Team &t, std::string f)
{
	std::ifstream inputStream;
	inputStream.open(f, std::ifstream::in);
	boost::archive::binary_iarchive inputArchive(inputStream);
	inputArchive >> t;
	inputStream.close();

	return 0;
}