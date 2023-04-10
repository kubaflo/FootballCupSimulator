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
        void simulateTournament();

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

void Tournament::simulateTournament()
{
    generateTeams();
    chooseTeamsForTournament();

    std::cout<<"=======SEMIFINALS========"<<std::endl<<std::endl;
    Match semifinal1(allTeams[0],allTeams[1]);
    Team semifinal1Winner=semifinal1.simulateMatchAndGetWinner();

    std::cout<<std::endl<<std::endl<<std::endl;
    Match semifinal2(allTeams[2],allTeams[3]);
    Team semifinal2Winner=semifinal2.simulateMatchAndGetWinner();

    std::cout<<std::endl<<std::endl<<std::endl;
    std::cout<<"=======FINAL========"<<std::endl<<std::endl;
    Match final(semifinal1Winner,semifinal2Winner);
    Team finalWinner=final.simulateMatchAndGetWinner();

    std::cout<<std::endl<<std::endl<<std::endl;
    std::cout<<std::endl<<"=======WINNER======="<<std::endl;
    finalWinner.printTeam(true);
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