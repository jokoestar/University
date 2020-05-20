// TODO: Write your campusTravel.cpp code here
#include<iostream>
using namespace std;

int main()
{
    int  distance = 14, xBus = 2, xSubway = 5, xJetpack = 10, travelMethod = 0;
    cout << "You are " << distance << " mile(s) from campus!" << endl;
    for(int turn = 0; distance > 0 && turn < 4; turn++)
    {
        while(travelMethod < 1 || travelMethod > 3)
        {
            cout << "How do you wish to travel? (1 bus, 2 subway, 3 jetpack) ";
            cin >> travelMethod;
            if(travelMethod < 1 || travelMethod > 3) cout << "Invalid choice, try again!" << endl;
        }
        if(travelMethod == 1) distance -= 2;
        if(travelMethod == 2) distance -= 5;
        if(travelMethod == 3) distance -= 10;
        travelMethod = 0;
        if(distance >= 0) cout << "You are " << distance << " mile(s) from campus!" << endl;
        if(distance < 0) cout << "You have over-shot your target!" << endl<< "You lose!" << endl;
    }
    if(distance == 0) cout << "You have won!" << endl;
    if( distance > 0) cout << "You haven't reached your target!" << endl << "You lose!" << endl;
    return 0;
}
