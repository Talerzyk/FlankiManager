#include "Team.h"
#include "ComparatorClass.h"
#include "Match.h"
#include "Menu.h"
#include "SerializationClass.h"
#include <iostream>

#include <boost/archive/binary_iarchive.hpp>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/serialization/vector.hpp>
#include <sstream>
#include <fstream>

int main()
{
	ComparatorClass comp;
	Player p1("adam", "szalbot", 0.7, 10, 5);
	Player p2("tymoteusz", "giemza", 0.2, 30, 5);
	Player p3("aleksander", "kubeczek", 0.5, 20, 5);
	Player p4, p5;

	Team t1(p1, p2, p3, p4, p5);

	t1.SetName("dupa");
	std::cout << SerializationClass::SerializeTeam(t1) << std::endl;

	Team t2;
	std::cout << SerializationClass::DeserializeTeam(t2, t1.GetName()) << std::endl;

	//Can c;

	//Match m1(t1, t2, c, 8);

	//Menu m;
	//m.Display(m.menuMain, m1);

	return 0;
}
