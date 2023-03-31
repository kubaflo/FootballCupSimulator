#include<iostream>

#include "player.h"

using namespace std;

int main()
{
    Player player("Jakub", PlayerStats(10,10,10), STRIKER);

    cout<<player.getName();
    
    return 0;
}