//DISPLAY 15.4 Interface for the Derived Class SalariedEmployee
//This is the header file salariedemployee.h. 
//This is the interface for the class SalariedEmployee.

//Header guard
#ifndef SALARIEDEMPLOYEE_H
#define SALARIEDEMPLOYEE_H

#include "Employee.h"
using namespace std;

//This is the SalariedEmployee class which has a name, ssn, and a salary. It inherits from the employee class.
class SalariedEmployee : public Employee
{
    //These are the public functions
    public:
		//This is the default constuctor for the SalariedEmployee
        SalariedEmployee( );
        
        //This is a constructor for the SalariedEmployee class which has a variable for every instance variable of the SalariedEmployee
	    //Parameter the_name: name is changed to the value of this variable
	    //Parameter the_ssn: ssn is changed to the value of this variable
	    //Parameter the_weekly_salary: salary is changed to the value of this variable
        SalariedEmployee (string the_name, string the_ssn, double the_weekly_salary);


		//Accessor Function(s)
		
		//This is an Accessor function which returns the salary of the SalariedEmployee
		//Precondition: salary is initialized
		//Postcondition: salary is returned
		//Returns: salary
        double get_salary( ) const;
        
        
        //Mutator Function(s)
        
        //This is a mutator function which chnages the salary of the SalariedEmployee
        //Parameter new_salary: This is a double which salary's value is changed to
        //Precondition: Memory is available for the new salary to be added
        //Postcondition: salary is set equal to the value of new_salary
        void set_salary(double new_salary); 


		//Virtual functions
		
	    //This is a function which displays the net pay of the SalariedEmployee on the console
	    //Precondition: The salary is initialized
	    //Postcondition: The salary which represents the net pay is initialized
		virtual double get_net_pay() const;
		
		//This function prints the SalariedEmployee's check
        //Precondition: The SalariedEmployee is initialized
        //Postcondition: The SalariedEmployee's check is printed to the console
        virtual void print_check( ) const;
        
        //This function prints the user for the SalariedEmployee's information. This includes the name, ssn, and salary
        //Parameter in: This is a pointer to an istream used to recieve the name, ssn, and salary of the SalariedEmployee from the user
        //Parameter out: This is a pointer to an ostream used to prompt the user to input the name, ssn, and salary
        //Precondition: The user is prompted to input the information about the SalariedEmployee. The string variables can have spaces and the numerical ones cannot
        //Postcondition: THe instance variable's values are all changed to the user inputed values
		virtual istream& promptInput(istream& in, ostream& out);
    
    //These are the private instance variables of the SalariedEmployee class
    private:
        //This is a double which holds the weekly salary of the SalariedEmployee
        double salary;
};

//endif directive to match the ifndef directive of the header guard
#endif
