// SeasonSwitch.cpp
/*
Use the IF statements of SeasonIf with SWITCH statements to perform the same logic.


Ask the user to enter a month number between 1 and 12.

The following seasons are associated with these months:

Winter: 12, 1, 2

Spring: 3, 4, 5

Summer: 6, 7, 8

Fall: 9, 10, 11

Example:

Enter a month number: 10

It is Fall

Also: Check for legal input (valid entries are 1-12). If not a legal number output:

"Invalid month. Enter number 1-12"
*/
#include <iostream>
using namespace std;

int main()
{
	int month;

	cout << "Enter a month number: ";
	cin >> month;

	switch(month)
	{
		case 12:
		case 1:
		case 2:
			cout << "It is Winter" << endl;
			return 0;

		case 3:
		case 4:
		case 5:
			cout << "It is Spring" << endl;
			return 0;

		case 6:
		case 7:
		case 8:
			cout << "It is Summer" << endl;
			return 0;

		case 9:
		case 10:
		case 11:
			cout << "It is Fall" << endl;
			return 0;
	}
	cout << "Invalid month. Enter number 1-12" << endl;
	return 0;
}
