#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int SIZE = 50;//a global constant used for the maximum number of elements in the arrays
int highestPay(double grossPay[SIZE]);//recieves an array of doubles and returns the index of the number with the largest value
int lowestPay(double grossPay[SIZE]);//recieves an array of doubles and returns the index of the number with the largest value
string getEmployeeName(); //recieves input from the user and returns "" if the user wants to quit to avoid the array initializing an extra value in the array and otherwise returns the inputed string 
int getNumEmployees(string employees[SIZE]);//uses uninitialized values in an array to find the number of initialized values
int getNumEmployees(double grossPay[SIZE]);//finds the index corresponding to the largest value for pay by iterating through the array grossPay and finding the highest value
double getTotalHours(double hours[SIZE][7], int index);//finds the index corresponding to the largest value for pay by iterating through the array grossPay and finding the lowest value

int main()
{
	//An array of strings for the employee names able to hold SIZE employees
	string  employees[SIZE];
	//Arrays of double for hourly pay and gross pay able to hold SIZE employees
    double hourlyPay[SIZE], grossPay[SIZE];
	//A 2-D array of doubles for the hours of SIZE employees and a 7 day week.
    double hours[SIZE][7];

	//Makes it so output to the console outputs to two decimal places for doubles
    cout << fixed << setprecision(2);
    
    //prompts the user to input the employee names and places the inputs in the array employees
    string name;
    for(int i = 0; i < SIZE; i++)
    {
        cout << "Enter an employee name: ";
        name = getEmployeeName();
        if(name == "")
            break;
        employees[i] = name;
    }
    
    int numEmployees = getNumEmployees(employees);//declares and initializes an integer with a value equal to the number of employees
    
    //promtps the user to input the hourly pay rates for the employees and places the hours in the corresponding memory locations in the array
    for(int i = 0; i < numEmployees; i++)
    {
        cout << "Enter " << employees[i] << "'s hourly pay rate: ";
        cin >> hourlyPay[i];
    }
    
    //prompts the user to input the hours worked by the employees for y days and populates the array hours with it
    for(int i = 0; i < numEmployees; i++)
    {
        cout << "Enter " << employees[i] << "'s hours for 7 days (0 if day off): ";
        for(int j = 0; j < 7; j++)
            cin >> hours[i][j];
    }
    
    //calculates the gross pay and populates the array grossPay with the values
    for(int i = 0; i < numEmployees; i++)
        grossPay[i] = (getTotalHours(hours, i))*(hourlyPay[i]);
        
    //prints the names, hours, and gross pay of all of the employees    
    cout << setw(20) << "Employee Name" << setw(12) << "Total Hours" << setw(10) << "Gross Pay" << endl;
    for(int i = 0; i < numEmployees; i++)
        cout << setw(20) << employees[i] << setw(12) << getTotalHours(hours, i) << setw(10) << grossPay[i] << endl;

    //prints out the names and gross pay of the employees who made the most and least in the 7 day period
    cout << "Highest Pay: $" << grossPay[highestPay(grossPay)] << " " << employees[highestPay(grossPay)] << endl;
    cout << "Lowest Pay: $" << grossPay[lowestPay(grossPay)] << " " << employees[lowestPay(grossPay)] << endl;

    return 0;
}

string getEmployeeName()//recieves input from the user and returns "" if the user wants to quit to avoid the array initializing an extra value in the array and otherwise returns the inputed string 
{
    string firstName, lastName;
    cin >> firstName;
    if(firstName != "quit")
        {
            cin >> lastName;
        return firstName + " " + lastName;
        }
    else
        return "";
}
//uses uninitialized values in an array to find the number of initialized values
int getNumEmployees(string employees[])
{
    int i = 0;
    while(employees[i] != "" && i < SIZE)
        i++;
    return i;
}

//uses uninitialized values in an array to find the number of initialized values
int getNumEmployees(double grossPay[SIZE])
{
    int i = 0;
    while(grossPay[i] != 0 && i < SIZE)
        i++;
    return i;
}

//recieves a two dimensional array of doubles and an integer and uses them to find the total number of hour values in a column corresponding to the index
double getTotalHours(double hours[SIZE][7], int index)
{
    double totalHours = 0;
    for(int i = 0; i < 7; i++)
        totalHours += hours[index][i];
    return totalHours;
}

//finds the index corresponding to the largest value for pay by iterating through the array grossPay and finding the highest value
int highestPay(double grossPay[SIZE])
{
    int high = -99999, highIndex = -1;
    for(int i = 0; i < getNumEmployees(grossPay); i++)
    {
        if(grossPay[i] > high)
            {
                high = grossPay[i];
                highIndex = i;
            }
    }
    return highIndex;
}

//finds the index corresponding to the largest value for pay by iterating through the array grossPay and finding the lowest value
int lowestPay(double grossPay[SIZE])
{
    int low = 99999, lowIndex = -1;
    for(int i = 0; i < getNumEmployees(grossPay); i++)
    {
        if(grossPay[i] < low)
            {
                low = grossPay[i];
                lowIndex = i;
            }
    }
    return lowIndex;
}