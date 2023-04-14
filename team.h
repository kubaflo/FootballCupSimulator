#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include "player.h"
#include "user_interface.h"

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
        UserInterface userInterface;
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
        userInterface.print("Team: "+name+'\n',userInterface.COLOR_YELLOW);
    }

    userInterface.print("Coach: "+name+'\n',userInterface.COLOR_YELLOW);
    userInterface.print("Attack Strength: "+std::to_string(attackStrength)+'\n',userInterface.COLOR_YELLOW);
    userInterface.print("Defence Strength: "+std::to_string(defenceStrength)+'\n',userInterface.COLOR_YELLOW);

    if(fullInfo) {
        userInterface.print("Players:\n",userInterface.COLOR_YELLOW);
        for (auto& player : players) {
            userInterface.print("- " + player.getName()+'\n',userInterface.COLOR_UNDERLINE);
        }
    }

    userInterface.print("Starting Lineup:\n",userInterface.COLOR_YELLOW);
    for (auto& player : lineup) {
        userInterface.print("- " + player.getName() + ": Overall Rating - " + std::to_string(player.getStats().getOverall())+'\n',userInterface.COLOR_UNDERLINE);
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