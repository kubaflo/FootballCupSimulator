#ifndef TOURNAMENT_H
#define TOURNAMENT_H

#include "../team.h"
#include "../match.h"
#include "../user_interface.h"
#include <vector>
#include <algorithm>
#include <random>
#include <stack>

class Tournament
{
    private:
        UserInterface userInterface;

    protected:
        std::vector<Team> allTeams;
        std::vector<Team> selectedTeams;
        virtual void generateTeams()= 0;
        void addPlayersToTeams();
        void chooseTeamsForTournament(int numberOfTeams);        

    public:
        void addCustomTeam(Team team);
        void simulateTournament(InitialRound initialRound);
};


void Tournament::addCustomTeam(Team team) { allTeams.push_back(team); }

void Tournament::chooseTeamsForTournament(int numberOfTeams)
{
    bool isNumberSelected[numberOfTeams];
    int randomNumber;
    std::stack<int> selectedNumbers;
    
    while(numberOfTeams>0)
    {
        do
        {
            randomNumber=rand()%allTeams.size();
        } while(isNumberSelected[randomNumber]);

        isNumberSelected[randomNumber]=true;
        selectedNumbers.push(randomNumber); 
        numberOfTeams--;
    }

    while(!selectedNumbers.empty())
    {
        srand(time(NULL));
        std::cout<<selectedNumbers.top()<<"xxx";
        selectedTeams.push_back(allTeams[selectedNumbers.top()]);
        selectedNumbers.pop();
    }
}

void Tournament::simulateTournament(InitialRound initialRound)
{
    generateTeams();

    Match match;
    Team* winner[(int)initialRound];

    if(initialRound==QUARTER_FINAL)
    {
        chooseTeamsForTournament(8);
        userInterface.print("\n\n--- QUARTER-FINALS MATCHES ---\n",userInterface.COLOR_GREEN);
        winner[0]= match.simulateMatchAndGetWinner(selectedTeams[0],selectedTeams[1]);
        winner[1]= match.simulateMatchAndGetWinner(selectedTeams[2],selectedTeams[3]);
        winner[2]= match.simulateMatchAndGetWinner(selectedTeams[4],selectedTeams[5]);
        winner[3]= match.simulateMatchAndGetWinner(selectedTeams[6],selectedTeams[7]);
    }

    if(initialRound==SEMI_FINAL)
    {
        chooseTeamsForTournament(4);
        userInterface.print("\n\n--- SEMI-FINALS MATCHES  ---\n",userInterface.COLOR_GREEN);
        winner[0]= match.simulateMatchAndGetWinner(selectedTeams[0],selectedTeams[1]);
        winner[1]= match.simulateMatchAndGetWinner(selectedTeams[2],selectedTeams[3]);
    }
    else if(initialRound==QUARTER_FINAL)
    {
        userInterface.print("\n\n--- SEMI-FINALS RESULTS ---\n",userInterface.COLOR_GREEN);
        winner[0]= match.simulateMatchAndGetWinner(*winner[0],*winner[1]);
        winner[1]= match.simulateMatchAndGetWinner(*winner[2],*winner[3]);
    }

    userInterface.print("\n\n--- FINAL MATCH ---\n",userInterface.COLOR_GREEN);
    if(initialRound==FINAL)
    {
        chooseTeamsForTournament(2);
        winner[0]= match.simulateMatchAndGetWinner(selectedTeams[0],selectedTeams[1]);
    }
    else 
        winner[0] = match.simulateMatchAndGetWinner(*winner[0],*winner[1]);

    userInterface.print("\n\n--- WINNER OF THE TOURNAMENT ---\n",userInterface.COLOR_GREEN);
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