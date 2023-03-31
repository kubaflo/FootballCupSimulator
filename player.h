#include "enums.h"
#include "player_stats.h"

using namespace std;

class Player
{
    public:
        string name;
        PlayerStats stats;
        Position position;
        Player(string name, PlayerStats stats, Position position);
};

Player::Player(std::string name, PlayerStats stats, Position position)
    : name(name), stats(stats), position(position) {}