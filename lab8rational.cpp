/* 
 * labrational8.cpp:
 *    A driver program that tests the class rational. This file contains your main function.
 *    The program should have a big main do-while loop that does the following:
 *    	1. Give the user a list of operators and read in an operator. No numbers allowed.
 *    	2. Validate that the operator is OK then read in the number of rational operands. Use the operator>>
 *    	3. Apply the operator to the operands and print out the equation or relation with the result.
 *    	4. Loop while the user says Continue?(y or n)
 */
#include "rational8.h"
#include <iostream>
#include <cctype>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


//main program 
int main ()
{
	cout << "Welcome to Rational World!" <<endl;
	cout << endl;

	// Extra credit: in rational class operator>>
	// [5 pts] In the input operator>>, allow the user to enter the value as follows:
	// 	0.45 - You should figure out the numerator is 45, denominator is 100. 
	// 	0.3  - You should figure out the numerator is then 3, denominator is 10.
	//  2.4  - You should figure out the numerator is 24, denominator is 10.
	
    char rerun;

	do{
		// ToDo: Declare necessary local variables
		
		string operator_string;
		rational a, b;
		
		cout << "Enter operator (+,-,*,/,==,>=,<=,!=,<,>,-1 for negation): ";
		
		// read in operator string.
        
        cin >> operator_string;

		// ToDo: Get operands as rationals using the operator>> 
		
        if(operator_string == "-1")
        {
            cout << "Enter the operand (ex. 1/2 or -3/4): ";
            cin >> a;
        }
        else if(operator_string.length() <= 2)
        {
            cout << "Enter the two operands (ex. 1/2 or -3/4): ";
            cin >> a >> b;
        }

        

		// ToDo: Big multiway-if or switch statement with every operator to evaluate
		// and print the answer using operator<< ex. (n1/d1)+(n2/d2)=n2/d3
        
        switch(operator_string.length())
        {
            case 1:
                switch(operator_string.at(0))
                {
                    case '+':
                        cout << "(";
                        cout << a;
                        cout << ")+(";
                        cout << b;
                        cout << ")=";
                        cout << (a + b);
                        cout << endl;
                        break;
                        
                    case '-':
                        cout << "(";
                        cout << a;
                        cout << ")-(";
                        cout << b;
                        cout << ")=";
                        cout << (a - b);
                        cout << endl;
                        break;
                        
                    case '*':
                        cout << "(";
                        cout << a;
                        cout << ")*(";
                        cout << b;
                        cout << ")=";
                        cout << (a * b);
                        cout << endl;
                        break;
                        
                    case '/':
                        cout << "(";
                        cout << a;
                        cout << ")/(";
                        cout << b;
                        cout << ")=";
                        cout << (a / b);
                        cout << endl;
                        break;
                        
                    case '<':
                        cout << "(";
                        cout << a;
                        cout << ")<(";
                        cout << b;
                        cout << ")=";
                        if (a < b)
                            cout << "True";
                        else
                            cout << "False";
                        cout << endl;
                        break;
                        
                    case '>':
                        cout << "(";
                        cout << a;
                        cout << ")>(";
                        cout << b;
                        cout << ")=";
                        if (a > b)
                            cout << "True";
                        else
                            cout << "False";
                        cout << endl;
                        break;
                        
                    default:
                        cout << "Invalid operator!" << endl;
                        break;
                }
                break;
                
            case 2:
                switch(operator_string.at(1))
                {
                    case '=':
                        switch(operator_string.at(0))
                        {
                            case '=':
                                cout << "(";
                                cout << a;
                                cout << ")==(";
                                cout << b;
                                cout << ")=";
                                if(a == b)
                                    cout << "True";
                                else
                                    cout << "False";
                                cout << endl;
                                break;
                                
                            case '!':
                                cout << "(";
                                cout << a;
                                cout << ")!=(";
                                cout << b;
                                cout << ")=";
                                if (a != b)
                                    cout << "True";
                                else
                                    cout << "False";
                                cout<< endl;
                                break;
                                
                            case '>':
                                cout << "(";
                                cout << a;
                                cout << ")>=(";
                                cout << b;
                                cout << ")=";
                                if (a >= b)
                                    cout << "True";
                                else
                                    cout << "False";
                                cout << endl;
                                break;
                                
                            case '<':
                                cout << "(";
                                cout << a;
                                cout << ")<=(";
                                cout << b;
                                cout << ")=";
                                if (a <= b)
                                    cout << "True";
                                else
                                    cout << "False";
                                cout << endl;
                                break;
                            
                            default:
                                cout << "Invalid operator!" << endl;
                                break;
                        }
                        
                        break;
                    
                    case '1':
                        if(operator_string.at(0) == '-')
                        {    cout << "-(";
                            cout << a;
                            cout << ")=";
                            cout << (-a);
                            cout << endl;
                        }
                        else
                            cout << "Invalid operator!" << endl;
                        break;
                    
                    default:
                        cout << "Invalid operator!" << endl;
                        break;
                }
                break;
          
        default:
            cout << "Invalid operator!" << endl;
            break;
        }

		// Use this in case the operator>> fails.
		if (cin.fail()) {
			cin.clear();
			cin.ignore();
		}

		// ToDo: Prompt the user to rerun the simulation 
		cout << "Continue(y/n): " << endl;
		cin >> rerun; 

	} while (rerun == 'y'|| rerun == 'Y'); 

	cout << "Have a nice day!" <<endl;

	return 0;
}


