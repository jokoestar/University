/*********************************************************************
 Lab3.cpp

   This program uses dynamic arrays to store login information for
four labs.  Each of the four labs is referenced by the labs[] array
which is indexed from 0-3.  A pointer in the labs[] array then
references a dynamic array that is of size for however many computers
are in that lab.

Written by: Joshua Kohler
Last modified on: 2/12/2020 at 2:18
Known bugs: none
*********************************************************************/

#include <iostream>

using namespace std;

// Type definition
typedef int* IntPtr;

// Constants
const int NUMLABS = 4;

// Function prototypes

/*
 Creates the dynamic arrays for the labs.
 @param labs: the array of labs,
 @param labsizes: contains the size (or number of computers) of each lab
  This dictates the size of the dynamic array.
 @precondition: labsize[0] is the # of computers in lab1,
                labsize[1] is the # of computers in lab2, ...
 @postcondition: labs[0] points to lab1's array (of size given by labsize[0])
      labs[1] points to lab2's array (of size given by labsize[1])
        ...
*/
void createArrays(IntPtr labs[], int labsizes[]);

/* 
freeArrays:
Releases memory we allocated with "new".
*/
void freeArrays(IntPtr labs[]);


/*
showLabs:
Displays the status of all labs (who is logged into which computer).
*/
void showLabs(IntPtr labs[], int labsizes[]);


// ======================
// login:
// Simulates a user login by asking for the login info from
// the console.
// ======================
void login(IntPtr labs[], int labsizes[]);


// ======================
// logout:
// Searches through the arrays for the input user ID and if found
// logs that user out.
// ======================
void logout(IntPtr labs[], int labsizes[]);


// ======================
// search:
// Searches through the arrays for the input user ID and if found
// outputs the station number.
// ======================
void search(IntPtr labs[], int labsizes[]);


// ======================
//     main function
// ======================
int main()
{
	IntPtr labs[NUMLABS]; 	// store the pointers to the dynamic array for each lab
	int labsizes[NUMLABS];	// Number of computers in each lab
	int choice = -1;
	
	cout <<"Welcome to the LabMonitorProgram!\n";

	// Prompt the user to enter labsizes 
	cout <<"Please enter the number of computer stations in each lab:\n"; 
	for (int i=0; i< NUMLABS; i++)
	{
		do
		{
			cout <<"How many computers in Lab "<< i+1<<"?";
			cin >> labsizes[i]; 
		} while (labsizes[i]<0); 
	}

	// Create ragged array structure
	createArrays(labs, labsizes);   

	// Main Menu
	while (choice != 0)
	{
		cout << endl;
		cout << "MAIN MENU" << endl;
		cout << "0) Quit" << endl;
		cout << "1) Simulate login" << endl;
		cout << "2) Simulate logout" << endl;
		cout << "3) Search" << endl;
		cin >> choice;
		if (choice == 1)
		{
			login(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 2)
		{
			logout(labs, labsizes);
			showLabs(labs, labsizes);
		}
		else if (choice == 3)
		{
			search(labs, labsizes);
		}
	}

	freeArrays(labs);		// Free memory before exiting
	cout << "Bye!\n";
	return 0;
}


/*  createArrays:
	Fills the array labs with -1 integer values for the size at labsize[i]
	Precondition: labsizes at [i] is greater than 0
	Postcondition: labs at [i] along index [j] is set to -1
 */

void createArrays(IntPtr labs[], int labsizes[])
{
    for(int lab = 0; lab < NUMLABS; lab++)
    {
        int labsize = labsizes[lab];
        labs[lab] = new int[labsize];
        for(int i = 0; i < labsize; i++)
            labs[lab][i] = -1;
    }
}

/* freeArrays:
  Frees up memory by removing all of the pointers in labs
  Precondition: labs points somewhere
  Postcondition: labs is empty
 */
void freeArrays(IntPtr labs[])
{

  for(int i = 0; i < NUMLABS; i++)
    delete labs[i];
}


/*  showLabs:
    Displays the status of all labs (who is logged into which computer).
	Precondition: labs[] is a multidimension array of labs with computers
				  labsizes[i] contains the size of the array in labs[i]
 */
void showLabs(IntPtr labs[], int labsizes[])
{

	int i;
	int j;

	cout << "LAB STATUS" << endl;
	cout << "Lab #     Computer Stations" << endl;
	for (i=0; i < NUMLABS; i++)
	{
		cout << i+1 << "         ";
		for (j=0; j < labsizes[i]; j++)
		{
			cout << (j+1) << ": ";
			if (labs[i][j] == -1)
			{
				cout << "empty ";
			}
			else
			{
				cout << labs[i][j] << " ";
			}
		}
		cout << endl;
	}
	cout << endl;
	return;
}

/* login:
   Simulates a user login by asking for the login info from the console. 
   Reads the user-id, the lab and the computer then assigns the id to labs[lab-1][computer-1]
   Precondition: labs is a multidimension array of labs with computers
                 labsizes[i] is the size of the array in labs[i]
   Postcondition: labs[lab-1][computer-1] = user-id
 */
void login(IntPtr labs[], int labsizes[])
{
	int id, lab, num = -1;

	// read user id 
	do
	{
  		cout << "Enter the 5 digit ID number of the user logging in:" << endl;
		cin >> id;
	} while ((id < 10000) || (id > 99999));

	// read the lab number 
	do 
	{
		cout << "Enter the lab number the user is logging in from (1-" <<
			NUMLABS << "):" << endl;
		cin >> lab;
	} while ((lab <= 0) || (lab > NUMLABS));

	//read computer number 
	do
	{
		cout << "Enter computer station number the user is logging in to " <<
			"(1-" << labsizes[lab-1] << "):" << endl;
		cin >> num;
	} while ((num <= 0) || (num > labsizes[lab-1]));

	// Check to see if this station is free
	if (labs[lab-1][num-1]!=-1)
	{
		cout << "ERROR, user " << labs[lab-1][num-1] <<
			" is already logged into that station." << endl;
		return;
	}
	// Assign this station to the user
	labs[lab-1][num-1] = id;
	return;
}


/*  logout:
    Asks the user to input an id. The user is logged out of this id if it is not logged in. Otherwise, the program provides an error message
    Precodition: labs and labsizes are initialized
    Postcondition: the value id is removed from labs
 */
void logout(IntPtr labs[], int labsizes[])
{
    
	// Get an ID from the keyboard, validating data ranges (0 - 99999)
    int id;
    cout << "Enter the 5 digit ID number of the user logging in:" << endl;
    cin >> id;
	
    // Check each computer in each labs for the matching ID. Loop the
    // the labs one by one and for each lab, loop the computers in that lab.
	// In the loop, check each computer for a match of the given ID.
	// If a match is found, set the computer in the labs to -1 and return.
	for(int i = 0; i < NUMLABS; i++)
	    for(int j = 0; j < labsizes[i]; j++)
	        if(labs[i][j] == id)
            {
                labs[i][j] = -1;
                cout << "Logout user " << id << " in Lab " << i  + 1 << " at computer "  << j + 1 << endl;
                return;
            }
	// If no match is found, then print that the user is not logged in
	// and return.
    cout << "User not logged in.\n";
}

/* search:
    Promopts the user for an id and prints its location if found. Otherwise, and error message
    Precondition: labs has elements
    Postcondition: the location of id is printed if it exists and otherwise an error message is returned
 */
void search(IntPtr labs[], int labsizes[])
{
    int id;
    cout << "Enter the 5 digit ID number of the user logging in:" << endl;
    cin >> id;
    
    for(int i = 0; i < NUMLABS; i++)
        for(int j = 0; j < labsizes[i]; j++)
        {
            if(labs[i][j] == id)
            {
                cout << "User " << id << " logged in Lab " << i + 1 << " at computer " << j + 1 << endl;
                return;
            }
        }
    cout << "User not logged in.\n";
}








