/* 
 * pallindrome: checks a string to see if it is a pallindrome.
 *  
 *  Examples:
 * 
 *  Able was I 'ere I saw Elba.
 *  Madam, I'm Adam.
 *  A man, a plan, a canal, Panama.
 *  Racecar
 * 
 *  First, create a clean version of the string. 
 *  	- convert all characters to lower case.
 *  	- remove all punctuation.
 * 
 *  Second, create a reverse version of the string.
 *   - use reverse and swap from our lab assignment
 *   so first make a copy of the string and pass in
 *   the copy to reverse.
 *   
 *  Third
 *  	- compare the two strings 
 *  		if they are the same, palindrome.
 *  		else, not palindrome.
 */ 
#include <iostream>
#include <vector>
#include<string.h>
// ToDo: Add include files.
using namespace std;


void removePunct(string &str);
// Function: removePunct
// Precondition: a string that may or may not have punctuation.
// Postcondition: returns a (possibly shorter) string with punctuaton
// removed.

void convertToLower(string &str);
// Precondition: a string that may have mixed case in it.
// Postcondition: returns a lowercase string

void reverse(string &str);
// Precondition: a string to be reversed
// Postcondition: returns a string that is the
// reverse of the input string.

void display(vector<string> vstrings);
// Precondition: a vector of strings to print
// Postcondition: strings are printed one per line.

bool isPalindrome(string str);
// Precondition: a string to be tested
// Postcondition: returns a bool that is true if the input is a palindrome
// returns false otherwise.

int main() {

    // two vectors of strings to save the input strings: palindromes, not_palindromes.
    vector<string> palindromes, non_palindromes;
    
    //this string recieves the input from the istream
    string input = "";
    
    // a loop to read in the palindrome strings using getline until
    // the user quits. The user will enter the word "quit" to exit the loop.
    while(input != "quit")
    {
        cout << "Enter your palindrome or type quit: \n";
        getline(cin, input);
        if(input == "quit")
            break;
        if(isPalindrome(input))
            palindromes.push_back(input);
        else
            non_palindromes.push_back(input);
    }
    //displays the Palindromes
    cout << "Palindromes:\n";
    display(palindromes);
    //displays the not Palindromes
    cout << "NOT Palindromes:\n";
    display(non_palindromes);

	return 0;
}
/*  removePunct: removes all nonalphabetical characters in a string by checking each individual
*   character and replacing the character and the following characters with the following characters
*   @Param str: This string has the nonalphabetical characters removed from it
*/
void removePunct(string &str)
{
    for(int i = 0; i < str.length(); i++)
        if(!isalpha(str.at(i)))
        {
            str = str.substr(0, i) + str.substr(i + 1, str.length() - i);
            i--;
        }
}
/*  convertToLower: converts all uppercase characters in a strong to lowercase characters by checking
*   by checking whether each individual character is lowercase and changing its case and changhing if it is not lowercase
*   @Param str: this string has the lowercase characters in it made uppercase
*/  
void convertToLower(string &str)
{
    for(int i = 0; i < str.length(); i++)
        if(isupper(str.at(i)))
            str.at(i) = tolower(str.at(i));
}
/*  reverse: reverses the order in which characters appear in a string by swapping each character with one at an equal distance from the middle of the string
*   @Param: this string has its chars reversed
*/
void reverse(string &str)
{
    for(int i = 0; i < str.length() / 2; i++)
        swap(str.at(i), str.at(str.length() - i - 1));
}
/*  isPalindrome: checks to see if a string is a palindrome by removing all nonalphabetical characters, making every letter lowercase, reversing the string, and
*   checking every character in the string to see if it matches the character equistant from the middle of the string
*   @Param: str: this string has its characters reversed
*/
bool isPalindrome(string str)
{
    removePunct(str);
    convertToLower(str);
    reverse(str);
    for(int i = 0; i < str.length() / 2; i++)
        if(str.at(i) != str.at(str.length() - i - 1))
            return false;
    return true;
}
/*  display: displays the contents of a vector of strings with a \t character preceding and a \n character proceeding
*   @param: vstrings is a vector whose strings are printed
*/
void display(vector<string> vstrings)
{
    for(int i = 0; i < vstrings.size(); i++)
        cout << "\t" << vstrings.at(i) << endl;
}

















