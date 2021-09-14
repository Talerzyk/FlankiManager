#pragma once
#include <vector>
#include "Match.h"

class Menu
{
public:
	Menu();

	void Display(std::vector<std::string> menu, Match &m); //Displays menu and all options and allows to play game
	int GetKeyMenu();

	const std::vector<std::string> menuMain = { "Play", "Team", "Options", "Exit" };
	const std::vector<std::string> menuOptions = { "Difficulty", "Sound", "Back" };
	const std::vector<std::string> menuTeam = { "Display Team", "Back" };
	
private:
	int choice;
};

