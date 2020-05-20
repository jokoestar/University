#include <iostream>
#include <string>
//Top of Header guard
#ifndef _RATIONAL_H
#define _RATIONAL_H

/*  KEEP THIS COMMENT
* class Rational
*    represents a Rational number. Remember rational means ratio-nal
*    which means there is a numerator and denominator having
*    integer values. Using good ADT techniques, we have made member
*    variable private (also known as instance variables) and made member
*    functions public.
*/
class rational
{
	// ToDo: Constructor that takes int numerator and int denominator
	private:
	
	    //This integer represents the numerator in a rational number
	    
	    int numerator;
	    
	    //That integer represents the denominator in a rational number
	    
        int denominator;
        
    public:
    
        //This is the constructor for the rational class. It initializes a rational number with the value num/den
        
        rational(int num = 0, int den = 1);
        
        //This is a function which sets the instance variables numerator and denominator of the rational class to num and den respectively
        //@Param r1: This is a rational whose numerator the numerator of the class is set equal to
        //@Param r2: This is a rational whose denominator the denominator of the class is set equal to
        //Precondition: r1 and r2 are initialized
        //Postcondition: The numerator is equal to that of r1 and denominator to that of r2
        
        void set(int n1, int n2);
        
        //This is a function which recives an input value for the rational number in the format "numerator/denominator"
        //@Param in: This is an istream which reads input from the console
        //Precondition: none
        //Postcondition: The numerator and denominator are changed
        
        void input(std::istream &in);
        
        //This is a function which outputs the value of the rational number in the format numerator/denominator
        // @Param out: This is a pointer to an ostream used to print values in the function
        //Precondition: numerator and denominator are initialized
        //Postcondition: numerator and denominator have been printed to the console with a '/' in between the two
        
        const void output(std::ostream &out);
        
        //This is a function which reduces the rational by removing the common factors in the numerator and denominator
        //Precondition: numerator and denominator are initialized
        //Postcondition: numerator and denominator have  each been divided by all of their common factors once

        void reduce();
    
        //This is a function which sets the values of a rational number equal to the sum two other rational numbers taken as parameters
        // @Param a: This is the first rational number in the calculation
        // @Param b: This is the second rational number in the calculation
        // Precondition: a and b are initialized
        // Postcondition: the numerator an denominator are set equal to the sume of a and b
        
        friend rational sum(const rational a, const rational b);
        
        //This function returns true if a and b represent equal numbers
        //@Param a: This is a rational  whose numerator and denominator are compared
        //@Param b: This is a rational whose numerator and denominator are compared
        //Precondition: a and b are initialized
        //Postcondition: returns true if a and b represent equal numbers
        
        friend bool Equals(const rational a, const rational b);
    
        //This operator returns true if the rationals represent equivalent numbers
        //@Param a: This rational is compared to b
        //@Param b: This rational is compared to a
        //Precondition: a and b are initialized
        //Postcondition: Returns true if they represent equal numbers and false if they do not
        //Returns: True if they represent equal numbers and false if they are not

        friend bool operator ==(const rational a, const rational b);
        
        //This operator returns true if the rationals do not represent equal numbers
        //@Param a: This rational is compared to b
        //@Param b: This rational is compared to a
        //Precondition: a and b are initialized
        //Postcondition: Returns false if they represent equal numbers and true if they do not
        //Returns: False if they are equal and true if they are not
        
        friend bool operator !=(const rational a, const rational b);
        
        //This operator returns true if the rational represents a number greater than what b represents
        //@Param a: This rational is compared to b
        //@Param b: This rational is compared to a
        //Precondition: a and b are initialized
        //Postcondition: Returns true if a represents a number greater than b and false otherwise
        //Returns: True if a represents a number greater than what b represents and true otherwise
        
        friend bool operator >(const rational a, const rational b);
        
        //This operator returns true if the rational represents a number less than what b represents
        //@Param a: This rational is compared to b
        //@Param b: This rational is compared to a
        //Precondition: a and b are initialized
        //Postcondition: Returns true if a represents a number less than b and false otherwise
        //Returns: True if a represents a number less than what b represents and true otherwise
        
        friend bool operator <(const rational a, const rational b);
        
        //This operator returns true if the rational represents a number greater than or equal to what b represents
        //@Param a: This rational is compared to b
        //@Param b: This rational is compared to a
        //Precondition: a and b are initialized
        //Postcondition: Returns true if a represents a number greater to or equal to what b represents and false otherwise
        //Returns: True if a represents a number greater than or equal to b and false otherwise
        
        friend bool operator >=(const rational a, const rational b);
        
        //This operator returns true if the rational represents a number less than or equal to what b represents
        //@Param a: This rational is compared to b
        //@Param b: This rational is compared to a
        //Precondition: a and b are initialized
        //Postcondition: Returns true if a represents a number less than or equal to what b represents and false otherwise
        //Returns: True if a represents a number less than or equal to b and false otherwise
        
        friend bool operator <=(const rational a, const rational b);
        
        //This operator outputs the rational to the console in the format numerator/denominator and returns the ostream
        //@Param out: This is a pointer to the ostream used to output the rational
        //@Param a: This is a rational whose value is outputed to the console in the format numerator/denominator
        //Precondition: a is initialized
        //Postcondition: Outputs the rational in the format numerator/denominator and returns a pointer to the ostream afterwards
        //Returns: A pointer to the ostream 
        
        const friend std::ostream& operator <<(std::ostream &out, const rational a);
        
        //This operator inputs the rational from the console in the format numerator/denominator and returns the istream
        //@Param out: This is a pointer to the istream used to iutput the rational
        //@Param a: This is a rational whose value is iutputed from the console in the format numerator/denominator 
        //Precondition: 
        //Postcondition: Inputs the rational in the format numerator/denominator and returns a pointer to the istream afterwards
        //Returns: A pointer to the istream 
        
        friend std::istream& operator >>(std::istream &in, rational& a);
        
        //This operator adds two rationals, simplifies their values, and returns the simplified values
        //@Param: a: This rational has b added to it
        //@Param b: This rational is added to b
        //Precondition: b and b are initialized
        //Postcondition: returns the sum of a and b
        //Returns: The sum of a and b equivalent to a.numerator * b.denominator) + (b.numerator * a.denominator), a.denominator * b.denominator
        
        friend rational operator +(const rational a, const rational b);
        
        //This operator subtracts two rationals, simplifies their values, and returns the simplified values
        //@Param a: This rational has b subtracted from it
        //@Param b: This rational is subtracted from a
        //Precondition: a and b are initialized
        //Postcondition: returns the difference between a and b
        //Returns: The difference between a and b equivalent to (a.numerator * b.denominator) - (b.numerator * a.denominator), a.denominator * b.denominator)
        
        friend rational operator -(const rational a, const rational b);
        
        //This operator multiplies two rationals, simplifies their values, and returns the simplified values
        //@Param a: This rational is multiplied by b
        //@Param b: This rational is multiplied by a
        //Precondition: a and b are initialized
        //Postcondition: returns the product of a and b using the formula a.numerator * b.numerator, a.denominator * b.denominator
        //Returns: The product of a and b using the formula a.numerator * b.numerator, a.denominator * b.denominator
        
        friend rational operator *(const rational a, const rational b);
        
        //This operator divides two rationals, simplifies their values, and returns the simplified values
        //@Param a: This rational is divided by b
        //@Param b: This rational is divided from a
        //Precondition: a and b are initialized
        //Postcondition: returns the quotient of a and b using the formula a.numerator * b.numerator, a.denominator * b.denominator
        //Returns: The product of a and b using the formula a.numerator * b.denominator, b.numerator * a.denominator
        
        friend rational operator /(const rational a, const rational b);
        
        //This operator negates the value of a rational by multiplying the numerator by -1, simplifies it, and returns the simplifies values
        //@Param a: This rational is negated
        //Precondition: a is initialized
        //Postcondition: returns the negation of a using the formula a.numerator * (-1)
        //Returns: the negation of a using a.numerator * (-1)
        
        friend rational operator -(const rational a);
        
        //This is a geftter which returns the numerator of the rational object
        //Precondition: numerator is initialized
        //Postcondition: returns numerator as an integer
        
        const int get_num();
    
        //This is a getter which returns the denominator of the rational objecy
        //Precondition: denominator is initialized
        //Postcondition: returns denominator as an integer
        
        const int get_den();

};
//Bottom of header guard
#endif //_RATIONAL_H

//This function returns the index of the first instance of char c in string s unless there are none in which case it returns -1
//@Param s: This is a string in which the value stored in c is searched for
//@Param c: This is the char whose index is searched for
//Precondition: S and c are initialized
//Postcondition: Returns the index of c in s or -1 if c is not found in s
//Returns: The index of the first instance of char c in s in ascending index order from 0 to s.length() and if no char in c is equal to s, returns -1

int index_of(std::string s, char c);

//This function returns true if all characters in s are numbers and false Otherwise
//@Param s: This is the string which is searched
//@Param c: This is a char whose value is searched for
//Precondition: s is initialized
//Postcondition: returns true if s has only characters and false otherwise
//Returns: True if s is a string represents a single integer


bool is_digit(std::string s);

//This function returns true if all chars in the string are '0' or if the string represents a negative number and false elsewise
//@Param s: This is the string which is searched
//Precondition: s is initialized
//Postcondition: Returns true if all values in s are chars '0' to '9' or the same conditon with the first character being '-' and false otherweise
//Returns: True if all chars in the string are 0 or a negative number is represented and false otherwise

bool is_zero_or_negative(std:: string s);
