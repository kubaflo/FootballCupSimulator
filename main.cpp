#include<iostream>

#include "tournament.h"

using namespace std;

void simulateMatch();
void printTeamInfo();
void simulateTournament();

int main()
{

printTeamInfo();
    //simulateMatch();
    simulateTournament();
    
    return 0;
}

void simulateMatch()
{
   Team host("Manchester United", "Alex", 10, 10);
   Team guest("Real Madrid", "Carlo", 10, 5);

   Match match(host,guest);
   match.simulateMatchAndGetWinner();
}

void printTeamInfo()
{
    Team team("FC Barcelona", "Xavi", 10, 10);
    Player player1("Robert Lewandowski",PlayerStats(10,32,12),STRIKER);
    Player player2("Gavi", PlayerStats(42,12,43), MIDFIELDER);
    Player player3("Sergio Roberto", PlayerStats(42,12,42), DEFENDER);
    Player player4("Ter Stegen", PlayerStats(72,12,42), GOALKEEPER);
    team.addPlayer(player1);
    team.addPlayer(player2);
    team.addPlayer(player3);
    team.addPlayer(player4);
    team.printTeam();
}

void simulateTournament()
{
    Team team("Poland", "Pole", 10, 10);
    Team team2("England", "Englishman", 10, 10);
    Team team3("Germany", "German", 10, 10);
    Team team4("Belgium", "Belgian", 10, 10);
    Team team5("Spain", "Spaniard", 10, 10);

    Tournament euro2020;
    euro2020.addTeam(Team("Poland", "Pole", 10, 10));
    euro2020.addTeam(Team("England", "Englishman", 10, 10));
    euro2020.addTeam(Team("Germany", "German", 10, 10));
    euro2020.addTeam(Team("Belgium", "Belgian", 10, 10));
    euro2020.addTeam(Team("Spain", "Spaniard", 10, 10));

    euro2020.simulateTournament();
}