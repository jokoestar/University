#include <iostream>
using namespace std;

int main()
{//begin main function
	
	double cost = 1; //cost per 1 cookie
	int numpurchased; //number of cookies purchased
	double taxrate;
	cout << "Number of Cookies? ";
	cin >> numpurchased;
	cout << "Cookies: " << numpurchased<< " at $" << cost << " each" << endl;
	double subtotal = cost * numpurchased;
	cout << "Subtotal = $" << subtotal << endl;
	cout << "Tax Rate? ";
	cin >> taxrate;
	double tax = taxrate * subtotal;
	cout << "Tax = $" << tax << endl;
	cout << "Total = $" << tax + subtotal;

	return 0; //end funciton
}
