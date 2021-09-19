#pragma once
#include <vector>
#include "Match.h"

class Menu
{
public:
	Menu();

	void Display(std::vector<std::string> menu); //Displays menu and all options and allows to play game
	int GetKeyMenu();

	const std::vector<std::string> menuMain = { "New Game", "Load Game", "Options", "Exit" };
	const std::vector<std::string> menuPlay = { "Play", "Team", "Back" };
	const std::vector<std::string> menuOptions = { "Difficulty", "Sound", "Back" };
	const std::vector<std::string> menuTeam = { "Display Team", "Manage Team", "Save Team", "Back" };
	const std::vector<std::string> menuManageTeam = {"Change Name", "Back"};
	
private:
	int choice;
};

