/* This is the header file for Administrator class */
/* Please finish the definition of the class to provide the following additional members:
 *  1. a string type member variable to store the title (director, Vice President, ... )
 *  3. Constructor functions: one default one, another taking necessary info. about the administrator: name, SSN, salary, title
 *  4. redefine print_check() so that the title is printed on the check. Start with the version from 
 *  SalariedEmployee
 */
 
 //Header guard
#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "SalariedEmployee.h"


class Administrator: public SalariedEmployee
{
  //These are the public functions  
  public:
	//This is the default constructor for the Administrator class
    Administrator();

	//This is a constructor for the Administrator class which has a variable for every instance variable of the Administrator
	//Parameter the_name: name is changed to the value of this variable
	//Parameter the_ssn: ssn is changed to the value of this variable
	//Parameter the_weekly_salary: salary is changed to the value of this variable
	//Parameter the_title: title is changed to the value of this variable
	//Parameter the_bonus: bonus is changed to the value of this variable
    Administrator(string the_name, string the_ssn, double the_weekly_salary, string the_title, double the_bonus);
    
    
	//Accessor functions
	
	//This is an accessor which returns the title of the Administrator
	//Precondition: title is initialized
	//Postcondition: title is returned
	//Returns: title
    string get_title() const;
    
    //This is an accessor which returns the bonus of the Administrator
    //Precondition: bonus is initialized
    //Postcondition: bonus is returned
    //Returns: bonus
    double get_bonus() const;
    
    
    //Getter functions
    
    //This is a mutator whiich changes the title of the Administrator
    //Parameter new_title: This is a string which title's value is replaced with
    //Precondition: Memory is available for the new title to be added
    //Postcondition: title is changed to new_title
    void set_title(string new_title);
    
    //This is a mutator whiich changes the bonus of the Administrator
    //Parameter new_bonus: This is a double which bonus' value is replaced with
    //Precondition: Memory is available for the new bonus to be added
    //Postcondition: bonus is changed to new_bonus
    void set_bonus(double new_bonus);


	//Virtual functions
	
	//This is a function which displays the net pay of the Administrator on the console
	//Precondition: The salary and bonus are initialized
	//Postcondition: The sum of the salary and bonus which represent the net pay are initialized
    virtual double get_net_pay() const;
    
    //This function prints the Administrator's check
    //Precondition: The Administrator is initialized
    //Postcondition: The Administrator's check is printed to the console
    virtual void print_check( ) const;
    
    //This function prints the user for the Administrator's information. This includes the name, ssn, salary, bonus, and title
    //Parameter in: This is a pointer to an istream used to recieve the name, ssn, salary, bonus, and title of the administrator from the user
    //Parameter out: THis is a pointer to an ostream used to prompt the user to input the name, salary, ssn, bonus, and title
    //Precondition: The user is prompted to input the information about the administrator. The string variables can have spaces and the numerical ones cannot
    //Postcondition: THe instance variable's values are all changed to the user inputed values
	virtual istream& promptInput(istream& in, ostream& out);

  //These are the private instance variables of the Administrator class
  private: 
	
	//This is a string which holds the job title of the Administrator
    string title;
    
    //This is a double which holds the bonus pay of the Administrator  
    double bonus;

};
//endif directive to match the ifndef directive of the header guard
#endif
