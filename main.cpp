#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include "Tournaments/asia_tournament.h"
#include "Tournaments/euro_tournament.h"
#include "Tournaments/africa_tournament.h"
#include "user_interface.h"

int main()
{
    int choice;
    Tournament* tournament;
    InitialRound initialRound;
    UserInterface userInterface;
    

    while (true)
    {
        system("clear");
        userInterface.print("Select a tournament to simulate:\n",userInterface.COLOR_YELLOW);
        userInterface.print("1. Euro\n",userInterface.COLOR_RED);
        userInterface.print("2. Africa\n",userInterface.COLOR_RED);
        userInterface.print("3. Asia\n",userInterface.COLOR_RED);

        std::cin >> choice;
        if (choice == 1)
            tournament = new EuroTournament();
        else if (choice == 2)
            tournament = new AfricaTournament();
        else if (choice == 3)
            tournament = new AsiaTournament();

        userInterface.print("\nSelect a starting stage\n",userInterface.COLOR_YELLOW);
        userInterface.print("1. Quarter-Final\n",userInterface.COLOR_RED);
        userInterface.print("2. Semi-Final\n",userInterface.COLOR_RED);
        userInterface.print("3. Final\n",userInterface.COLOR_RED);
        std::cin >> choice;
        initialRound = choice == 1 ? QUARTER_FINAL : choice == 2 ? SEMI_FINAL : FINAL;
        tournament->simulateTournament(initialRound);
        
        userInterface.print("\nWhat would you like to do next?\n",userInterface.COLOR_YELLOW);
        userInterface.print("1. Back to menu\n",userInterface.COLOR_BLUE);
        userInterface.print("2. Close\n",userInterface.COLOR_RED);
        std::cin >> choice;

        if (choice == 2)
            break;

        // Clear the console for the next iteration
    }

    return 0;
}