#include "CommissionEmployee.h"


//These are the public functions


// Constructors
	
//This is the default constuctor for the CommissionEmployee
CommissionEmployee::CommissionEmployee() : Employee(), sales(0), commission_percent(0.0)
{
    //deliberately empty
}


//This is a constructor for the CommissionEmployee class which has a variable for every instance variable of the CommissionEmployee
//Parameter the_name: name is changed to the value of this variable
//Parameter the_ssn: ssn is changed to the value of this variable
//Parameter the_sales: sales is changed to the value of this variable
//Parameter the_commission_percent: commission_percent is changed to the value of this variable
CommissionEmployee::CommissionEmployee(string the_name, string the_ssn, int the_sales, double the_commission_percent) : Employee(the_name, the_ssn), sales(the_sales), commission_percent(the_commission_percent)
{
    //deliberately empty
}


//Accessor functions
        
//This is an accessor function which returns the sales of the CommissionEmployee
//Precondition: sales is initialized
//Postcondition: sales is returned
//Returns: sales
int CommissionEmployee::get_sales() const
{
    return sales;
}

//This is an accessor function which returns the commission_percent of the CommissionEmployee
//Precondition: commission_percent is initialized
//Postcondition: commission_percent is returned
//Returns: commission_percent
double CommissionEmployee::get_commission_percent() const
{
    return commission_percent;
}


//Mutator functions
        
//This is a mutator function which chnages the sales of the CommissionEmployee
//Parameter new_sales: This is a double which sales's value is changed to
//Precondition: Memory is available for the new sales to be added
//Postcondition: sales is set equal to the value of new_sales
void CommissionEmployee::set_sales(int new_sales)
{
    sales = sales;
}

//This is a mutator function which chnages the commission_percent of the CommissionEmployee
//Parameter new_commission_percent: This is a double which commission_percent's value is changed to
//Precondition: Memory is available for the new commission_percent to be added
//Postcondition: commission_percent is set equal to the value of new_commission_percent
void CommissionEmployee::set_commission_percent(double new_commission_percent)
{
    commission_percent = new_commission_percent;
}


//Virtual functions
		
//This is a function which displays the net pay of the CommissionEmployee on the console
//Precondition: The sales and commission_percent initialized
//Postcondition: The sales and the commission_percent whose product represents the net pay are initialized
//Returns: The product of sales and commission_percent
double CommissionEmployee::get_net_pay() const
{
    // Hint: compensation is commission/100 * sales
    return commission_percent / 100 * sales;
}

//This function prints the CommissionEmployee's check
//Precondition: The CommissionEmployee is initialized
//Postcondition: The CommissionEmployee's check is printed to the console
void CommissionEmployee::print_check() const
{
	Employee::print_check();
    cout << "Commission Employee. \n Gross sales: " << sales << " Commission: " << commission_percent <<   " Pay: " << get_net_pay() << endl; 
    cout << "_________________________________________________\n";
}

//This function prints the user for the CommissionEmployee's information. This includes the name, ssn, sales, and commission_percent
//Parameter in: This is a pointer to an istream used to recieve the name, ssn, sales, and commission_percent of the CommissionEmployee from the user
//Parameter out: This is a pointer to an ostream used to prompt the user to input the name, ssn, sales, and commission_percent
//Precondition: The user is prompted to input the information about the CommissionEmployee. The string variables can have spaces and the numerical ones cannot
//Postcondition: The instance variable's values are all changed to the user inputed values

istream & CommissionEmployee::promptInput(istream& in, ostream& out)
{
	Employee::promptInput(in, out);
	out << "Enter sales and commission: ";
	in >> sales >> commission_percent;
	return in;
}
