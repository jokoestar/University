//DISPLAY 15.7 Using Derived Classes
#include <iostream>
#include "HourlyEmployee.h"
#include "SalariedEmployee.h"
#include "Administrator.h"
#include "CommissionEmployee.h"
#include <vector>
using namespace std;

// payday function - using vector of pointers
void paydayPtrs(const vector<Employee*>& employeePtrs);

// payday function - using vector of pointers
void paydaySlices(const vector<Employee>& employeeSlices);

int main( )
{
    //creates vectors to hold employees, employee vectors, and an integer to recieve the number of employees
    vector<Employee*> employeePtrs;
    vector<Employee> employeeSlices;
	int numberEmployees;
    //Welcomes the user and asks for the number of employees
	cout << "Welcome to ABC Corporation!!\n";
	cout << "Enter the number of employees: ";
	cin >> numberEmployees;
	
	// Enter the number of employees
	for (int i=0; i<numberEmployees; i++)
    {
        //Asks for the number of employees and the type of employees and then recieves the type
		cout <<"Enter employee #"<<(i+1)<<":\n";
		string type; 
        cout <<"Enter the type of employee (hourly, salaried, admin, commission):";
        cin >> type;

		// Request an hourly employee
		if (type=="hourly")
		{
			// Construct an HourlyEmployee
			HourlyEmployee * hourly = new HourlyEmployee();

			// Prompt for input
			hourly->promptInput(cin, cout);

			// Store in the vectors
			employeePtrs.push_back(hourly);
			employeeSlices.push_back(*hourly);
		} 
		else if (type=="salaried")
		{
			// Construct a SalariedEmployee
			SalariedEmployee * mgmt = new SalariedEmployee();

			// Prompt for input
			mgmt->promptInput(cin, cout);

			// Add to the lists
			employeePtrs.push_back(mgmt);
			employeeSlices.push_back(*mgmt);
		} 
		else if (type =="admin")
		// Construct an Adminstrator
		{
   			//Construct an Administrator
			Administrator * admin = new Administrator();

			//Prompt for input
            admin->promptInput(cin, cout);

			//Add to the lists
            employeePtrs.push_back(admin);
            employeeSlices.push_back(*admin);
		}
		else if (type == "commission")
		{
			//Construct a CommissionEmployee
            
            CommissionEmployee * commission = new CommissionEmployee();

			//Prompt for input
            commission->promptInput(cin, cout);
            
			//Add to the lists
            employeePtrs.push_back(commission);
            employeeSlices.push_back(*commission);
		}

   }

	// Print pointers
	paydayPtrs(employeePtrs);
	paydaySlices(employeeSlices);

    //ToDo: free up dynamically allocated memory
    for(int i = 0; i < employeePtrs.size(); i++)
        delete employeePtrs.at(i);
    for(int i = 0; i < employeeSlices.size(); i++)
    {
        employeePtrs.clear();
        employeeSlices.clear();
    }
    return 0;
}

//Payday! 
void paydaySlices(const vector<Employee>& employeeSlices)
{ 
   cout <<"***********************************************\n";
   cout <<"Payday Slices! Print all checks in a batch!\n";
   for (int i=0;i<employeeSlices.size();i++)

   {
   		cout << "Slice Check for " << employeeSlices[i].get_name() << endl;
   		employeeSlices[i].print_check( );
   		cout << endl;
   }
}
//Payday! 
void paydayPtrs(const vector<Employee*>& employeePtrs)
{ 
   cout <<"***********************************************\n";
   cout <<"Payday Virtual! Print all checks in a batch!\n";
   for (int i=0;i<employeePtrs.size();i++)
   {
   		cout << "Virtual Check for " << employeePtrs[i]->get_name() << endl;
   		employeePtrs[i]->print_check( );
   		cout << endl;
   }
}
