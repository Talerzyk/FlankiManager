#include "Career.h"
#include <chrono>
#include <format>

Career::Career()
{
	
}

int Career::AddToHistory(int result, Team opTeam)
{
	auto const time = std::chrono::current_zone()->to_local(std::chrono::system_clock::now());
	std::string formattedTime =  std::format("{:%Y-%m-%d %X}", time);
	
	std::string winlose;

	if (result == 0)
		winlose = "won";
	else
		winlose = "lost";
	matchHistory.push_back({winlose, formattedTime, opTeam.GetName()});
	return 0;
}

std::string Career::GetName()
{
	return name;
}

void Career::SetName(std::string n)
{
	name = n;
}

Team & Career::GetMyTeam()
{
	return myTeam;
}

void Career::SetMyTeam(Team t)
{
	myTeam = t;
}

std::vector< std::vector<std::string>> Career::GetMatchHistory()
{
	return matchHistory;
}

std::string Career::PrintMatchHistory()
{
	std::string data;
	for (int i = 0; i < matchHistory.size(); i++)
		data += matchHistory[i][0] + "   " + matchHistory[i][1] + "   " + matchHistory[i][2] + "\n";

	return data;
}
