#include<iostream>

#include "team.h"

using namespace std;

int main()
{

   Team team("MyTeam", "Coach", 10, OFFENSIVE);

    Player player1("John", PlayerStats(10, 8, 9), STRIKER);
    Player player2("Mary", PlayerStats(8, 10, 7), MIDFIELDER);
    Player player3("Peter", PlayerStats(7, 9, 10), DEFENDER);

    team.addPlayer(player1);
    team.addPlayer(player2);
    team.addPlayer(player3);

    team.selectLineup();
    team.printTeam();
    
    return 0;
}