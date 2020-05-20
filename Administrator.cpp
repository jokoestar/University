/* Implement Administrator class */
#include <iostream>
#include "Administrator.h"
#include "SalariedEmployee.h"

using namespace std;

// ToDo: implement the default constructor, remember to call base class constructor
Administrator::Administrator() : SalariedEmployee(), title(""), bonus(0.0)
{
    
}

// ToDo: implement the constructor, remember to call base class constructor
Administrator::Administrator(string the_name, string the_ssn, double the_weekly_salary, string the_title, double the_bonus) : SalariedEmployee(the_name, the_ssn, the_weekly_salary), title(the_title), bonus(the_bonus)
{
	// deliberately empty
	// cout << "Adminstrator(" << name << "," << SSN << "," << salary << "," << title << ")\n"; 
}


// ToDo: implement accessor/mutators
string Administrator::get_title() const
{
    return title;
}

double Administrator::get_bonus() const
{
    return bonus;
}

void Administrator::set_title(string new_title)
{
    title = new_title;
}

void Administrator::set_bonus(double new_bonus)
{
    bonus = new_bonus;
}
// ToDo: implement virtual functions


// ToDo: implement virtual get_net_pay function

double Administrator::get_net_pay() const
{
    return SalariedEmployee::get_net_pay() + bonus;
}
// Hint: compensation is salary + bonus


// ToDo: implement the print_check() function. Follow the model in SalariedEmployee
// Hint: Use the base class print_check()
void Administrator::print_check() const
{
    SalariedEmployee::print_check();
    cout << "Administrator Title: " << title << "\nBonus: " << bonus << " Pay: " << get_net_pay() << "\n_________________________________________________" << endl;

}

// ToDo: implement the promptInput() function. Follow the model in SalariedEmployee
// Hint: Use the base class promptInput()
istream & Administrator::promptInput(istream & in, ostream & out) 
{
	// ToDo: inplement the base class part, follow the model in SalariedEmployee
    SalariedEmployee::promptInput(in, out);
	out << "Enter bonus and title: ";
	in >> bonus;
	getline(in, title);
	return in;

	// ToDo: read the bonus. Use ignorespace() to skip newline.

	


	// ToDo: read the rest of the line for the title


}

