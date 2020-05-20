//#pragma once
#include "Employee.h"

//Header Guard
#ifndef _COMMISSION_H
#define _COMMISSION_H


//This is the CommissionEmployee class which has a name, an ssn, sales, and a commission_percent which represents the percent made from sales
class CommissionEmployee : public Employee
{
  //These are the public functions
  public:
	// Constructors
	
	//This is the default constuctor for the CommissionEmployee
    CommissionEmployee();

    //This is a constructor for the CommissionEmployee class which has a variable for every instance variable of the CommissionEmployee
    //Parameter the_name: name is changed to the value of this variable
	//Parameter the_ssn: ssn is changed to the value of this variable
	//Parameter the_sales: sales is changed to the value of this variable
	//Parameter the_commission_percent: commission_percent is changed to the value of this variable
    CommissionEmployee(string the_name, string the_ssn, int the_sales, double the_commission_percent);


    //Accessor functions
        
	//This is an accessor function which returns the sales of the CommissionEmployee
	//Precondition: sales is initialized
	//Postcondition: sales is returned
	//Returns: sales
    int get_sales() const;
    
    //This is an accessor function which returns the commission_percent of the CommissionEmployee
	//Precondition: commission_percent is initialized
	//Postcondition: commission_percent is returned
	//Returns: commission_percent
    double  get_commission_percent() const;
    
    
    //Mutator functions
        
    //This is a mutator function which chnages the sales of the CommissionEmployee
    //Parameter new_sales: This is a double which sales's value is changed to
    //Precondition: Memory is available for the new sales to be added
    //Postcondition: sales is set equal to the value of new_sales
    void set_sales(int new_sales);
    
    //This is a mutator function which chnages the commission_percent of the CommissionEmployee
    //Parameter new_commission_percent: This is a double which commission_percent's value is changed to
    //Precondition: Memory is available for the new commission_percent to be added
    //Postcondition: commission_percent is set equal to the value of new_commission_percent
    void set_commission_percent(double new_commission_percent);
    

	//Virtual functions
		
	//This is a function which displays the net pay of the CommissionEmployee on the console
    //Precondition: The sales and commission_percent initialized
    //Postcondition: The sales and the commission_percent whose product represents the net pay are initialized
    //Returns: The product of sales and commission_percent
    virtual double get_net_pay() const;
    
    //This function prints the CommissionEmployee's check
    //Precondition: The CommissionEmployee is initialized
    //Postcondition: The CommissionEmployee's check is printed to the console
    virtual void print_check() const;
    
    //This function prints the user for the CommissionEmployee's information. This includes the name, ssn, sales, and commission_percent
    //Parameter in: This is a pointer to an istream used to recieve the name, ssn, sales, and commission_percent of the CommissionEmployee from the user
    //Parameter out: This is a pointer to an ostream used to prompt the user to input the name, ssn, sales, and commission_percent
    //Precondition: The user is prompted to input the information about the CommissionEmployee. The string variables can have spaces and the numerical ones cannot
    //Postcondition: The instance variable's values are all changed to the user inputed values
    virtual istream& promptInput(istream& in, ostream& out);
    
    //This is an operator which uses the input of the istream to change the instance variables in the CommissionEmployee and returns the istream
    //Parameter in: This is a pointer to an istream which is used to change the value of the instance variables
    //Precondition: There is available memory for the istream and Employee
    //Postcondition: Changes the values of the istream and variables
    //Returns a pointer to the istream
    friend istream& operator >>(istream& in, CommissionEmployee& commission);


//These are the private instance variables of the CommissionEmployee class
private:
	//This is the number of sales of the CommissionEmployee
	int sales;
	//This is the commission_percent the CommissionEmployee makes on sales
	double commission_percent;

};

//endif directive to match the ifndef directive of the header guard
#endif // _COMMISSION_H

