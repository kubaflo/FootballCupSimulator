#include<iostream>
#include "Tournaments/asia_tournament.h"
#include "Tournaments/euro_tournament.h"


using namespace std;

void simulateMatch();
void printTeamInfo();
void simulateTournament();

int main()
{

    AsiaTournament euro2020;
    euro2020.simulateTournament();

    EuroTournament euro2021;
    euro2021.simulateTournament();

    return 0;
}