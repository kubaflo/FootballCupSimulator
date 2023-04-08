#include "team.h"
#include "match.h"
#include <vector>
#include <algorithm>
#include <random>

class Tournament
{
    public:
        void addTeam(Team team);
        void simulateTournament();

    private:
        std::vector<Team> allTeams;
        std::vector<Team> selectedTeams;
        void chooseTeamsForTournament();
};

void Tournament::addTeam(Team team) { allTeams.push_back(team); }

void Tournament::chooseTeamsForTournament()
{
    for(int i=0;i<allTeams.size();i++)
        selectedTeams.push_back(allTeams[i]);
}

void Tournament::simulateTournament()
{
    if(allTeams.size()<4)
    {
        std::cout<<"Tournament needs to have 4 teams!"<<std::endl;
        return;
    }

    chooseTeamsForTournament();

    std::cout<<std::endl<<std::endl<<"=====Semifinal I====="<<std::endl;
    Match semifinal1(allTeams[0],allTeams[1]);
    Team semifinal1Winner=semifinal1.simulateMatchAndGetWinner();

    std::cout<<std::endl<<std::endl<<"=====Semifinal 2====="<<std::endl;
    Match semifinal2(allTeams[2],allTeams[3]);
    Team semifinal2Winner=semifinal2.simulateMatchAndGetWinner();

    std::cout<<std::endl<<std::endl<<"=====Final====="<<std::endl;
    Match final(semifinal1Winner,semifinal2Winner);
    Team finalWinner=final.simulateMatchAndGetWinner();

    std::cout<<std::endl<<std::endl<<"WINNER"<<std::endl;
    finalWinner.printTeam();


}