class PlayerStats {
    public:
        PlayerStats(int attack, int defence, int speed);
        int getOverall() const;

    private:
        int attack;
        int defence;
        int speed;
};

PlayerStats::PlayerStats(int attack, int defence, int speed)
    : attack(attack), defence(defence), speed(speed){}

int PlayerStats::getOverall() const
{
    return (attack  +  defence + speed ) / 6;
}