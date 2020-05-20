#include <iostream>
using namespace std;
#include <cstdlib> // required for rand()
int main()
{
    //sets the seed equal to 17 for rand()
	srand(17);
	//this is a constant equal to the size of the array
    const int ARRAYSIZE = 20;
    //this is an empty array of 20 integers
    int randArray[ARRAYSIZE];
	// sets all elements in randArray to be a random number between 0 and 99
	for(int i = 0; i < ARRAYSIZE; i++)
	    randArray[i] = rand() % 100;
	//prints all elements in randArray
	for(int i = 0; i < ARRAYSIZE; i++)
	    cout << "randArray[" << i << "]=" << randArray[i] << endl;
    return 0;
}