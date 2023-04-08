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
        void generateTeams();
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
    generateTeams();
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

void Tournament::generateTeams()
{
    allTeams.push_back(Team("France", "Didier Deschamps", 80, 85));
    allTeams.push_back(Team("Spain", "Luis Enrique", 75, 80));
    allTeams.push_back(Team("Italy", "Roberto Mancini", 70, 85));
    allTeams.push_back(Team("Portugal", "Fernando Santos", 85, 75));
    allTeams.push_back(Team("Netherlands", "Frank de Boer", 75, 80));
    allTeams.push_back(Team("Germany", "Joachim Löw", 85, 80));
    allTeams.push_back(Team("Belgium", "Roberto Martinez", 90, 75));
    allTeams.push_back(Team("England", "Gareth Southgate", 80, 85));
    allTeams.push_back(Team("Switzerland", "Murat Yakin", 70, 75));
    allTeams.push_back(Team("Denmark", "Kasper Hjulmand", 75, 80));
    allTeams.push_back(Team("Sweden", "Janne Andersson", 70, 75));
    allTeams.push_back(Team("Croatia", "Zlatko Dalić", 75, 80));
    allTeams.push_back(Team("Russia", "Stanislav Cherchesov", 70, 75));
    allTeams.push_back(Team("Turkey", "Şenol Güneş", 75, 75));
    allTeams.push_back(Team("Austria", "Franco Foda", 70, 75));
    allTeams.push_back(Team("Poland", "Paulo Sousa", 80, 75));
    allTeams.push_back(Team("Scotland", "Steve Clarke", 65, 70));
    allTeams.push_back(Team("Czech Republic", "Jaroslav Šilhavý", 70, 75));
    allTeams.push_back(Team("Ukraine", "Andriy Shevchenko", 75, 75));
    allTeams.push_back(Team("Wales", "Robert Page", 70, 75));

    for (auto team : allTeams) 
    {
        for (int i = 0; i < 5; i++) {
            std::string player_name = "Player " + std::to_string(i+1);
            int attack = rand() % 91 + 10; // generate a random number between 10 and 100
            int defence = rand() % 91 + 10; // generate a random number between 10 and 100
            Position position = Position(i % 3); // alternate between the four positions
            PlayerStats stats(attack, defence, 0); // set the player's goal count to 0
            allTeams[i].addPlayer(Player(player_name, stats, position));
        }
    }
}