#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <string>
#include <filesystem>
#include "Menu.h"
#include "Career.h"
#include "Match.h"
#include "main.h"
#include "SerializationClass.h"


const int KEY_ARROW_CHAR1 = 224;
const int KEY_ARROW_UP = 72;
const int KEY_ARROW_DOWN = 80;
const int KEY_ARROW_LEFT = 75;
const int KEY_ARROW_RIGHT = 77;
const int KEY_ENTER = 13;

Menu::Menu()
{
	choice = 0;
	subChoice = 0;
	squad = 0;
}

int Menu::Display(std::vector<std::string> menu, std::string message)
{
	static Team opponentTeam;
	std::vector<std::string> careers;
	for (const auto & entry : std::filesystem::directory_iterator("./Careers"))
		careers.push_back(entry.path().string());
	careers.push_back("Back");

	std::vector<std::string> teams;
	for (const auto& entry : std::filesystem::directory_iterator("./Teams"))
		teams.push_back(entry.path().string());
	teams.push_back("Back");

	int maxChoice = menu.size();

	std::cout << message;

	choice = 0;
	for (int i = 0; i < maxChoice; i++)
	{
		if (i == choice)
			std::cout << menu[i] << "<<" << std::endl;
		else
			std::cout << menu[i] << std::endl;
	}

	while (1)
	{
		if (GetKeyMenu() == 1)
		{
			system("cls");
			if (menu[choice] == "Back" || menu[choice] == "Exit")
			{
				choice = 0;
				return 0;
			}
			else if (menu[choice] == "New Game")
			{
				Team t;
				myCareer.GetMyTeam() = t;
				std::cout << myCareer.GetMyTeam().Print(0) << std::endl;
				_getch();
				system("cls");
				Display(menuGame, "");
			}
			else if (menu[choice] == "Load Game")
			{
				Display(careers, "Which career do you want to load?:\n");
				Display(menuGame, myCareer.GetName() + "\n\n");
			}
			else if (menu == careers)
			{
				SerializationClass::DeserializeCareer(myCareer, menu[choice]);
				system("cls");
				std::cout << myCareer.GetMyTeam().Print(0) << std::endl;
				_getch();
				system("cls");
				return 0;
			}
			else if (menu[choice] == "Save Game")
			{
				if (SerializationClass::SerializeCareer(myCareer) == 0)
				{
					system("cls");
					std::cout << "Game saved" << std::endl;
				}
				else
					std::cout << "Game not saved" << std::endl;

				_getch();
			}
			else if (menu[choice] == "Options")
				Display(menuOptions, "");
			else if (menu[choice] == "Play")
			{
				if (Display(teams, "Select opponent team\n\n") == 0)
				{
					Match m(myCareer.GetMyTeam(), opponentTeam, 8);
					myCareer.AddToHistory(m.Play(), opponentTeam);
					_getch();
				}
			}
			else if (menu == teams)
			{
				Team tempTeam;
				SerializationClass::DeserializeTeam(tempTeam, menu[choice]);
				if (tempTeam.Print(0) == myCareer.GetMyTeam().Print(0))
				{
					std::cout << "Cannot choose this team" << std::endl;
					_getch();
					return 1;
				}
				opponentTeam = tempTeam;
				return 0;
			}
			else if (menu[choice] == "Team")
				Display(menuTeam, "Team " + myCareer.GetMyTeam().GetName() + "\n\n");
			else if (menu[choice] == "Display Team")
			{
				std::cout << myCareer.GetMyTeam().Print(0) << std::endl << myCareer.GetMyTeam().Print(1);
				_getch();
			}
			else if (menu[choice] == "Manage Team")
				Display(menuManageTeam, "");
			else if (menu[choice] == "Change Name")
			{
				std::string newName;
				std::cout << "Current name: " << myCareer.GetMyTeam().GetName() << std::endl << "Enter new name: ";
				std::cin >> newName;
				myCareer.GetMyTeam().SetName(newName);
			}
			else if (menu[choice] == "Manage Players")
			{
				Display(menuBR, "");
				return 0;
			}
			else if (menu[choice] == "Base")
			{
				squad = 0; //for managing team
				Display(myCareer.GetMyTeam().GetTeamMenu(0), "Base\n");
				return 0;
			}
			else if (menu[choice] == "Reserve")
			{
				squad = 1; //for managing team
				Display(myCareer.GetMyTeam().GetTeamMenu(1), "Reserve\n");
				return 0;
			}
			else if (menu == myCareer.GetMyTeam().GetTeamMenu(0) || menu == myCareer.GetMyTeam().GetTeamMenu(1))
			{
				subChoice = choice; //for picking player
				Display(menuPlayer, menu[choice] + "\n\n");
				return 0;
			}
			else if (menu[choice] == "Remove From Team")
			{
				if (myCareer.GetMyTeam().RemovePlayer(myCareer.GetMyTeam().GetTeam(squad)[subChoice], squad) == 1)
					std::cout << "Cannot remove player" << std::endl;
				else
					std::cout << "Player removed successfully" << std::endl;
				_getch();
				return 0;
			}
			else if (menu[choice] == "Change Squad")
			{
				if (myCareer.GetMyTeam().GetTeam((squad + 1)%2).size() == myCareer.GetMyTeam().teamSize)
				{
					std::cout << "Cannot change squad" << std::endl;
					_getch();
				}
				else
				{
					myCareer.GetMyTeam().AddPlayer(myCareer.GetMyTeam().GetTeam(squad)[subChoice], ((squad + 1) % 2));
					myCareer.GetMyTeam().RemovePlayer(myCareer.GetMyTeam().GetTeam(squad)[subChoice], squad);
				}
				return 0;
			}
			else if (menu[choice] == "Show Match History")
			{
				std::cout << myCareer.PrintMatchHistory();
				_getch();
			}
		}

		if (choice == maxChoice)
			choice = 0;
		else if (choice < 0)
			choice = maxChoice - 1;

		system("cls");

		std::cout << message;

		for (int i = 0; i < maxChoice; i++)
		{
			if (i == choice)
				std::cout << menu[i] << "<<" << std::endl;
			else
				std::cout << menu[i] << std::endl;
		}
	}	
}

int Menu::GetKeyMenu()
{
	unsigned char ch1 = _getch();
	if (ch1 == KEY_ARROW_CHAR1)
	{
		// Some Arrow key was pressed, determine which?
		unsigned char ch2 = _getch();
		switch (ch2)
		{
		case KEY_ARROW_UP:
			choice--;
			break;

		case KEY_ARROW_DOWN:
			choice++;
			break;

		case KEY_ARROW_LEFT:
			break;

		case KEY_ARROW_RIGHT:
			break;
		}
	}
	else if (ch1 == KEY_ENTER)
		return 1;

	return 0;
}