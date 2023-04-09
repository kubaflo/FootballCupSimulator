#ifndef ASIATOURNAMENT_H
#define ASIATOURNAMENT_H

#include "tournament.h"

class AsiaTournament : public Tournament
{
    void generateTeams() override
    {
        allTeams.push_back(Team("South Korea", "Paulo Bento"));
        allTeams.push_back(Team("China", "Li Tie"));
        allTeams.push_back(Team("India", "Igor Stimac"));
        allTeams.push_back(Team("Thailand", "Akira Nishino"));
        allTeams.push_back(Team("Iran", "Dragan Skocic"));
        allTeams.push_back(Team("Saudi Arabia", "Hervé Renard"));
        allTeams.push_back(Team("Uzbekistan", "Hector Cuper"));
        allTeams.push_back(Team("Iraq", "Srecko Katanec"));
        allTeams.push_back(Team("Qatar", "Félix Sánchez"));
        allTeams.push_back(Team("United Arab Emirates", "Bert van Marwijk"));
        allTeams.push_back(Team("Australia", "Graham Arnold"));
        allTeams.push_back(Team("Lebanon", "Liviu Ciobotariu"));
        allTeams.push_back(Team("Jordan", "Vital Borkelmans"));
        allTeams.push_back(Team("Syria", "Hussein Afash"));
        allTeams.push_back(Team("Oman", "Erwin Koeman"));
        allTeams.push_back(Team("Kyrgyzstan", "Aleksandr Krestinin"));
        allTeams.push_back(Team("Bahrain", "Helio Sousa"));
        allTeams.push_back(Team("Palestine", "Noureddine Ould Ali"));
        allTeams.push_back(Team("Vietnam", "Park Hang-seo"));

        addPlayersToTeams();
    }
};
#endif