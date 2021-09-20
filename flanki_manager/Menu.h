#pragma once
#include <vector>
#include "Match.h"

class Menu
{
public:
	Menu();

	void Display(std::vector<std::string> menu, std::string message); //Displays menu and all options and allows to play game. Message is displayed on the top of the menu
	int GetKeyMenu();

	const std::vector<std::string> menuMain = { "New Game", "Load Game", "Options", "Exit" };
	const std::vector<std::string> menuGame = { "Play", "Team", "Back" };
	const std::vector<std::string> menuPlay = { "Choose Opponent", "Random Opponent", "Back" };
	const std::vector<std::string> menuOptions = { "Difficulty", "Sound", "Back" };
	const std::vector<std::string> menuTeam = { "Display Team", "Manage Team", "Save Team", "Back" };
	const std::vector<std::string> menuManageTeam = {"Change Name", "Manage Players", "Back"};
	const std::vector<std::string> menuPlayer = {"Remove from team", "Change squad", "Back"};
	
private:
	int choice;
};

