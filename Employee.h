//DISPLAY 15.1 Interface for the Base Class Employee
//This is the header file employee.h. 
//This is the interface for the class Employee.
//This is primarily intended to be used as a base class to derive
//classes for different kinds of employees.

//Header guard
#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cctype>
using namespace std;

//This is the Employee class which has a name and an ssn
class Employee
{
    //These are the public functions
    public:
		//This is the default constuctor for the Employee
        Employee( );
        
        //This is a constructor for the Employee class which has a variable for every instance variable of the Employee
	    //Parameter the_name: name is changed to the value of this variable
	    //Parameter the_ssn: ssn is changed to the value of this variable
        Employee(string the_name, string the_ssn);


		//Accessor Function(s)
		
		//This is an accessor function which returns the name of the Employee
		//Precondition: name is initialized
		//Postcondition: name is returned
		//Returns: name
        string get_name( ) const;
        
        //This is an accessor function which returns the ssn of the Employee
		//Precondition: ssn is initialized
		//Postcondition: ssn is returned
		//Returns: ssn
        string get_ssn( ) const;

        //This is a mutator function which chnages the name of the Employee
        //Parameter new_name: This is a double which name's value is changed to
        //Precondition: Memory is available for the new name to be added
        //Postcondition: ssn is set equal to the value of new_name
        void set_name(string new_name);
        
        //This is a mutator function which chnages the ssn of the Employee
        //Parameter new_name: This is a double which ssn's value is changed to
        //Precondition: Memory is available for the new ssn to be added
        //Postcondition: ssn is set equal to the value of new_ssn
        void set_ssn(string new_ssn);
 
		//Virtual functions
		
		//This is a virtual function intended to be inherited by child classes which will print the net pay of the Employee
        //Returns: 0.0
        virtual double get_net_pay() const;
        
        //This function prints the Employee's check
        //Precondition: The Employee is initialized
        //Postcondition: The Employee's check is printed to the console
        virtual void print_check() const;
        
        //This function prints the user for the Employee's information. This includes the name and ssn
        //Parameter in: This is a pointer to an istream used to recieve the name, and ssn of the Employee from the user
        //Parameter out: This is a pointer to an ostream used to prompt the user to input the name and ssn
        //Precondition: The user is prompted to input the information about the Employee. The string variables can have spaces and the numerical ones cannot
        //Postcondition: THe instance variable's values are all changed to the user inputed values
		virtual istream& promptInput(istream& in, ostream& out);

        //This is an operator which uses the input of the istream to change the instance variables in the Employee and returns the istream
        //Parameter in: This is a pointer to an istream which is used to change the value of the instance variables
        //Precondition: There is available memory for the istream and Employee
        //Postcondition: Changes the values of the istream and variables
        //Returns a pointer to the istream
		friend istream& operator>>(istream& in, Employee& empl);


    //These are the protected functions
    protected:
        //This funcion ignores spaces in the input recieved on the istream
        //Parameter in: This is a pointer to the istream used for testing
        //Precondition: There is information on the istream
        //Postcondition: If there is a space, ungets the space on the istream. Regardless of the presence of a space, returns a pointer to the istream
        //Returns: a pointer to the istream
		istream& ignorespace(istream& in) const;


    //These are the private instance variables of the Employee class
    private:
        //This is a string which holds the name of the employee
        string name; 
        //This is the ssn which holds the ssn of the employeee
        string ssn;
};

//endif directive to match the ifndef directive of the header guard
#endif //EMPLOYEE_H
