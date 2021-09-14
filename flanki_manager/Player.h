#pragma once
#include <string>

class Player
{
public:
	Player();
	Player(std::string fName, std::string lName, float acc, int ds, int rs);

	void SetFirstName(std::string name);
	std::string GetFirstName();
	void SetLastName(std::string name);
	std::string GetLastName();
	void SetAccuracy(float acc);
	float GetAccuracy();
	void SetBottle(int bot);
	int GetBottle();

	int Throw(); //checks if player succseeded in throwing the stone. Return value: 0 - no success, 1 normal succes, 2 huge success
	int Drink(int time); //returns number of mililiters drank in int time seconds by a player
	int Run(int distance, int bottle); //returns number of seconds it took for a player to run, put the can back and return

	std::string Print();

private:
	std::string firstName;
	std::string lastName;
	float accuracy;
	int drinkSpeed; //speed of drinking in ml/s
	int runSpeed; //runnung speed in m/s
	int bottle; //bottle of a player, value in mililiters. 500 - full, 0 - empty
};

