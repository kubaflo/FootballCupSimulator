#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include "Tournaments/asia_tournament.h"
#include "Tournaments/euro_tournament.h"
#include "Tournaments/africa_tournament.h"


using namespace std;

// Define constants for console colors
const string COLOR_RESET = "\033[0m";
const string COLOR_BOLD = "\033[1m";
const string COLOR_UNDERLINE = "\033[4m";
const string COLOR_RED = "\033[31m";
const string COLOR_GREEN = "\033[32m";
const string COLOR_YELLOW = "\033[33m";
const string COLOR_BLUE = "\033[34m";

int main()
{
    int choice;
    Tournament* tournament;
    InitialRound initialRound;

    while (true)
    {
        // Print menu with options
        cout << endl << COLOR_BOLD << "Select a tournament to simulate:" << COLOR_RESET << endl;
        cout << COLOR_YELLOW << "1. Euro" << endl;
        cout << "2. Africa" << endl;
        cout << "3. Asia" << COLOR_RESET << endl;

        cin >> choice;
        if (choice == 1)
            tournament = new EuroTournament();
        else if (choice == 2)
            tournament = new AfricaTournament();
        else if (choice == 3)
            tournament = new AsiaTournament();

        // Print options for initial round
        cout << endl << COLOR_BOLD << "Select a starting stage:" << COLOR_RESET << endl;
        cout << COLOR_YELLOW << "1. Quarter-Final" << endl;
        cout << "2. Semi-Final" << endl;
        cout << "3. Final" << COLOR_RESET << endl;
        cin >> choice;
        initialRound = choice == 1 ? QUARTER_FINAL : choice == 2 ? SEMI_FINAL : FINAL;
        tournament->simulateTournament(initialRound);

        // Print options for continuing or exiting
        cout << endl << COLOR_BOLD << "What would you like to do next?" << COLOR_RESET << endl;
        cout << COLOR_YELLOW << "1. Back to menu" << endl;
        cout << "2. Close" << COLOR_RESET << endl;
        cin >> choice;

        if (choice == 2)
            break;

        // Clear the console for the next iteration
        system("clear");
    }

    return 0;
}