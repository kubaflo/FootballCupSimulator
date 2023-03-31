#include "player_stats.h"
#include "enums.h"

class Player {
    public:
        Player(std::string name, PlayerStats stats, Position position);
        std::string getName();
        PlayerStats getStats() const;
        Position getPosition();

        bool operator==(const Player& other) const {return name == other.name;}

    private:
        std::string name;
        PlayerStats stats;
        Position position;
};

Player::Player(std::string name, PlayerStats stats, Position position)
    : name(name), stats(stats), position(position) {}

std::string Player::getName(){return name;}

PlayerStats Player::getStats() const {return stats;}

Position Player::getPosition() {return position;}