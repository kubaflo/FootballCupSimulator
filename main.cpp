#include<iostream>

#include "match.h"

using namespace std;

int main()
{

   Team team1("MyTeam", "Coach", 10, 10);
   Team team2("MyTeam2", "Coach", 10, 10);

    // Player player1("John", PlayerStats(10, 8, 9), STRIKER);
    // Player player2("Mary", PlayerStats(8, 10, 7), MIDFIELDER);
    // Player player3("Peter", PlayerStats(7, 9, 10), DEFENDER);

    // team.addPlayer(player1);
    // team.addPlayer(player2);
    // team.addPlayer(player3);

    // team.selectLineup();
    // team.printTeam();

    Match match(team1,team2);
    match.simulateMatch();
    match.printMatchStats();
    
    return 0;
}