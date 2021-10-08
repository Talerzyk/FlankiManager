#include "ComparatorClass.h"
#include "Menu.h"
#include "SerializationClass.h"
#include <iostream>

#include <chrono>
#include <thread>
#include <conio.h>
#include <mutex>
#include <condition_variable>

std::mutex m;
std::condition_variable cv;
unsigned char ch1, ch2;


Career myCareer;

auto watchdog = [](std::stop_token t)
{
	
	while (!t.stop_requested())
	{
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::unique_lock<std::mutex> lk(m);
		ch1 = _getch();
		ch2 = _getch();
		//std::cout << std::this_thread::get_id() << " " << (int)ch1 << " " << (int)ch2 << std::endl;
		cv.notify_one();
	}
};

auto print = [](std::stop_token t)
{
	while (!t.stop_requested())
	{
		std::unique_lock<std::mutex> lk(m);
		cv.wait(lk);
		std::cout << std::this_thread::get_id() << " " << (int)ch1 << " " << (int)ch2 << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
};

int main()
{
	/*
	Player p1("aleksander", "kubeczek", 0.4, 20, 6);
	Player p2("tymoteusz", "giemza", 0.6, 15, 5);
	Player p3("maciej", "jasielewicz", 0.2, 25, 4);
	Player p4("jakub", "antosiewicz", 0.8, 30, 3);
	Player p5("krzysztof", "kocyan", 0.5, 15, 5);
	Team t1(p1, p2, p3, p4, p5);
	t1.SetName("dupa");
	Team t2;
	*/

	//Menu m;
	//m.Display(m.menuMain, "");

	std::jthread watchd(watchdog);
	std::jthread prnt(print);

	std::this_thread::sleep_for(std::chrono::seconds(10));
	prnt.request_stop();
	watchd.request_stop();

	return 0;
}
