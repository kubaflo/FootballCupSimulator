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
        void chooseTeamsForTournament(int numberOfTeams);
};


void Tournament::addCustomTeam(Team team) { allTeams.push_back(team); }

void Tournament::chooseTeamsForTournament(int numberOfTeams)
{
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(allTeams), std::end(allTeams), rng);

    for(int i=0;i<numberOfTeams;i++)
        selectedTeams.push_back(allTeams[i]);
}

void Tournament::simulateTournament(InitialRound initialRound)
{
    generateTeams();

    Match match;
    Team* winner[(int)initialRound];

    if(initialRound==QUARTER_FINAL)
    {
        chooseTeamsForTournament(8);
        std::cout<<"=======QUARTER-FINALS========"<<std::endl<<std::endl;
        winner[0]= match.simulateMatchAndGetWinner(selectedTeams[0],selectedTeams[1]);
        winner[1]= match.simulateMatchAndGetWinner(selectedTeams[2],selectedTeams[3]);
        winner[2]= match.simulateMatchAndGetWinner(selectedTeams[4],selectedTeams[5]);
        winner[3]= match.simulateMatchAndGetWinner(selectedTeams[6],selectedTeams[7]);
    }

    if(initialRound==SEMI_FINAL)
    {
        chooseTeamsForTournament(4);
        std::cout<<"=======SEMI-FINALS========"<<std::endl<<std::endl;
        winner[0]= match.simulateMatchAndGetWinner(selectedTeams[0],selectedTeams[1]);
        winner[1]= match.simulateMatchAndGetWinner(selectedTeams[2],selectedTeams[3]);
    }
    else if(initialRound==QUARTER_FINAL)
    {
        std::cout<<"=======SEMI-FINALS========"<<std::endl<<std::endl;
        winner[0]= match.simulateMatchAndGetWinner(*winner[0],*winner[1]);
        winner[1]= match.simulateMatchAndGetWinner(*winner[2],*winner[3]);
    }

    std::cout<<"=======FINAL========"<<std::endl<<std::endl;
    if(initialRound==FINAL)
    {
        chooseTeamsForTournament(2);
        winner[0]= match.simulateMatchAndGetWinner(selectedTeams[0],selectedTeams[1]);
    }
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
            int attack = rand() % 91 + 10;
            int defence = rand() % 91 + 10;
            int speed = rand() % 91 + 10;
            Position position = Position(i % 3);
            PlayerStats stats(attack, defence, speed);
            team.addPlayer(Player(player_name, stats, position));
        }
        team.selectLineup();
        team.calculateAttackAndDefenceStrength();
    }
}
#endif