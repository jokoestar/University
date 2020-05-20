#include <iostream>
using namespace std;

int main(){
    char input = 65, newChar;//input is the input recieved and newChar is the encrypted value
    
    /*  Input recieves an input from the user called input
    This input is copied to newChar which is encrypted if it is a letter between A-Z
    If it is not, the program will check to see if is not '0' and then tell the user they did not input a valid character
    Then, the above block will repeat as long as the input is not '0' */
    while (!(input == 48))
    {
        cout << "Enter a character (A-Z) to encrypt (0 to quit): ";
        cin >> input;
        newChar = input;
        if(!(newChar < 65 || newChar > 90))
        {
            newChar += 13;
            if(newChar > 90) newChar -= 26;
            cout << input << " encrypts to " << newChar << endl;
        }
        else if(!(input == 48)) cout << "Invalid character (A-Z)" << endl;
    }
    cout << "Bye!" << endl;
    return 0;
}
