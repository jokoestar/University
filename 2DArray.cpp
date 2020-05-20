#include <iostream>
using namespace std;
#include <iomanip>
int main()
{
    //declares array of multArraySize1D times multArraySize2D elements
    const int multArraySize1D = 12, multArraySize2D = 10;
    int multArray[multArraySize1D][multArraySize2D];
    //sets the values of multArray equal to their index plus 1 multiplied by eachother
    for(int i = 0; i < multArraySize1D; i++)
        for(int j = 0; j < multArraySize2D; j++)
            multArray[i][j] = (i + 1)*(j + 1);
    //prints a matrix of all values in the array
    for(int i = 0; i < multArraySize1D; i++)
    {
        for(int j = 0; j < multArraySize2D; j++)
            cout << setw(6) << multArray[i][j];
        cout << endl;
    }
    return 0;
}