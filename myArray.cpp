#include <iostream>
using namespace std;

main()
{
    // declares arr which is an empty array with an size of 10
    int arr[10];
    /*  for loop which sets the value of each element of the array equal to its index plus 10
    *    and prints the values of said array
    */
    for(int i = 0; i < 10; i++)
    {
        arr[i] = i + 10;
        cout << "myArray[" << i << "]=" << arr[i] << endl;
    }
    return 0;
}