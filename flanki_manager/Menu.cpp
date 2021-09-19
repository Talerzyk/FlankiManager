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
}

void Menu::Display(std::vector<std::string> menu)
{
	int maxChoice = menu.size();

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
				return;
			else if (menu[choice] == "New Game")
			{
				Team t;
				myTeam = t;
				std::cout << myTeam.Print(0) << std::endl;
				_getch();
				system("cls");
				Display(menuPlay);
			}
			else if (menu[choice] == "Load Game")
			{
				std::string file;
				for (const auto & entry : std::filesystem::directory_iterator("./Teams"))
					std::cout << entry.path() << std::endl;

				std::cout << "Which team do you want to load?:" << std::endl;
				std::cin >> file;
				SerializationClass::DeserializeTeam(myTeam, file);
				system("cls");
				std::cout << myTeam.Print(0) << std::endl;
				_getch();
				system("cls");
				Display(menuPlay);
			}
			else if (menu[choice] == "Options")
				Display(menuOptions);
			else if (menu[choice] == "Play")
			{
				Match m(myTeam, 8);
				m.Play();
			}
			else if (menu[choice] == "Team")
				Display(menuTeam);
			else if (menu[choice] == "Display Team")
			{
				std::cout << myTeam.Print(0) << std::endl;
				_getch();
			}
			else if (menu[choice] == "Manage Team")
				Display(menuManageTeam);
			else if (menu[choice] == "Save Team")
				SerializationClass::SerializeTeam(myTeam);
			else if (menu[choice] == "Change Name")
			{
				std::string newName;
				std::cout << "Current name: " << myTeam.GetName() << std::endl << "Enter new name: ";
				std::cin >> newName;
				myTeam.SetName(newName);
			}
		}

		if (choice == maxChoice)
			choice = 0;
		else if (choice < 0)
			choice = maxChoice - 1;

		system("cls");

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