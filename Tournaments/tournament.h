#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "../team.h"
#include "../match.h"
#include <vector>
#include <algorithm>
#include <random>

class Tournament
{
    public:
        void addCustomTeam(Team team);
        void simulateTournament(InitialRound initialRound);

    protected:
        std::vector<Team> allTeams;
        std::vector<Team> selectedTeams;
        virtual void generateTeams()= 0;
        void addPlayersToTeams();
        void chooseTeamsForTournament();
};


void Tournament::addCustomTeam(Team team) { allTeams.push_back(team); }

void Tournament::chooseTeamsForTournament()
{
    for(int i=0;i<allTeams.size();i++)
        selectedTeams.push_back(allTeams[i]);
}

void Tournament::simulateTournament(InitialRound initialRound)
{
    generateTeams();
    chooseTeamsForTournament();

    Match match;
    Team* winner[4];

    if(initialRound==QUARTER_FINAL)
    {
        std::cout<<"=======QUARTER-FINALS========"<<std::endl<<std::endl;
        winner[0]= match.simulateMatchAndGetWinner(allTeams[0],allTeams[1]);
        winner[1]= match.simulateMatchAndGetWinner(allTeams[2],allTeams[3]);
        winner[2]= match.simulateMatchAndGetWinner(allTeams[4],allTeams[5]);
        winner[3]= match.simulateMatchAndGetWinner(allTeams[6],allTeams[7]);
    }

    if(initialRound==SEMI_FINAL)
    {
        std::cout<<"=======SEMI-FINALS========"<<std::endl<<std::endl;
        winner[0]= match.simulateMatchAndGetWinner(allTeams[0],allTeams[1]);
        winner[1]= match.simulateMatchAndGetWinner(allTeams[2],allTeams[3]);
    }
    else if(initialRound==QUARTER_FINAL)
    {
        std::cout<<"=======SEMI-FINALS========"<<std::endl<<std::endl;
        winner[0]= match.simulateMatchAndGetWinner(*winner[0],*winner[1]);
        winner[1]= match.simulateMatchAndGetWinner(*winner[2],*winner[3]);
    }

    std::cout<<"=======FINAL========"<<std::endl<<std::endl;
    if(initialRound==FINAL)
        winner[0]= match.simulateMatchAndGetWinner(allTeams[0],allTeams[1]);
    else 
        winner[0] = match.simulateMatchAndGetWinner(*winner[0],*winner[1]);

    std::cout<<std::endl<<"=======WINNER======="<<std::endl<<std::endl;
    winner[0]->printTeam(true);
}

void Tournament::addPlayersToTeams()
{
    for (auto& team : allTeams) 
    {
        for (int i = 0; i < 5; i++) {
            std::string player_name = "Player " + std::to_string(i+1);
            int attack = rand() % 91 + 10; // generate a random number between 10 and 100
            int defence = rand() % 91 + 10; // generate a random number between 10 and 100
            int speed = rand() % 91 + 10; // generate a random number between 10 and 100
            Position position = Position(i % 3); // alternate between the four positions
            PlayerStats stats(attack, defence, speed); // set the player's goal count to 0
            team.addPlayer(Player(player_name, stats, position));
        }
        team.selectLineup();
        team.calculateAttackAndDefenceStrength();
    }
}
#endif