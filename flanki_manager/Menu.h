#pragma once
#include <vector>
#include "Career.h"

class Menu
{
public:
	Menu();

	int Display(std::vector<std::string> menu, std::string message); //Displays menu and all options and allows to play game. Message is displayed on the top of the menu
	int GetKeyMenu();

	const std::vector<std::string> menuMain = { "New Game", "Load Game", "Save Game", "Options", "Exit" };
	const std::vector<std::string> menuGame = { "Play", "Team", "Show Match History", "Back" };
	const std::vector<std::string> menuPlay = { "Choose Opponent", "Random Opponent", "Back" };
	const std::vector<std::string> menuOptions = { "Difficulty", "Sound", "Back" };
	const std::vector<std::string> menuTeam = { "Display Team", "Manage Team", "Back" };
	const std::vector<std::string> menuManageTeam = { "Change Name", "Manage Players", "Back" };
	const std::vector<std::string> menuPlayer = { "Remove From Team", "Change Squad", "Back" };
	const std::vector<std::string> menuBR = { "Base", "Reserve", "Back" };
	
private:
	int choice;
	int subChoice;
	int squad;
};

