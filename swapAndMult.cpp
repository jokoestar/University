#include <iostream>
using namespace std;
//void method which prints the values of two ints to the console
void print2Ints(int a, int b)
{
    cout << a << " " << b << endl;
}
//void method which uses two integers as parameters and uses pointers to recieve their values from the console
void getTwoInts(int &a, int &b)
{
	cin >> a;
	cin >> b;
	print2Ints(a, b);
}
//void method which uses two integers as parameters and uses pointers to swap their values and print them on the console
void swap(int &a, int &b)
{
	a += b;
	b = a - b;
	a -= b;
	cout << "After swap:\n" ;
	print2Ints(a, b);
}
//void method which uses two integers as parameters and uses pointers to swap and multiply their values and print them on the console
void swapAndMult(int &a, int &b, int multiplier)
{
	a += b;
	b = a - b;
	a -= b;
	a*=multiplier;
	b*=multiplier;
	cout << "After swap and mult:\n";
    print2Ints(a, b);
}
//void method which uses an integer parameter and a pointer to overwrite the value of the integer wth an input from the console
void getMultiplier(int &multiplier)
{
    cout << "Enter the multiplier: ";
    cin >> multiplier;
    cout << multiplier << endl;
}
// gets 2 integers a and b and prints them
// then swap them and prints them again
// get the multiplier value from the user and prints that
// swaps and multiplies the values and prints the values one last time
int main()
{
    int a, b, multiplier;
    cout << "Input two numbers: ";
    getTwoInts(a, b);
    swap(a, b);
    getMultiplier(multiplier);
    swapAndMult(a, b, multiplier);
    return 0;
}
