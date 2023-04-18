#include <iostream>
#include <vector>
#include <random>
#include <cstdlib>
#include "user_interface.h"

class Match {

    private:
        UserInterface userInterface;
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

    public:
        Team* simulateMatchAndGetWinner(Team& home, Team& away);
};

Team* Match::simulateMatchAndGetWinner(Team& homeTeam, Team& awayTeam) {
    homeGoals=awayGoals=homeShots=awayShots=homeFouls=awayFouls=0;

    // Display the match details
    userInterface.printLine();
    userInterface.print("MATCH: " + homeTeam.getName() + " vs " + awayTeam.getName()+"\n",userInterface.COLOR_BOLD);
    userInterface.printLine();
    userInterface.print("HOME TEAM\n",userInterface.COLOR_GREEN);
    userInterface.printLine();
    homeTeam.printTeam(true);
    userInterface.printLine();
    userInterface.print("AWAY TEAM\n",userInterface.COLOR_GREEN);
    userInterface.printLine();
    awayTeam.printTeam(true);
    userInterface.printLine();

    // Simulate the first half
    userInterface.print("FIRST HALF\n",userInterface.COLOR_GREEN);
    userInterface.printLine();
    simulateHalf(homeTeam,awayTeam,45);
    userInterface.printLine();

    // Simulate the second half
    userInterface.print("SECOND HALF\n",userInterface.COLOR_GREEN);
    userInterface.printLine();
    simulateHalf(homeTeam,awayTeam,45);
    userInterface.printLine();

    // Check for a tie and simulate extra time if necessary
    if (homeGoals == awayGoals) {
        userInterface.printLine();
        extraTime(homeTeam,awayTeam);
        userInterface.printLine();
    }

    // Display match statistics and return winner
    userInterface.print("MATCH STATS\n",userInterface.COLOR_GREEN);
    userInterface.printLine();
    printMatchStats(homeTeam,awayTeam);
    userInterface.printLine();

    return homeGoals>awayGoals?&homeTeam:&awayTeam;
}

void Match::extraTime(Team& homeTeam, Team& awayTeam)
{
    userInterface.print("EXTRA TIME:\n",userInterface.COLOR_GREEN);
    userInterface.print("---First half---\n",userInterface.COLOR_BOLD);
    simulateHalf(homeTeam,awayTeam,15);
    userInterface.print("---Second half---\n",userInterface.COLOR_BOLD);
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
    userInterface.print("--- Penalty Shootout ---\n",userInterface.COLOR_BOLD);

    if (winner == 0) 
    {
        // Home team wins the penalty shootout
        userInterface.print(homeTeam.getName() + " " + std::to_string(numbersOfPenaltiesScoredToWin) + " - " + std::to_string(numbersOfPenaltiesScoredToWin-1) + " " + awayTeam.getName()+'\n',userInterface.COLOR_BOLD);
        homeGoals++;
    }
    else 
    {
        // Away team wins the penalty shootout
        userInterface.print(homeTeam.getName() + " " + std::to_string(numbersOfPenaltiesScoredToWin-1) + " - " + std::to_string(numbersOfPenaltiesScoredToWin) + " " + awayTeam.getName()+'\n',userInterface.COLOR_BOLD);
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
    userInterface.print("The match result is "+std::to_string(homeGoals) +'-'+ std::to_string(awayGoals)+'\n',userInterface.COLOR_BOLD);
}

void Match::printMatchStats(Team& homeTeam, Team& awayTeam) {
    userInterface.print("Final Score: "+ std::to_string(homeGoals) + " - " + std::to_string(awayGoals)+'\n',userInterface.COLOR_BLUE);
    userInterface.print("Total Shots "+ std::to_string(homeGoals+awayGoals)+'\n',userInterface.COLOR_BLUE);
    userInterface.print(homeTeam.getName()+ " Shots: "+ std::to_string(homeShots)+'\n',userInterface.COLOR_BLUE);
    userInterface.print(awayTeam.getName()+ " Shots: "+ std::to_string(homeShots)+'\n',userInterface.COLOR_BLUE);
    userInterface.print("Total Fouls "+ std::to_string(homeFouls+awayFouls)+'\n',userInterface.COLOR_BLUE);
    userInterface.print(homeTeam.getName()+ " Fouls: "+ std::to_string(homeShots)+'\n',userInterface.COLOR_BLUE);
    userInterface.print(awayTeam.getName()+ " Fouls: "+ std::to_string(awayFouls)+'\n',userInterface.COLOR_BLUE);
}