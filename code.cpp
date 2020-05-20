#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    /*  infile is an ifstream variable which retrieves data from a file
        filename is a string used to store the name of the file read in the program
    */
    ifstream infile;
    string filename;
    
    //  retrieves the filename and opens it
    cout << "Enter the name of the file to be analyzed:";
    cin >> filename;
    infile.open(filename);
    
    //tests whether infile opened a file and if it does not, tells the user so and terminates the program
    if(!infile)
    {
        cout << "File " << filename << " cannot be opened.";
        return 0;
    }
    
    /*  date is a string that stores a date read from the file
        junk is a string that stores the data on the line following the date
        lowDate is a string that stores the date corresponding to the lowest price and highDate the highest
        high is the largest double value of price and low the lowest
        price is a double that stores a price read from the file
    */
    string date, junk, lowDate, highDate;
    double high = -9999.00, price, low = 9999.00;
        
    //truncates printed doubles to two decimal places without rounding
    cout.precision(2);
    cout.setf(ios::fixed);
    
    /*  prints the date and the price from the file after storing them in their respective variables
        note: junk stores the rest of the data contained in a line
        changes the high and low variables to correspond to the highest and lowest double values recieved
    */
    while (infile >> date >> price >> junk)
    {
        cout << date << " " << price << endl;
        if(price > high)
        {
            high = price;
            highDate = date;
        }
        if(price < low)
        {
            low = price;
            lowDate = date;
        }
    }
    //prints the high and low values
    cout << "High: " << high << " on " << highDate << endl;
    cout << "Low:  " << low << " on " << lowDate << endl;
    return 0;
    infile.close();
}