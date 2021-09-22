#include "Team.h"
#include "ComparatorClass.h"
#include "Match.h"
#include "Menu.h"
#include "SerializationClass.h"
#include <iostream>

Team myTeam;

int main()
{
	/*
	Player p1("aleksander", "kubeczek", 0.4, 20, 6);
	Player p2("tymoteusz", "giemza", 0.6, 15, 5);
	Player p3("maciej", "jasielewicz", 0.2, 25, 4);
	Player p4("jakub", "antosiewicz", 0.8, 30, 3);
	Player p5("krzysztof", "kocyan", 0.5, 15, 5);
	t1.SetName("dupa");
	*/
	
	Menu m;
	m.Display(m.menuMain, "");

	return 0;
}
