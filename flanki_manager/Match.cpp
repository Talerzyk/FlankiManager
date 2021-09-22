#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <random>
#include <iostream>
#include <conio.h>
#include "Match.h"
#include "ComparatorClass.h"
#include "Team.h"
#include "Can.h"

Match::Match(Team t1, int dist)
{
	Team t2;
	Can c;
	a = t1;
	b = t2;
	can = c;
	distance = dist;

	for (int i = 0; i < a.GetTeam(0).size(); i++)
	{
		a.GetTeam(0)[i].SetBottle(500); //everyone has full beer at the beginning of match
	}
	for (int i = 0; i < b.GetTeam(0).size(); i++)
	{
		a.GetTeam(0)[i].SetBottle(500); //everyone has full beer at the beginning of match
	}
}

Team& Match::GetA()
{
	return a;
}

Team& Match::GetB()
{
	return b;
}

Can& Match::GetCan()
{
	return can;
}

int Match::GetDistance()
{
	return distance;
}

int Match::Play()
{
	int turnA = 0, turnB = 0;
	int maxA = a.GetTeam(0).size();
	int maxB = b.GetTeam(0).size();
	int teamPlaying = CoinFlip(); //which team will play first. 0 - team a, 1 - team b
	int bottleState;
	int runTime;
	int drank;


	while (a.GetTeam(0).size() != 0 && b.GetTeam(0).size() != 0)
	{
		Sleep(1000);
		switch (teamPlaying)
		{
		case 0:
			std::cout << std::endl << std::endl << "Team " << a.GetName() << " plays" << std::endl;
			bottleState = can.Hit(a.GetTeam(0)[turnA].Throw()); //player throws and maybe hits can 
			std::cout << "bottle state: " << bottleState << std::endl;
			if (bottleState == 0)
			{
				teamPlaying = 1;
				break;
			}

			runTime = b.GetTeam(0)[turnB].Run(distance, bottleState); //player runs and puts the can back
			std::cout << "run time: " << runTime << std::endl;
			can.PutBack();

			for (int i = 0; i < maxA; i++)
			{
				drank = a.GetTeam(0)[i].Drink(runTime); //team drinks for the ammount of time that player ran
				std::cout << a.GetTeam(0)[i].GetFirstName() << " drank " << drank << "ml" << std::endl;
				if (drank < 0)
				{
					a.RemovePlayer(a.GetTeam(0)[i], 0);
					maxA--;
					i--;
					if (maxA == 0)
					{
						std::cout << "TEAM " << a.GetName() << " HAS WON" << std::endl;
						_getch();
						return 0;
					}
				}
			}

			turnA++;
			if (turnA <= maxA)
				turnA = 0;

			teamPlaying = 1;

			break;

		case 1:
			std::cout << std::endl << std::endl << "Team " << b.GetName() << " plays" << std::endl;
			bottleState = can.Hit(b.GetTeam(0)[turnA].Throw()); //player throws and maybe hits can
			std::cout << "bottle state: " << bottleState << std::endl;
			if (bottleState == 0)
			{
				teamPlaying = 0;
				break;
			}

			runTime = a.GetTeam(0)[turnB].Run(distance, bottleState); //player runs and puts the can back
			std::cout << "run time: " << runTime << std::endl;
			can.PutBack();

			for (int i = 0; i < maxB; i++)
			{
				drank = b.GetTeam(0)[i].Drink(runTime); //team drinks for the ammount of time that player ran
				std::cout << b.GetTeam(0)[i].GetFirstName() << " drank " << drank << "ml" << std::endl;
				if (drank < 0)
				{
					b.RemovePlayer(b.GetTeam(0)[i], 0);
					maxB--;
					i--;
					if (maxB == 0)
					{
						std::cout << "TEAM " << b.GetName() << " HAS WON" << std::endl;
						_getch();
						return 0;
					}
				}
			}

			turnB++;
			if (turnB <= maxB)
				turnB = 0;

			teamPlaying = 0;

			break;
		}
	}

	return 0;
}

int Match::CoinFlip() //returns result of a coin flip
{
	std::random_device rd; //random number from hardware
	std::mt19937 mt(rd()); //seed rd
	std::uniform_int_distribution<int> distr(0, 1);

	return distr(rd); //generate random number
}

std::string Match::Print()
{
	std::string data;
	data = "Team A:\nBase:\n" + a.Print(0) + "\nReserve:\n" + a.Print(1) + "\n\nTeam B:\nBase:\n" + b.Print(0) + "\nReserve:\n" + b.Print(1);
	return data;
}
