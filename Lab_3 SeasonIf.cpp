// SeasonIf.cpp 
/* Instructions
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

	//Recieves month number and makes sure th emonth number recieved is between 1 and 12
	cout << "Enter a month number :";
	cin >> month;

	if(month < 0 || month > 12)
	{
	 	cout << " Invalid month. Enter number 1-12 " << endl;
		return 0;
	}
	//Outputs the month corresponding to the recieved month number
	if(month == 12 || month == 1 || month == 2)
	{
		 cout << " It is Winter" << endl;
	}
	if(month > 2 && month < 6)
	{
		 cout << " It is Spring" << endl;
	}
	if(month > 5 && month < 9)
	{
		 cout << " It is Summer" << endl;
	}
	if(month > 8 && month < 12){
		cout << " It is Fall" << endl;
	}
	
	return 0;
}
