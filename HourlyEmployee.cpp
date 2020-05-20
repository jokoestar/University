//Implementation for the Derived Class HourlyEmployee 
//This is the file: hourlyemployee.cpp 
//This is the implementation for the class HourlyEmployee.
//The interface for the class HourlyEmployee is in 
//the header file hourlyemployee.h.
#include "HourlyEmployee.h"


 //These are the public functions


// Constructors

//This is the default constuctor for the HourlyEmployee
HourlyEmployee::HourlyEmployee( ) : Employee( ), wage_rate(0), hours(0)
{
    //deliberately empty
}

		
//This is a constructor for the HourlyEmployee class which has a variable for every instance variable of the HourlyEmployee
//Parameter the_name: name is changed to the value of this variable
//Parameter the_ssn: ssn is changed to the value of this variable
//Parameter the_wage_rate: wage_rate is changed to the value of this variable
//Parameter the_hours: hours is changed to the value of this variable
HourlyEmployee::HourlyEmployee(string the_name, string the_number, double the_wage_rate, double the_hours):
Employee(the_name, the_number), wage_rate(the_wage_rate), hours(the_hours)
{
    //deliberately empty
}


//Accessor functions

//This is an accessor function which returns the wage_rate of the HourlyEmployee
//Precondition: wage_rate is initialized
//Postcondition: wage_rate is returned
//Returns: wage_rate
double HourlyEmployee::get_rate( ) const
{
    return wage_rate;
}

//This is an accessor function which returns the hours of the HourlyEmployee
//Precondition: hours is initialized
//Postcondition: hours is returned
//Returns: hours
double HourlyEmployee::get_hours( ) const
{
    return hours;
}

//This is a mutator function which chnages the wage_rate of the HourlyEmployee
//Parameter new_name: This is a double which wage_rate's value is changed to
//Precondition: Memory is available for the new wage_rate to be added
//Postcondition: ssn is set equal to the value of new_wage_rate
void HourlyEmployee::set_rate(double new_wage_rate)
{
    wage_rate = new_wage_rate;
}



//This is a mutator function which chnages the hours of the HourlyEmployee
//Parameter new_name: This is a double which hours's value is changed to
//Precondition: Memory is available for the new hours to be added
//Postcondition: ssn is set equal to the value of hours
void HourlyEmployee::set_hours(double hours_worked)
{
    hours = hours_worked;
}


//Virtual functions

//This is a function which displays the net pay of the HourlyEmployee on the console
//Precondition: The wage_rate and hours are initialized
//Postcondition: The wage rate and the hours whose product represents the net pay are initialized
//Returns: The product of wage_rate and hours
double HourlyEmployee::get_net_pay() const
{
	return hours * wage_rate;
}

//This function prints the HourlyEmployee's check
//Precondition: The HourlyEmployee is initialized
//Postcondition: The HourlyEmployee's check is printed to the console
void HourlyEmployee::print_check( ) const
{
	Employee::print_check();
    cout << "Hourly Employee. \nHours worked: " << hours 
         << " Rate: " << wage_rate << " Pay: " << get_net_pay( ) << endl; 
    cout << "_________________________________________________\n";
}


//This function prints the user for the HourlyEmployee's information. This includes the name, ssn, wage_rate, and hours
//Parameter in: This is a pointer to an istream used to recieve the name, ssn, wage_rate, and hours of the HourlyEmployee from the user
//Parameter out: This is a pointer to an ostream used to prompt the user to input the name, ssn, wage_rate, and hours
//Precondition: The user is prompted to input the information about the HourlyEmployee. The string variables can have spaces and the numerical ones cannot
//Postcondition: THe instance variable's values are all changed to the user inputed values
istream & HourlyEmployee::promptInput(istream & in, ostream & out)
{
	Employee::promptInput(in, out);
	out << "Enter hours worked and wage rate: ";
	in >> hours >> wage_rate;
	return in;
}


