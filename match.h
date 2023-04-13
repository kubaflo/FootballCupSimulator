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
    void printMatchStats(Team& homeTeam, Team& awayTeam);
};

Team* Match::simulateMatchAndGetWinner(Team& homeTeam, Team& awayTeam) {
    homeGoals=awayGoals=homeShots=awayShots=homeFouls=awayFouls=0;
    // Display the match details
    std::cout << "MATCH: " << homeTeam.getName() << " vs " << awayTeam.getName() << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "HOME TEAM" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    homeTeam.printTeam(true);
    std::cout << "---------------------------------------" << std::endl;
    std::cout << "AWAY TEAM" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    awayTeam.printTeam(true);
    std::cout << "---------------------------------------" << std::endl;

    // Simulate first half
    std::cout << "FIRST HALF" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    simulateHalf(homeTeam,awayTeam,45);
    std::cout << "---------------------------------------" << std::endl;

    // Simulate second half
    std::cout << "SECOND HALF" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    simulateHalf(homeTeam,awayTeam,45);
    std::cout << "---------------------------------------" << std::endl;

    // Check for tie and simulate extra time if necessary
    if (homeGoals == awayGoals) {
        std::cout << "EXTRA TIME" << std::endl;
        std::cout << "---------------------------------------" << std::endl;
        extraTime(homeTeam,awayTeam);
        std::cout << "---------------------------------------" << std::endl;
    }

    // Display match statistics and return winner
    std::cout << "MATCH STATS" << std::endl;
    std::cout << "---------------------------------------" << std::endl;
    printMatchStats(homeTeam,awayTeam);
    std::cout << "---------------------------------------" << std::endl;

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
    // Generate a random number between 0 and 1 to determine the winner
    int winner = rand() % 2;

    // Generate a random number between 1 and 10 to determine the number of penalties scored to win
    int numbersOfPenaltiesScoredToWin = rand() % 10 + 1;

    // Display the penalty shootout results
    std::cout << "==== Penalty Shootout ====" << std::endl;
    std::cout << "Both teams scored the same number of goals in the extra time period." << std::endl;
    std::cout << "The match will be decided by a penalty shootout." << std::endl;

    if (winner == 0) 
    {
        // Home team wins the penalty shootout
        std::cout << homeTeam.getName() << " " << numbersOfPenaltiesScoredToWin << " - " << numbersOfPenaltiesScoredToWin-1 << " " << awayTeam.getName() << std::endl;
        homeGoals++;
    }
    else 
    {
        // Away team wins the penalty shootout
        std::cout << homeTeam.getName() << " " << numbersOfPenaltiesScoredToWin-1 << " - " << numbersOfPenaltiesScoredToWin << " " << awayTeam.getName() << std::endl;
        awayGoals++;
    }
}

void Match::simulateHalf (Team& homeTeam, Team& awayTeam,int duration) {
    // Set up the match
    srand(time(NULL));
    int homeChance = (homeTeam.getAttackStrength() + awayTeam.getDefenceStrength()) / 2;
    int awayChance = (awayTeam.getAttackStrength() + homeTeam.getDefenceStrength()) / 2 + 100;

    // Simulate the match
    for (int time = 1; time <= duration / 5; ++time) {
        int random = rand() % 500 + 1;
        if (random <= homeChance)
            homeGoals++;
        else if (random > homeChance && random <= awayChance) 
            awayGoals++;
    }

    // Update statistics
    homeShots += (homeGoals + (rand() % 3 + 1));
    homeFouls += (rand() % 3 + 1);
    awayShots += (awayGoals + (rand() % 3 + 1));
    awayFouls += (rand() % 3 + 1);

    // Print the match result
    std::cout << "The match result is:" << std::endl;
    std::cout << homeGoals << " - " << awayGoals << std::endl;
}

void Match::printMatchStats(Team& homeTeam, Team& awayTeam) {
    std::cout << "Final Score: " << homeGoals << " - " << awayGoals << std::endl;
    std::cout << "Total Shots: " << homeShots + awayShots << std::endl;
    std::cout << homeTeam.getName() << " Shots: " << homeShots << std::endl;
    std::cout << awayTeam.getName() << " Shots: " << awayShots << std::endl;
    std::cout << "Total Fouls: " << homeFouls + awayFouls << std::endl;
    std::cout << homeTeam.getName() << " Fouls: " << homeFouls << std::endl;
    std::cout << awayTeam.getName() << " Fouls: " << awayFouls << std::endl;
}