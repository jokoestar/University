#include <cmath>
#include <iostream>
using namespace std;

int main()
{
    //Makes it so I can call these methods
    double Degrees2Radians(int degrees);
     void Drawline(char character, int numRepetitions);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(5);
    for(int degrees = 0; degrees <= 360; degrees += 5)
    {
        cout << "sin(" << degrees << ") = " << sin(Degrees2Radians(degrees)) << endl;
        if((degrees % 90) == 0 || degrees == 0) Drawline('-', 30);
    }
    return 0;
}

double Degrees2Radians(int degrees)//recieves a degree value and returns its value in radians
{
    return degrees*3.14159/180;
}
//prints a line consisting of a number of characters equal to the integer value recieved and adds a newline character to the end 
void Drawline(char character, int numRepetitions)
{
    for(int i = 0; i < numRepetitions; i++) cout << character;
    cout << endl;
}