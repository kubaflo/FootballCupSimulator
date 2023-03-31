class PlayerStats
{
    public:
        int attack;
        int defence;
        int speed;
        PlayerStats(int attack,int defence,int speed);
};

PlayerStats::PlayerStats(int attack, int defence, int speed)
    : attack(attack), defence(defence), speed(speed) {}