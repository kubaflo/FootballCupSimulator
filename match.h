#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>

class Match {
public:
    Team* simulateMatchAndGetWinner(Team& home, Team& away);

private:
    int homeGoals;
    int awayGoals;
    int homeShots;
    int awayShots;
    int homeFouls;
    int awayFouls;
    void simulateHalf(Team& homeTeam, Team& awayTeam,int duration);
    void extraTime(Team& homeTeam, Team& awayTeam);
    void penalties(Team& homeTeam, Team& awayTeam);
    void printMatchStats();
};

Team* Match::simulateMatchAndGetWinner(Team& homeTeam, Team& awayTeam) {
    homeGoals=awayGoals=homeShots=awayShots=homeFouls=awayFouls=0;
    std::cout << homeTeam.getName() << " vs " << awayTeam.getName() << std::endl;
    std::cout<<"===="<<homeTeam.getName()<<"===="<<std::endl;
    homeTeam.printTeam(false);
    std::cout<<"===="<<awayTeam.getName()<<"===="<<std::endl;
    awayTeam.printTeam(false);
    std::cout<<"====First half===="<<std::endl;
    simulateHalf(homeTeam,awayTeam,45);
    std::cout<<"====Second half===="<<std::endl;
    simulateHalf(homeTeam,awayTeam,45);
    if (homeGoals == awayGoals)
        extraTime(homeTeam,awayTeam);

    printMatchStats();

    return homeGoals>awayGoals?&homeTeam:&awayTeam;
}

void Match::extraTime(Team& homeTeam, Team& awayTeam)
{
    std::cout << "Extra time:" << std::endl;
    std::cout<<"====First half===="<<std::endl;
    simulateHalf(homeTeam,awayTeam,15);
    std::cout<<"====Second half===="<<std::endl;
    simulateHalf(homeTeam,awayTeam,15);
    if(homeGoals==awayGoals)
        penalties(homeTeam,awayTeam);
}

void Match::penalties(Team& homeTeam, Team& awayTeam)
{
    std::cout << "====Penalties====" << std::endl;
    int winner=rand()%2;
    int numbersOfPenaltiesScoredToWin=rand()%10+1;
    if(winner==0) 
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

void Match::simulateHalf (Team& homeTeam, Team& awayTeam,int duration) {
    srand(time(NULL));
    int homeChance = (homeTeam.getAttackStrength() + awayTeam.getDefenceStrength())/2;
    int awayChance = (awayTeam.getAttackStrength() + homeTeam.getDefenceStrength())/2+100;
    for (int time = 1; time <= duration/5; ++time) {

        int random=rand()%500+1;
        if (random <= homeChance)
            homeGoals++;
        else if(random>homeChance && random<=awayChance) 
            awayGoals++;        
    }
    homeShots+=(homeGoals+(rand()%3+1));
    homeFouls+=(rand()%3+1);
    awayShots+=(awayGoals+(rand()%3+1));
    awayFouls+=(rand()%3+1);
    std::cout << homeGoals << " - " << awayGoals << std::endl;
}

void Match::printMatchStats() {
    std::cout << "====Statistics===="<<std::endl;
    std::cout << "Score: " << homeGoals << " - " << awayGoals << std::endl;
    std::cout << "Shots: " << homeShots << " - " << awayShots << std::endl;
    std::cout << "Fouls: " << homeFouls << " - " << awayFouls << std::endl;
}