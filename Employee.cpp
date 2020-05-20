//DISPLAY 15.2 Implementation for the Base Class Employee
//This is the file: employee.cpp. 
//This is the implementation for the class Employee.
//The interface for the class Employee is in the header file employee.h.
#include <string>
#include <cstdlib>
#include <iostream>
#include "Employee.h"
#include <iomanip>
#include <cctype>
using namespace std;


//Constructors

//This is the default constuctor for the Employee
Employee::Employee( ) : name("No name yet"), ssn("No number yet")
{
    //deliberately empty
}

//This is a constructor for the Employee class which has a variable for every instance variable of the Employee
//Parameter the_name: name is changed to the value of this variable
//Parameter the_ssn: ssn is changed to the value of this variable
Employee::Employee(string the_name, string the_number) 
       : name(the_name), ssn(the_number)
{
    //deliberately empty
    //cout <<"Employee( " <<the_name <<","<<the_number <<")called\n";
}

//Accessor Function(s)
	
//This is an accessor function which returns the name of the Employee
//Precondition: name is initialized
//Postcondition: name is returned
//Returns: name
string Employee::get_name( ) const 
{
    return name;
}

//This is an accessor function which returns the ssn of the Employee
//Precondition: ssn is initialized
//Postcondition: ssn is returned
//Returns: ssn
string Employee::get_ssn( ) const 
{
    return ssn;
}

//This is a mutator function which chnages the name of the Employee
//Parameter new_name: This is a double which name's value is changed to
//Precondition: Memory is available for the new name to be added
//Postcondition: ssn is set equal to the value of new_name
void Employee::set_name(string new_name)
{
    name = new_name;
}

//This is a mutator function which chnages the ssn of the Employee
//Parameter new_name: This is a double which ssn's value is changed to
//Precondition: Memory is available for the new ssn to be added
//Postcondition: ssn is set equal to the value of new_ssn
void Employee::set_ssn(string new_ssn)
{
    ssn = new_ssn;
}

//Virtual functions
		
//This is a virtual function intended to be inherited by child classes which will print the net pay of the Employee
//Returns: 0.0
double Employee::get_net_pay() const
{
	return 0.0;
}

//This function prints the Employee's check
//Precondition: The Employee is initialized
//Postcondition: The Employee's check is printed to the console
void Employee::print_check( ) const
{
    cout << "\n_______________________________________________\n" ;
    cout << "Pay to the order of " << get_name( ) << endl;
    cout << "The sum of " << get_net_pay( ) << " Dollars\n";
    cout << "__ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __ __\n";
    cout << "Employee Number: " << get_ssn( ) << endl;
}

//This function prints the user for the Employee's information. This includes the name and ssn
//Parameter in: This is a pointer to an istream used to recieve the name, and ssn of the Employee from the user
//Parameter out: This is a pointer to an ostream used to prompt the user to input the name and ssn
//Precondition: The user is prompted to input the information about the Employee. The string variables can have spaces and the numerical ones cannot
//Postcondition: THe instance variable's values are all changed to the user inputed values
istream & Employee::promptInput(istream & in, ostream & out)
{
	out << "Enter name and ssn (each on its own line):" << endl;
	return operator>>(in, *this);
}


//These are the protected functions

//This funcion ignores spaces in the input recieved on the istream
 //Parameter in: This is a pointer to the istream used for testing
//Precondition: There is information on the istream
//Postcondition: If there is a space, ungets the space on the istream. Regardless of the presence of a space, returns a pointer to the istream
//Returns: a pointer to the istream
istream& Employee::ignorespace(istream& in) const
{
	if (!isspace(in.get())) in.unget();
	return in;
}

//This is an operator which uses the input of the istream to change the instance variables in the Employee and returns the istream
//Parameter in: This is a pointer to an istream which is used to change the value of the instance variables
//Precondition: There is available memory for the istream and Employee
//Postcondition: Changes the values of the istream and variables
//Returns a pointer to the istream
istream& operator>>(istream& in, Employee& empl)
{
	empl.ignorespace(in);
	getline(in, empl.name);
	getline(in, empl.ssn);
	return in;
}

