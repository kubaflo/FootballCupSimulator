#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "player.h"

class Team
{
    public:
        Team(std::string name, std::string coach);
        void addPlayer(Player player);
        void removePlayer(Player player);
        void selectLineup();
        void printTeam(bool fullInfo);
        void calculateAttackAndDefenceStrength();
        std::string getName();
        int getAttackStrength();
        int getDefenceStrength();

    private:
        std::string name;
        std::string coach;
        int attackStrength;
        int defenceStrength;
        std::vector<Player> players;
        std::vector<Player> lineup;
};

Team::Team(std::string name, std::string coach)
    :name(name), coach(coach) {};

void Team::addPlayer(Player player) { players.push_back(player); }

std::string Team::getName() { return name;}

void Team::removePlayer(Player player)
{
    auto it = std::find(players.begin(), players.end(), player);

    if(it!=players.end())
        players.erase(it);
}

bool compareOveralls (Player p1, Player p2) { return p1.getStats().getOverall()>p2.getStats().getOverall();}

void Team::selectLineup()
{
    //Select the lineup based on some player's overall
    std::sort(players.begin(), players.end(), compareOveralls);

    lineup.clear();
    for (int i = 0; i < 3; ++i) {
        lineup.push_back(players[i]);
    }
}

void Team::printTeam(bool fullInfo)
{
    if(fullInfo) {
        std::cout << "Team: " << name << std::endl;
    }

    std::cout << "Coach: " << coach << std::endl;
    std::cout << "Attack Strength: " << attackStrength << std::endl;
    std::cout << "Defence Strength: " << defenceStrength << std::endl;

    if(fullInfo) {
        std::cout << "Players: " << std::endl;
        for (auto& player : players) {
            std::cout << "- " << player.getName() << std::endl;
        }
    }

    std::cout << "Starting Lineup: " << std::endl;
    for (auto& player : lineup) {
        std::cout << "- " << player.getName() << ": Overall Rating - "<< player.getStats().getOverall() << std::endl;
    }
}

void Team::calculateAttackAndDefenceStrength()
{
    int totalAttack=0;
    int totalDefence=0;
    for(auto& player : players)
    {
        totalAttack+=player.getStats().getAttack();
        totalDefence+=player.getStats().getDefence();
    }
    int numberOfPlayers=players.size();
    attackStrength=totalAttack/numberOfPlayers;
    defenceStrength=totalDefence/numberOfPlayers;
}

int Team::getAttackStrength() { return attackStrength;}

int Team::getDefenceStrength() { return defenceStrength; }