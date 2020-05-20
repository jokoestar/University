/* Working with arrays and functions
 * Author: Joshua Kohler
 * Last modified on: 2/3/2020 3:56
 * Known bug
 */ 
#include <iostream>

using namespace std;
//global variable to hold the maximum size of an array
const int CAPACITY = 20;
// swap - swaps two integer values
// @Param n1: the first number swapped
// @Param n2L the second number swapped
void swap(int &n1, int &n2);
// displayArray - display the array on a single line separated by blanks.
// @param: int array[] is an unordered array of integers
// @param: int numberOfElements
void displayArray(int array[], int numElements);
//  fillArray fills an int array with values entered by the user. Stop reading when the user inputs -1 or you reach CAPACITY.
// @param: int array[] is an unordered array of integers when leaving this function
// @param: int& numberElements is the number of Elements in the array after function
// @returns void.
void fillArray(int array[], int &numElements);
// removeElement - removes the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int numberElements
// @param: int position of element to delete
// @returns: true if delete was successful, false otherwise
bool removeElement(int array[], int &numberElements, int num);

int searchElement(int array[], int numberElements, int num);

// insertElement - removes the element of the given index from the given array.
// @param: int array[] is an unordered array of integers
// @param: int numberElements
// @param: int position to insert into
// @param: int target to insert.
// @returns: true if insert was successful, false otherwise

bool insertElement(int array[], int &numberElements, int index, int value);

//ToDo: Declare a function that searches for an element in the given array
// searchElement - searches for the element in the given array.
// @param int array[] is an unordered array of integers
// @param int numberOfElements
// @param int target
// @returns index of element or -1 if not found.
int searchElement(int array[], int numberOfElements, int target);
// ToDo: Declare a function that reverses the array given an array and it's size.
// @param int array[] is an unordered array of integers
// @param int numberOfElements
// @returns void, but array is reversed from the original order.
// MUST USE a version of swap that you've implemented.
void reverse(int array[], int numberOfElements);


int main()
{
  // The NumArray can be partially filled, we use variable NumArrayElems to keep track of how many numbers
  // have been stored in the array. 
  int NumArray[CAPACITY];	// an int array with a given CAPACITY
  int NumArrayElems = 0;      // the array is initially empty, i.e., contains 0 elements
  bool genericBoolean;//This is a dumping ground for boolean values and occasionally a tmeporary variable
  //this is an integer used to keep track of the number of elements in NumArray with its integer value equal to the quantity
  // 1. ToDo: Call your fillArray function to read in a sequence of integer values,
  // separated by space, and ending with -1. Store the values in the NumArray array 
  // and the number of elements in NumArrayElems.
  // Display the contents of the array afterwards 
  fillArray(NumArray, NumArrayElems);
  displayArray(NumArray, NumArrayElems);

  // 2. ToDo: Read in a value and position from the user. Call your insertElement function
  // to insert the given value into the given position of the array 
  // Display the contents of the array afterwards
  int Num, Index;
  cout << "Enter a value and a position to insert: ";
  cin >> Num >> Index; 
  genericBoolean = insertElement(NumArray, NumArrayElems, Index, Num);
  displayArray(NumArray, NumArrayElems);
  // 3. ToDo: Read in a value and call your searchElement function.
  // if the value is  found, delete it from the array using your function
  // if the value not found, print "Value not found in array"
  // Display the contents of the array afterwards 
  cout << "Enter a value to delete from the array: ";
  cin >> Num;
  Index = searchElement(NumArray, NumArrayElems, Num);
  if(Index > -1)
  {
        genericBoolean = removeElement(NumArray, NumArrayElems, Index);
        displayArray(NumArray, NumArrayElems);
  }
  else
    cout << "Value not found!\n";
  // 5. TODO: Read in a value and call your insertElement function to append
  // a value to the end of the array 
  // Display the contents of the array afterwards 
  cout << "Enter a value to append: ";
  cin >> Num;
  insertElement(NumArray, NumArrayElems, NumArrayElems, Num);
  displayArray(NumArray, NumArrayElems);

  // 6. TODO: Call your reverse function to reverse the values in the array.
  // Display the contents of the array.
  reverse(NumArray, NumArrayElems);
  displayArray(NumArray, NumArrayElems);

  return 0;
}

//TODO: Implement all functions declared above.
//Don't forget to put precondition/postcondition comments under or over the function header.

// displayArray - displays the array
// precondition: int array[] is an unordered array of numElems integers.
// postcondition: array is displayed on the console on a single line separated by blanks.
void displayArray(int array[], int numElem)
{
    for (int i = 0; i < numElem; i++)
        cout << array[i] << " ";
    cout << endl;
}

void fillArray(int array[], int &numElements)
{
    cout << "Enter a list of up to 20 integers or -1 to end the list\n";
    int Num;
    cin >> Num;
    while((Num >= 0) && (numElements < CAPACITY))
    {
        array[numElements] = Num;
        numElements++;
        cin >> Num;
    }
}
// @Param: array is an array of integers that has a value inserted into it
// @Param: numberElements is an integer used to manage the integer which tracks the size of the array
// @Param: index is an integer used to find the part of the array to insert the value in
// @Param: value is an integer inserted into array at index index
//This function inserts value at index index in array array and shifts all other values one space as long as the array is not full and the index is not smaller than 0 in which case the function will return false instead 
bool insertElement(int array[], int &numberElements, int index, int value)
{
  if(index < 0 || index >= CAPACITY)
    return false;
  for(int i = numberElements; i >= index; i--)
    array[i] = array[i - 1];
  array[index] = value;
  numberElements++;
  
    if(index + 1 - numberElements > 1)
        numberElements--;
    return true;
}
int searchElement(int array[], int numberElements, int num)
{
  for(int i = 0; i < numberElements; i++)
    if (array[i] == num)
      return i;
  return -1;
}
// @Param: array is an array of integers that has a value removed into it
// @Param: numberElements is an integer used to manage the integer which tracks the size of the array
// @Param: index is an integer used to find the value int the array to remove
// This function the value at index in array and adjusts the array to make all values still in the array are consecutive in terms of placement
bool removeElement(int array[], int &numberElements, int index)
{
  numberElements--;
  for(int i = index; i < numberElements; i++)
    array[i] = array[i + 1];
  if(numberElements == 19)
    array[19] = 0;
    return true;
}
// @Param array is an array whose values are used to flip itself
// @Param numberOfElements is an integer whose value represents the number of elemnets in the array and is used to manage the loop
// This function reverse the order of the elements in array which are filled in
void reverse(int array[], int numberOfElements)
{
  for(int i = 0; i < numberOfElements / 2; i++)
    swap(array[i], array[numberOfElements - 1 - i]);
}
// This function swaps two integer values
// @Param n1: the first number swapped
// @Param n2L the second number swappedS
void swap(int &n1, int &n2)
{
  n1 += n2;
  n2 = n1 - n2;
  n1 -= n2;
}