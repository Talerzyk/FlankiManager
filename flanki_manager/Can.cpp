#include "Can.h"
#include <random>

Can::Can()
{
	state = 0;
}

int Can::Hit(const int &thr)
{
	std::random_device rd; //random number from hardware
	std::mt19937 mt(rd()); //seed rd
	std::uniform_int_distribution<int> distr(1, 10);
	int success = 0;

	switch (thr)
	{
	case 0:
		for (int i = 0; i < 3; i++)
		{
			int trial = distr(rd); //generate random number
			if (trial == 10 && success == 0)
				success = 1;
			else if (trial == 10 && success == 1)
				success = 2;
			else if (trial == 10 && success == 2)
				success = 3; //almost no chance for that (1/1000)
		}
		if (success > 1)
		{
			success = 1;
			state = 1; //can falls near
		}
		break;

	case 1:
		for (int i = 0; i < 10; i++)
		{
			int trial = distr(rd); //generate random number
			if (trial == 10 && success == 0)
			{
				success = 1;
				state = 1; //can falls near
			}
			else if (trial == 10 && success == 1)
			{
				success = 2;
				state = 2; //can falls far
			}
		}
		break;

	case 2:
		for (int i = 0; i < 15; i++)
		{
			int trial = distr(rd); //generate random number
			if (trial == 10 && success == 0)
			{
				success = 2;
				state = 2; //can falls far
			}
		}

	}

	return success;
}

int Can::PutBack()
{
	state = 0;
	return 0;
}