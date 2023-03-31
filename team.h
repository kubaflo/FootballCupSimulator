#include <iostream>
#include <vector>
#include "player.h"

class Team
{
    public:
        Team(std::string name, std::string coach, int skillLevel, Playing_style playingStyle);
        void addPlayer(Player player);
        void removePlayer(Player player);
        void selectLineup();
        void printTeam();

    private:
        std::string name;
        std::string coach;
        int skillLevel;
        Playing_style playingStyle;
        std::vector<Player> players;
        std::vector<Player> lineup;
};

Team::Team(std::string name, std::string coach, int skillLevel, Playing_style playingStyle)
    :name(name), coach(coach), skillLevel(skillLevel), playingStyle(playingStyle) {};

void Team::addPlayer(Player player){ players.push_back(player); }

void Team::removePlayer(Player player)
{
    // for (auto it = players.begin(); it != players.end(); ++it) {
    //     if (*it == player) {
    //         players.erase(it);
    //         break;
    //     }
    // }
}

void Team::selectLineup()
{
    // Select the lineup based on some player's overall
    // std::sort(players.begin(), players.end(), [](const Player& p1, const Player& p2) {
    //     return p1.getStats().getOverall() > p2.getStats().getOverall();
    // });

    lineup.clear();
    for (int i = 0; i < 2; ++i) {
        lineup.push_back(players[i]);
    }
}

void Team::printTeam()
{
    std::cout << "Team: " << name << std::endl;
    std::cout << "Coach: " << coach << std::endl;
    std::cout << "Skill level: " << skillLevel << std::endl;
    std::cout << "Playing style: " << playingStyle << std::endl;

    std::cout << "Players: " << std::endl;
    for (auto player : players) {
        std::cout << "- " << player.getName() << std::endl;
    }

    std::cout << "Lineup: " << std::endl;
    for (auto player : lineup) {
        std::cout << "- " << player.getName() << std::endl;
    }
}