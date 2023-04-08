#include<iostream>

#include "match.h"

using namespace std;

void SimulateMatch();
void PrintTeamInfo();

int main()
{

    //SimulateMatch();
    PrintTeamInfo();
    
    return 0;
}

void SimulateMatch()
{
   Team host("Manchester United", "Alex", 10, 10);
   Team guest("Real Madrid", "Carlo", 10, 5);

   Match match(host,guest);
   match.simulateMatch();
}

void PrintTeamInfo()
{
    Team team("FC Barcelona", "Xavi", 10, 10);
    Player player1("Robert Lewandowski",PlayerStats(10,32,12),STRIKER);
    Player player2("Gavi", PlayerStats(42,12,43), MIDFIELDER);
    Player player3("Sergio Roberto", PlayerStats(42,12,42), DEFENDER);
    Player player4("Ter Stegen", PlayerStats(72,12,42), DEFENDER);
    team.addPlayer(player1);
    team.addPlayer(player2);
    team.addPlayer(player3);
    team.addPlayer(player4);
    team.printTeam();
}