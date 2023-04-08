#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include "team.h"

class Match {
public:
    Match(Team& home, Team& away);
    void simulateMatch();
    void printMatchStats();

private:
    Team& homeTeam;
    Team& awayTeam;
    int homeGoals;
    int awayGoals;
    int homeShots;
    int awayShots;
    int homeFouls;
    int awayFouls;
    void simulateHalf(int duration);
};

Match::Match(Team& home, Team& away) :
        homeTeam(home), awayTeam(away),
        homeGoals(0), awayGoals(0), homeShots(0), awayShots(0),
        homeFouls(0), awayFouls(0) {}

void Match::simulateMatch() {
    std::cout << homeTeam.getName() << " vs " << awayTeam.getName() << std::endl;
    simulateHalf(45);
    simulateHalf(45);
    if (homeGoals == awayGoals) {
        std::cout << "Extra time!" << std::endl;
        simulateHalf(15);
        simulateHalf(15);
        if(homeShots==awayGoals)
        {
            std::cout << "Penalties!" << std::endl;
            int random=rand()%2;
            if(rand==0) homeGoals++;
            else awayGoals++;
        }
    }
}

void Match::simulateHalf (int duration) {
    srand(time(NULL));
    int homeChance = homeTeam.getAttackStrength() + awayTeam.getDefenceStrength();
    int awayChance = awayTeam.getAttackStrength() + homeTeam.getDefenceStrength()+20;
    for (int time = 1; time <= duration; ++time) {

        int random=rand()%500+1;
        if (random <= homeChance) {
            std::cout << homeTeam.getName() << " scores!" << std::endl;
            homeGoals++;
        } else if(random>homeChance && random<=awayChance) {
            std::cout << awayTeam.getName() << " scores!" << std::endl;
            awayGoals++;
        }
    }
    homeShots+=(homeGoals+(rand()%3+1));
    homeFouls+=(rand()%3+1);
    awayShots+=(awayGoals+(rand()%3+1));
    awayFouls+=(rand()%3+1);
    std::cout << "Half time: " << homeGoals << " - " << awayGoals << std::endl;
}

void Match::printMatchStats() {
    std::cout << homeTeam.getName() << " " << homeGoals << " - " << awayGoals << " " << awayTeam.getName() << std::endl;
    std::cout << "Shots: " << homeShots << " - " << awayShots << std::endl;
    std::cout << "Fouls: " << homeFouls << " - " << awayFouls << std::endl;
}