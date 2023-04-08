#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include "team.h"

class Match {
public:
    Match(Team& home, Team& away);
    void simulateMatch();

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
    void extraTime();
    void penalties();
    void printMatchStats();
};

Match::Match(Team& home, Team& away) :
        homeTeam(home), awayTeam(away),
        homeGoals(0), awayGoals(0), homeShots(0), awayShots(0),
        homeFouls(0), awayFouls(0) {}

void Match::simulateMatch() {
    std::cout << homeTeam.getName() << " vs " << awayTeam.getName() << std::endl;
    std::cout<<"====First half===="<<std::endl;
    simulateHalf(45);
    std::cout<<"====Second half===="<<std::endl;
    simulateHalf(45);
    if (homeGoals == awayGoals)
        extraTime();

    printMatchStats();
}

void Match::extraTime()
{
    std::cout << "Extra time:" << std::endl;
    std::cout<<"====First half===="<<std::endl;
    simulateHalf(15);
    std::cout<<"====Second half===="<<std::endl;
    simulateHalf(15);
    if(homeGoals==awayGoals)
        penalties();
}

void Match::penalties()
{
    std::cout << "====Penalties====" << std::endl;
    int random=rand()%2;
    int numbersOfPenaltiesScoredToWin=rand()%10+1;
    if(rand==0) 
    {
        std::cout << homeTeam.getName() << " " << numbersOfPenaltiesScoredToWin << " - " << numbersOfPenaltiesScoredToWin-1 << " " << awayTeam.getName() << std::endl;
        homeGoals++;
    }
    else 
    {
        std::cout << homeTeam.getName() << " " << numbersOfPenaltiesScoredToWin-1 << " - " << numbersOfPenaltiesScoredToWin << " " << awayTeam.getName() << std::endl;
        awayGoals++;
    }
}

void Match::simulateHalf (int duration) {
    srand(time(NULL));
    int homeChance = (homeTeam.getAttackStrength() + awayTeam.getDefenceStrength())/2;
    int awayChance = (awayTeam.getAttackStrength() + homeTeam.getDefenceStrength())/2;
    for (int time = 1; time <= duration/5; ++time) {

        int random=rand()%2500+1;
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
    std::cout << homeGoals << " - " << awayGoals << std::endl;
}

void Match::printMatchStats() {
    std::cout << "====Statistics===="<<std::endl;
    std::cout << homeTeam.getName() << " " << homeGoals << " - " << awayGoals << " " << awayTeam.getName() << std::endl;
    std::cout << "Shots: " << homeShots << " - " << awayShots << std::endl;
    std::cout << "Fouls: " << homeFouls << " - " << awayFouls << std::endl;
}