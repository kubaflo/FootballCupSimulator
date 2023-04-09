#ifndef EUROTOURNAMENT_H
#define EUROTOURNAMENT_H

#include "tournament.h"

class EuroTournament : public Tournament
{
    void generateTeams() override
    {
        allTeams.push_back(Team("France", "Didier Deschamps"));
        allTeams.push_back(Team("Spain", "Luis Enrique"));
        allTeams.push_back(Team("Italy", "Roberto Mancini"));
        allTeams.push_back(Team("Portugal", "Fernando Santos"));
        allTeams.push_back(Team("Netherlands", "Frank de Boer"));
        allTeams.push_back(Team("Germany", "Joachim Löw"));
        allTeams.push_back(Team("Belgium", "Roberto Martinez"));
        allTeams.push_back(Team("England", "Gareth Southgate"));
        allTeams.push_back(Team("Switzerland", "Murat Yakin"));
        allTeams.push_back(Team("Denmark", "Kasper Hjulmand"));
        allTeams.push_back(Team("Sweden", "Janne Andersson"));
        allTeams.push_back(Team("Croatia", "Zlatko Dalić"));
        allTeams.push_back(Team("Russia", "Stanislav Cherchesov"));
        allTeams.push_back(Team("Turkey", "Şenol Güneş"));
        allTeams.push_back(Team("Austria", "Franco Foda"));
        allTeams.push_back(Team("Poland", "Paulo Sousa"));
        allTeams.push_back(Team("Scotland", "Steve Clarke"));
        allTeams.push_back(Team("Czech Republic", "Jaroslav Šilhavý"));
        allTeams.push_back(Team("Ukraine", "Andriy Shevchenko"));
        allTeams.push_back(Team("Wales", "Robert Page"));

        addPlayersToTeams();
    }
};

#endif