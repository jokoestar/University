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

	int largestFoundSoFar = -1; // anything is larger than this!
	int indexOfLargest = -1;// sign that it is not initialized
	
	// a loop which iterates through the array and sets largestFoundSoFar equal to the larges integer value greater than -1
	// and indexOfLargest equal to the correspoding index
	
	for(int i = 0; i < ARRAYSIZE; i++)
	{
	    if(randArray[i] > largestFoundSoFar)
	        {
	            largestFoundSoFar = randArray[i];
	            indexOfLargest = i;
	        }
	}
	//prints off the largest integer value found and its correspoding index
	cout << "largestFoundSoFar=" << largestFoundSoFar << " at index " << indexOfLargest << endl;
	return 0;
}