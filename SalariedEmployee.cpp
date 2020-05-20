//Implementation for the Derived Class SalariedEmployee 
//This is the file salariedemployee.cpp.
//This is the implementation for the class SalariedEmployee.
//The interface for the class SalariedEmployee is in 
//the header file salariedemployee.h.
#include "SalariedEmployee.h"
using namespace std;


//This is the default constuctor for the SalariedEmployee
SalariedEmployee::SalariedEmployee( ) : Employee( ), salary(0)
{
    //deliberately empty
}

//This is a constructor for the SalariedEmployee class which has a variable for every instance variable of the SalariedEmployee
//Parameter the_name: name is changed to the value of this variable
//Parameter the_ssn: ssn is changed to the value of this variable
//Parameter the_weekly_salary: salary is changed to the value of this variable
SalariedEmployee::SalariedEmployee(string the_name, string the_number, double the_weekly_salary) : Employee(the_name, the_number), salary(the_weekly_salary)
{
	//deliberately empty
}
	
//Accessor Functions
		
//This is an Accessor function which returns the salary of the SalariedEmployee
//Precondition: salary is initialized
//Postcondition: salary is returned
//Returns: salary
double SalariedEmployee::get_salary( ) const 
{
    return salary;
}


//Mutator Function(s)

//This is a mutator function which chnages the salary of the SalariedEmployee
//Parameter new_salary: This is a double which salary's value is changed to
//Precondition: Memory is available for the new salary to be added
//Postcondition: salary is set equal to the value of new_salary
void SalariedEmployee::set_salary(double new_salary)
{
    salary = new_salary;
}


//Virtual functions

//This is a function which displays the net pay of the SalariedEmployee on the console
//Precondition: The salary is initialized
//Postcondition: The salary which represents the net pay is initialized
double SalariedEmployee::get_net_pay() const
{
	return salary;
}

//This function prints the SalariedEmployee's check
//Precondition: The SalariedEmployee is initialized
//Postcondition: The SalariedEmployee's check is printed to the console
void SalariedEmployee::print_check( ) const
{
	Employee::print_check();
    cout << "Salaried Employee. Regular Pay: " << salary << endl; 
    cout << "_________________________________________________\n";
}

//This function prints the user for the SalariedEmployee's information. This includes the name, ssn, and salary
//Parameter in: This is a pointer to an istream used to recieve the name, ssn, and salary of the SalariedEmployee from the user
//Parameter out: This is a pointer to an ostream used to prompt the user to input the name, ssn, and salary
//Precondition: The user is prompted to input the information about the SalariedEmployee. The string variables can have spaces and the numerical ones cannot
//Postcondition: THe instance variable's values are all changed to the user inputed values
istream & SalariedEmployee::promptInput(istream & in, ostream & out)
{
	Employee::promptInput(in, out);
	out << "Enter weekly salary: ";
	in >> salary;
	return in;
}
