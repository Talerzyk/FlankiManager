#include "Player.h"
#include <iostream>
#include <random>
#include <string>



Player::Player()
{
	firstName = "dupa";
	lastName = "kupa";
	accuracy = 0.4;
	bottle = 500;
	drinkSpeed = 15;
	runSpeed = 5;
}

Player::Player(const std::string& fName, const std::string& lName, const float& acc, const int& ds, const int& rs)
{
	firstName = fName;
	lastName = lName;
	accuracy = acc;
	drinkSpeed = ds;
	runSpeed = rs;
	bottle = 500;
}


void Player::SetFirstName(const std::string &name)
{
	firstName = name;
}

std::string Player::GetFirstName()
{
	return firstName;
}

void Player::SetLastName(const std::string &name)
{
	lastName = name;
}

std::string Player::GetLastName()
{
	return lastName;
}

void Player::SetAccuracy(const float &acc)
{
	accuracy = acc;
}

float Player::GetAccuracy()
{
	return accuracy;
}

void Player::SetBottle(const int &bot)
{
	bottle = bot;
}

int Player::GetBottle()
{
	return bottle;
}


int Player::Throw()
{
	int success = 0;
	int trial = 0;
	float trials = accuracy * 10;

	std::random_device rd; //random number from hardware
	std::mt19937 mt(rd()); //seed rd
	std::uniform_int_distribution<int> distr(1, 10);

	for (int i = 0; i < trials; i++)
	{
		trial = distr(rd); //generate random number
		if (trial == 10 && success == 0)
			success = 1;
		else if (trial == 10 && success == 1)
			success = 2;
	}

	return success;
}

int Player::Drink(const int &time)
{
	int drank = drinkSpeed * time;
	bottle = bottle - drank;
	if (bottle < 0)
		return -1;

	return drank;
}

int Player::Run(const int &distance, const int &bottle)
{
	int time = 0;
	time = time + 2*(distance/runSpeed + 1) + bottle; //run back and forth + 1 second for bottle setting

	return time;
}

std::string Player::Print()
{
	std::string data;
	data = firstName + " " + lastName + " accuracy:" + std::to_string(accuracy) + " drink speed:" + std::to_string(drinkSpeed) + " run speed:" + std::to_string(runSpeed);

	return data;
}
