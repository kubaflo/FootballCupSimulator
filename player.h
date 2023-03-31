#include "player_stats.h"
#include "enums.h"

class Player {
    public:
        Player(std::string name, PlayerStats stats, Position position);
        std::string getName();
        PlayerStats getStats();
        Position getPosition();

    private:
        std::string name;
        PlayerStats stats;
        Position position;
};

Player::Player(std::string name, PlayerStats stats, Position position)
    : name(name), stats(stats), position(position) {}

std::string Player::getName(){return name;}

PlayerStats Player::getStats() {return stats;}

Position Player::getPosition() {return position;}