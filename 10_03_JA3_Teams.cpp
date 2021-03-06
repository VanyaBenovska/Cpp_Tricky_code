// 10_03_JA3_Teams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream> //for std::cout
#include <string>
#include <iomanip> 
#include <map>    
#include <vector>
#include <iterator> //for std::ostream_iterator

//using namespace std;

class Player
{
private:
	std::string name;
	int wins = 0;
public:
	Player()
	{}
	Player(std::string name) :
			name(name),
			wins(0)
	{}
	void setWins()
	{
		this->wins++;
	}
	std::string getName()
	{
		return this->name;
	}
	int getWins()
	{
		return this->wins;
	}
};

class Team
{
private:
	std::string name;
	std::vector<Player> dataV_players;
public:
	Team()
	{}
	Team(std::string name, std::vector<Player>dataCurrTeamPlayers) :
			name(name), dataV_players(dataCurrTeamPlayers)
	{}
	
	void setTeamWinToAllTeamPlayers(std::map<std::string, Player> &dataM_players)
	{
		for(auto it = this->dataV_players.begin(); it != this->dataV_players.end(); it++)
		{
			for(auto ite = dataM_players.begin(); ite != dataM_players.end(); ite++)
			{
				if (it->getName() == ite->first)
				{
					ite->second.setWins();
				}
			}
		}
	}
	std::vector<Player> getTeam()
	{
		return this->dataV_players;
	}
};

int main()
{
	std::cin.sync_with_stdio(false);
	std::cout.sync_with_stdio(false);

	std::map<std::string, Team> dataM_teams;
	std::map<std::string, Player> dataM_players;

	int numberOfTeams;
	std::cin >> numberOfTeams;
	for(int i = 0; i < numberOfTeams; i++)
	{
		std::string teamName;
		std::cin >> teamName;
		int numberOfPlayersInTheTeam;
		std::cin >> numberOfPlayersInTheTeam;
		std::map<std::string, Player> mPlayersInCurrTeam;
		std::vector<Player> vPl;
		for(int j = 0; j < numberOfPlayersInTheTeam; j++)
		{
			std::string plName;
			std::cin >> plName;
			vPl.push_back({plName});
			if(!(dataM_players.find(plName) != dataM_players.end()))
			{
				dataM_players.insert({ plName, {plName} });
			}
		}
		Team team{teamName, vPl};
		dataM_teams[teamName] = { teamName, vPl };
	}
	int numberOfGames;
	std::cin >> numberOfGames;
	for (int i = 0; i < numberOfGames; i++) 
	{
		std::string teamName;
		std::cin >> teamName;
		auto it = dataM_teams.find(teamName);		
		it->second.setTeamWinToAllTeamPlayers(dataM_players);		
	}
	for(auto item : dataM_players)
	{
		std::cout << item.second.getWins() << " ";
	}
	std::cout << std::endl;
    return 0;
}

