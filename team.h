#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "player.h"

class Team
{
    public:
        Team(std::string name, std::string coach, int attackStrength, int defenceStrength);
        void addPlayer(Player player);
        void removePlayer(Player player);
        void selectLineup();
        void printTeam();
        std::string getName();
        int getAttackStrength(); //0-10
        int getDefenceStrength(); //0-10

    private:
        std::string name;
        std::string coach;
        int attackStrength;
        int defenceStrength;
        std::vector<Player> players;
        std::vector<Player> lineup;
};

Team::Team(std::string name, std::string coach, int attackStrength, int defenceStrength)
    :name(name), coach(coach), attackStrength(attackStrength), defenceStrength(defenceStrength) {};

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
    std::sort(players.begin(), players.end(),compareOveralls);

    lineup.clear();
    for (int i = 0; i < 2; ++i) {
        lineup.push_back(players[i]);
    }
}

void Team::printTeam()
{
    std::cout << "Team: " << name << std::endl;
    std::cout << "Coach: " << coach << std::endl;
    std::cout << "Attack strength: " << attackStrength << std::endl;
    std::cout << "Defence strength: " << defenceStrength << std::endl;

    std::cout << "Players: " << std::endl;
    for (auto player : players) {
        std::cout << "- " << player.getName() << std::endl;
    }

    std::cout << "Lineup: " << std::endl;
    for (auto player : lineup) {
        std::cout << "- " << player.getName() << std::endl;
    }
}

int Team::getAttackStrength() { return attackStrength;}

int Team::getDefenceStrength() { return defenceStrength; }