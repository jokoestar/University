//This program calculates the inflation rate given two Consumer Price Index values and prints it to the monitor. Then, it will ask the user if they want to continue and repeat that process until told to stop and will then print the average inflation rate
#include <vector>
#include <iostream>
using namespace std;

/* calcInflationRate - calculates the inflation rate given the old and new consumer price index
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently 
 * @returns the computed inflation rate or 0 if inputs are invalid.
 */
double calcInflationRate(float old_cpi, float new_cpi);
/* getCPIValues - gets the cpi values from the console
 * @param old_cpi: is the consumer price index that it was a year ago
 * @param new_cpi: is the consumer price index that it is currently
 * @returns: nothing
 */
void getCPIValues(float &old_cpi, float &new_cpi);
/* sort_array - sorts the an array of doubles in ascending order
 * @param MAX_RATES: the size of the array
 * @param cRates: the array itself
 * @returns: nothing
 */
void sort_array(int MAX_RATES, double *cRates[]);
/* swap_values - swaps the values of two doubles
 * @param n1: the first double
 * @param n2: the second double
 * @returns: nothing
 */
void swap_values(double &n1, double &n2);

/* findMedianRate - finds the median of values in an array
 * @param MAX_RATES: the size of the array
 * param cRates: the array
 * @returns: nothing
 */
double findMedianRate(int MAX_RATES, double cRates[]);

int main()   //C++ programs start by executing the function main
{
    //rates stores the cpi rates and a char is used to track the progress of the program
    vector<double> rates;
    char cont = 'y';
    //this is used to note the size of the array
    const int MAX_RATES = 20;
    //this is an array meant to hold the cpi values
    double cRates[MAX_RATES];
    //this is used to track the number of elements in the array
    int aSize;
    for(aSize = 0; aSize < MAX_RATES && (cont == 'y' || cont == 'Y'); aSize++)
    {
        
        //Declares two float variables
        float old_cpi, new_cpi;
        //reads them in from the console and adds it to  the vector and arraylist
        getCPIValues(old_cpi, new_cpi);
        double temp = calcInflationRate(old_cpi, new_cpi);
        if(temp != 0)
        {
            rates.push_back(temp);
            cRates[aSize] = rates.at(aSize);
        }
        //The floats are used to calculate the inflation rate and printed to the console
        cout << "Inflation rate is " << temp << endl << "Try again? (y or Y): ";
        cin >> cont;
    }
    
    //calculates and prints the average and median rate
    double avg = 0;
    for(int i = 0; i < rates.size(); i++)
        avg += rates.at(i);
    avg /= rates.size();
    cout << "Average rate is " << avg << "\nMedian rate is " << findMedianRate(aSize, cRates) << endl;
   return 0;
}


// double calcInflationRate(float old_cpi, float new_cpi)
// precondition:   both prices must be greater than 0.0
// postcondition:  the inflation rate is returned or 0 for invalid inputs
double calcInflationRate(float old_cpi, float new_cpi)
{
    if(old_cpi <= 0 || new_cpi <= 0)
        return 0;
    return ((new_cpi - old_cpi) / old_cpi * (float)100.0);
}
//postcondition: both values are greater than 0
void getCPIValues(float &old_cpi, float &new_cpi)
{
    do
    {
        cout << "Enter the old and new consumer price indices: ";
        cin >> old_cpi >> new_cpi;
        if (old_cpi <= 0 || new_cpi <= 0)
            cout << "Error: CPI values must be greater than 0\n";
    }while(old_cpi <= 0 || new_cpi <= 0);
}

//precondition: MAX_RATES is greater than 1, cRates size is equal to MAX_RATES
void sort_array(int MAX_RATES, double cRates[])
{
    bool sorted = false;
    while(!sorted)
    {
        sorted = true;
        for(int i = 0; i < MAX_RATES - 1; i++)
        {
            if(cRates[i] > cRates[i + 1])
            {
                swap_values(cRates[i], cRates[i + 1]);
                sorted = false;
            }
        }
    }
}

void swap_values(double &n1, double &n2)
{
    n1 += n2;
    n2 = n1 - n2;
    n1 = n1 - n2;
}
//precondition: MAX_RATES is greater than 0, cRates size is equal to MAX_RATES
double findMedianRate(int MAX_RATES, double cRates[])
{
    sort_array(MAX_RATES, cRates);
    if(MAX_RATES % 2 == 0)
        return (cRates[MAX_RATES / 2] + cRates[(MAX_RATES / 2) - 1]) / 2.0;
    else return cRates[(MAX_RATES / 2)]; 
}