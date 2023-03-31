#include "player.h"
#include "enums.h"

class Team
{
public:
    Team(std::string name, std::string coach, int skillLevel, std::string playingStyle);
    void addPlayer(Player player);
    void removePlayer(Player player);
    void selectLineup();
    void printTeam();

private:
    std::string name;
    std::string coach;
    int skillLevel;
    std::string playingStyle;
    std::vector<Player> players;
    std::vector<Player> lineup;
};