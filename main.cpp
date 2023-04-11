#include<iostream>
#include "Tournaments/asia_tournament.h"
#include "Tournaments/euro_tournament.h"


using namespace std;

void simulateMatch();
void printTeamInfo();
void simulateTournament();

int main()
{

    EuroTournament euro2021;
    euro2021.simulateTournament(FINAL);

    return 0;
}