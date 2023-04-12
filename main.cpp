#include <iostream>
#include <stdlib.h>
#include "Tournaments/asia_tournament.h"
#include "Tournaments/euro_tournament.h"
#include "Tournaments/africa_tournament.h"


using namespace std;

void simulateMatch();
void printTeamInfo();
void simulateTournament();

int main()
{
    Tournament *tournament;
    
    AsiaTournament asia;
    tournament=&asia;
    tournament->simulateTournament(FINAL);

    EuroTournament euro;
    tournament=&euro;
    tournament->simulateTournament(QUARTER_FINAL);
    return 0;
}