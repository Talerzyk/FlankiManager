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

Match::Match(const Team &t1, const Team &t2, const int &dist)
{
	Can c;
	teams[0] = t1; //player's team
	teams[1] = t2; //AI opponent's team
	can = c;
	distance = dist;

	for (int i = 0; i < teams[0].GetTeam(0).size(); i++)
	{
		teams[0].GetTeam(0)[i].SetBottle(500); //everyone has full beer at the beginning of match
	}
	for (int i = 0; i < teams[1].GetTeam(0).size(); i++)
	{
		teams[1].GetTeam(0)[i].SetBottle(500); //everyone has full beer at the beginning of match
	}
}

Team& Match::GetA()
{
	return teams[0];
}

Team& Match::GetB()
{
	return teams[1];
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
	int turn[2] = {0, 0};
	int max[2] = { max[0] = teams[0].GetTeam(0).size(), max[1] = teams[1].GetTeam(0).size() };
	int teamPlaying = CoinFlip(); //which team will play first. 0 - player's team, 1 - AI
	int bottleState;
	int runTime;
	int drank;


	while (teams[0].GetTeam(0).size() != 0 && teams[1].GetTeam(0).size() != 0)
	{
		Sleep(1000);
		std::cout << std::endl << std::endl << "Team " << teams[teamPlaying].GetName() << " plays" << std::endl;
		bottleState = can.Hit(teams[teamPlaying].GetTeam(0)[turn[teamPlaying]].Throw()); //player throws and maybe hits can 
		std::cout << "bottle state: " << bottleState << std::endl;
		if (bottleState == 0)
		{
			teamPlaying = (teamPlaying + 1) % 2;
			continue;
		}

		runTime = teams[(teamPlaying + 1)%2].GetTeam(0)[turn[(teamPlaying + 1) % 2]].Run(distance, bottleState); //player runs and puts the can back
		std::cout << "run time: " << runTime << std::endl;
		can.PutBack();

		for (int i = 0; i < max[teamPlaying]; i++)
		{
			drank = teams[teamPlaying].GetTeam(0)[i].Drink(runTime); //team drinks for the ammount of time that player ran
			std::cout << teams[teamPlaying].GetTeam(0)[i].GetFirstName() << " drank " << drank << "ml" << std::endl;
			if (drank < 0)
			{
				teams[teamPlaying].RemovePlayer(teams[teamPlaying].GetTeam(0)[i], 0);
				max[teamPlaying]--;
				i--;
				if (max[teamPlaying] == 0)
				{
					std::cout << "TEAM " << teams[teamPlaying].GetName() << " HAS WON" << std::endl;
					_getch();
					return teamPlaying;
				}
			}
		}
		turn[teamPlaying]++;
		if (turn[teamPlaying] <= max[teamPlaying])
				turn[teamPlaying] = 0;

		teamPlaying = (teamPlaying + 1) % 2;
	}
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
	data = "Team A:\nBase:\n" + teams[0].Print(0) + "\nReserve:\n" + teams[0].Print(1) + "\n\nTeam B:\nBase:\n" + teams[1].Print(0) + "\nReserve:\n" + teams[1].Print(1);
	return data;
}
