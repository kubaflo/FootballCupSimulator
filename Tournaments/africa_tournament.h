#ifndef AFRICATOURNAMENT_H
#define AFRICATOURNAMENT_H

#include "tournament.h"

class AfricaTournament : public Tournament
{
    void generateTeams() override
    {
        allTeams.push_back(Team("Algeria", "Djamel Belmadi"));
        allTeams.push_back(Team("Egypt", "Hossam El-Badry"));
        allTeams.push_back(Team("Nigeria", "Gernot Rohr"));
        allTeams.push_back(Team("Senegal", "Aliou Cisse"));
        allTeams.push_back(Team("Cameroon", "Antonio Conceicao"));
        allTeams.push_back(Team("Ivory Coast", "Patrice Beaumelle"));
        allTeams.push_back(Team("Morocco", "Vahid Halilhodzic"));
        allTeams.push_back(Team("Ghana", "CK Akonnor"));
        allTeams.push_back(Team("Tunisia", "Mondher Kebaier"));
        allTeams.push_back(Team("Mali", "Mohamed Magassouba"));
        allTeams.push_back(Team("South Africa", "Hugo Broos"));
        allTeams.push_back(Team("DR Congo", "Christian Nsengi"));
        allTeams.push_back(Team("Zambia", "Milutin Sredojevic"));
        allTeams.push_back(Team("Burkina Faso", "Kamou Malo"));
        allTeams.push_back(Team("Guinea", "Lappe Bangoura"));
        allTeams.push_back(Team("Uganda", "Abdallah Mubiru"));
        allTeams.push_back(Team("Benin", "Michel Dussuyer"));
        allTeams.push_back(Team("Cape Verde", "Beto Cardoso"));
        allTeams.push_back(Team("Libya", "Jalal Damja"));
        allTeams.push_back(Team("Mauritania", "Corentin Martins"));

        addPlayersToTeams();
    }
};
#endif