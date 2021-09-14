#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#include <random>
#include <iostream>
#include "Match.h"
#include "ComparatorClass.h"
#include "Player.h"
#include "Team.h"
#include "Can.h"

Match::Match(Team t1, Team t2, Can c, int dist)
{
	a = t1;
	b = t2;
	can = c;
	distance = dist;

	for (int i = 0; i < a.GetBase().size(); i++)
	{
		a.GetBase()[i].SetBottle(500); //everyone has full beer at the beginning of match
	}
	for (int i = 0; i < b.GetBase().size(); i++)
	{
		a.GetBase()[i].SetBottle(500); //everyone has full beer at the beginning of match
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
	int maxA = a.GetBase().size();
	int maxB = b.GetBase().size();
	int teamPlaying = CoinFlip(); //which team will play first. 0 - team a, 1 - team b
	int bottleState;
	int runTime;
	int drank;


	while (a.GetBase().size() != 0 && b.GetBase().size() != 0)
	{
		Sleep(1000);
		switch (teamPlaying)
		{
		case 0:
			std::cout << std::endl << std::endl << "Team t" << teamPlaying + 1 << " plays" << std::endl;
			bottleState = can.Hit(a.GetBase()[turnA].Throw()); //player throws and maybe hits can 
			std::cout << "bottle state: " << bottleState << std::endl;
			if (bottleState == 0)
			{
				teamPlaying = 1;
				break;
			}

			runTime = b.GetBase()[turnB].Run(distance, bottleState); //player runs and puts the can back
			std::cout << "run time: " << runTime << std::endl;
			can.PutBack();

			for (int i = 0; i < maxA; i++)
			{
				drank = a.GetBase()[i].Drink(runTime); //team drinks for the ammount of time that player ran
				std::cout << a.GetBase()[i].GetFirstName() << " drank " << drank << "ml" << std::endl;
				if (drank < 0)
				{
					a.RemovePlayer(a.GetBase()[i], 0);
					maxA--;
					i--;
				}
			}

			turnA++;
			if (turnA <= maxA)
				turnA = 0;

			teamPlaying = 1;

			break;

		case 1:
			std::cout << std::endl << std::endl << "Team t" << teamPlaying + 1 << " plays" << std::endl;
			bottleState = can.Hit(b.GetBase()[turnA].Throw()); //player throws and maybe hits can
			std::cout << "bottle state: " << bottleState << std::endl;
			if (bottleState == 0)
			{
				teamPlaying = 0;
				break;
			}

			runTime = a.GetBase()[turnB].Run(distance, bottleState); //player runs and puts the can back
			std::cout << "run time: " << runTime << std::endl;
			can.PutBack();

			for (int i = 0; i < maxB; i++)
			{
				drank = b.GetBase()[i].Drink(runTime); //team drinks for the ammount of time that player ran
				std::cout << b.GetBase()[i].GetFirstName() << " drank " << drank << "ml" << std::endl;
				if (drank < 0)
				{
					b.RemovePlayer(b.GetBase()[i], 0);
					maxB--;
					i--;
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
