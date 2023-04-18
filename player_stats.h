class PlayerStats {
    private:
        int attack;
        int defence;
        int speed;

    public:
        PlayerStats(int attack, int defence, int speed);
        int getAttack() const;
        int getDefence() const;
        int getSpeed() const;
        int getOverall() const;
};

PlayerStats::PlayerStats(int attack, int defence, int speed)
    : attack(attack), defence(defence), speed(speed){}

int PlayerStats::getOverall() const {return (attack + defence + speed ) / 3;}

int PlayerStats::getAttack() const {return attack;}

int PlayerStats::getDefence() const {return defence;}

int PlayerStats::getSpeed() const {return speed;}