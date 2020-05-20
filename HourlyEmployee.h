//DISPLAY 15.3 Interface for the Derived Class HourlyEmployee
//This is the header file hourlyemployee.h. 
//This is the interface for the class HourlyEmployee.

//Header Guard
#ifndef HOURLYEMPLOYEE_H
#define HOURLYEMPLOYEE_H

#include "Employee.h"


//This is the HourlyEmployee class which has a name, an ssn, a wage_rate in currency per hour, and hours (worked)
class HourlyEmployee : public Employee 
{
    //These are the public functions
    public:
		// Constructors
		
		//This is the default constuctor for the HourlyEmployee
        HourlyEmployee( );
        
        //This is a constructor for the HourlyEmployee class which has a variable for every instance variable of the HourlyEmployee
	    //Parameter the_name: name is changed to the value of this variable
	    //Parameter the_ssn: ssn is changed to the value of this variable
	    //Parameter the_wage_rate: wage_rate is changed to the value of this variable
	    //Parameter the_hours: hours is changed to the value of this variable
        HourlyEmployee(string the_name, string the_ssn, double the_wage_rate, double the_hours);


        //Accessor functions
        
		//This is an accessor function which returns the wage_rate of the HourlyEmployee
		//Precondition: wage_rate is initialized
		//Postcondition: wage_rate is returned
		//Returns: wage_rate
        double get_rate( ) const;
        
        //This is an accessor function which returns the hours of the HourlyEmployee
		//Precondition: hours is initialized
		//Postcondition: hours is returned
		//Returns: hours
        double get_hours( ) const;


        //Mutator functions
        
        //This is a mutator function which chnages the wage_rate of the HourlyEmployee
        //Parameter new_name: This is a double which wage_rate's value is changed to
        //Precondition: Memory is available for the new wage_rate to be added
        //Postcondition: ssn is set equal to the value of new_wage_rate
        void set_rate(double new_wage_rate);
        
        //This is a mutator function which chnages the hours of the HourlyEmployee
        //Parameter new_name: This is a double which hours's value is changed to
        //Precondition: Memory is available for the new hours to be added
        //Postcondition: ssn is set equal to the value of hours
        void set_hours(double hours_worked);


		//Virtual functions
		
	    //This is a function which displays the net pay of the HourlyEmployee on the console
	    //Precondition: The wage_rate and hours are initialized
	    //Postcondition: The wage rate and the hours whose product represents the net pay are initialized
	    //Returns: The product of wage_rate and hours
		virtual double get_net_pay() const;
		
		//This function prints the HourlyEmployee's check
        //Precondition: The HourlyEmployee is initialized
        //Postcondition: The HourlyEmployee's check is printed to the console
        virtual void print_check( ) const;
        
        //This function prints the user for the HourlyEmployee's information. This includes the name, ssn, wage_rate, and hours
        //Parameter in: This is a pointer to an istream used to recieve the name, ssn, wage_rate, and hours of the HourlyEmployee from the user
        //Parameter out: This is a pointer to an ostream used to prompt the user to input the name, ssn, wage_rate, and hours
        //Precondition: The user is prompted to input the information about the HourlyEmployee. The string variables can have spaces and the numerical ones cannot
        //Postcondition: The instance variable's values are all changed to the user inputed values
		virtual istream& promptInput(istream& in, ostream& out);

    //These are the private instance variables of the SalariedEmployee class
    private:
        //This is a double which holds the wage rate of the HourlyEmployee in currency per hour
        double wage_rate; 
        //This is a double which holds the number of hours worked by the employee over a period of time
        double hours;
};

//endif directive to match the ifndef directive of the header guard
#endif //HOURLYMPLOYEE_H
