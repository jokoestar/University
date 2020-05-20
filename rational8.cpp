#include <iostream>
#include <string>
using namespace std;

#include "rational8.h"

rational::rational(int num, int den)
{
    numerator = num;
    denominator = den;
}

void rational::set(int n1, int n2)
{
    numerator = n1;
    denominator = n2;
    reduce();
    if(denominator < 0)
    {
        denominator *= -1;
        numerator *= -1;
        
    }
}

/*void rational::input(istream &in)
{
    bool notRational = true;
    char slash;
    
    while(notRational)
    {
        if((in >> numerator >> slash >> denominator) && (slash == '/') && (denominator != 0))
            notRational = false;
        else
            cout << "Error: bad rational\n";
    }    
}

const void rational::output(ostream &out)
{
    out << numerator << '/' << denominator << endl;
}

rational sum(const rational a, const rational b)
{
     rational r;
     
     r.numerator = (a.numerator * b.denominator) + (a.denominator * b.numerator);
     r.denominator = a.denominator * b.denominator;
     
     return r;
}*/

bool operator ==(const rational a, const rational b)
{
    if(a.numerator * b.denominator == b.numerator * a.denominator)
        return true;
    return false;
}

bool operator !=(const rational a, const rational b)
{
    if(a.numerator * b.denominator != b.numerator * a.denominator)
        return true;
    return false;
}

bool operator >(const rational a, const rational b)
{
    if(a.numerator * b.denominator > b.numerator * a.denominator)
        return true;
    return false;
}

bool operator <(const rational a, const rational b)
{
    if(a.numerator * b.denominator < b.numerator * a.denominator)
        return true;
    return false;
}

bool operator >=(const rational a, const rational b)
{
    if(a.numerator * b.denominator >= b.numerator * a.denominator)
        return true;
    return false;
}

bool operator <=(const rational a, const rational b)
{
    if(a.numerator * b.denominator <= b.numerator * a.denominator)
        return true;
    return false;
}

const ostream& operator <<(ostream &out, const rational a)
{
    out << a.numerator << '/' << a.denominator;
    return out;
}

istream& operator >>(istream &in, rational &a)
{
    
    string input_string;

    in >> input_string;
    
    if(index_of(input_string, '/') != -1 && is_digit(input_string.substr(0, index_of(input_string, '/'))) && is_digit(input_string.substr(index_of(input_string, '/') + 1)) && !is_zero_or_negative(input_string.substr(index_of(input_string, '/') + 1)))
                {
                    a.numerator = stoi(input_string.substr(0, index_of(input_string, '/')));
                    a.denominator = stoi(input_string.substr(index_of(input_string, '/') + 1, input_string.length() - index_of(input_string, '/')));
                }
    else
        cout << "Invalid rational format!\n";
    
    if(a.denominator < 0)
    {
        a.denominator *= -1;
        a.numerator *= -1;
    }
    
    return in;
}

rational operator +(const rational a, const rational b)
{
    rational r;
    r.set((a.numerator * b.denominator) + (b.numerator * a.denominator), a.denominator * b.denominator);
    return r;
}

rational operator -(const rational a, const rational b)
{
    rational r;
    r.set((a.numerator * b.denominator) - (b.numerator * a.denominator), a.denominator * b.denominator);
    return r;
}

rational operator *(const rational a, const rational b)
{
    rational r;
    r.set(a.numerator * b.numerator, a.denominator * b.denominator);
    return r;
}

rational operator /(const rational a, const rational b)
{
    rational r;
    r.set(a.numerator * b.denominator, b.numerator * a.denominator);
    return r;
}
rational operator -(const rational a)
{
    rational r;
    r.set(a.numerator * -1, a.denominator);
    return r;
}

const int rational::get_num()
{
    return numerator;
}

const int rational::get_den()
{
    return denominator;
}

void rational::reduce()
{
    if(numerator > 0)
    for(int i = 2; i <= numerator && i <= denominator; i++)
        if(numerator % i == 0 && denominator % i == 0)
        {
            numerator /= i;
            denominator /= i;
            i = 2;
        }
}

int index_of(string s, char c)
{
    for(int i = 0; i < s.length(); i++)
        if(s.at(i) == c)
            return i;
    return -1;
}
bool is_digit(string s)
{
    for(int i = 0; i < s.length(); i++)
    {
        if(i == 0 && s.at(i) == '-' && s.length() > 1)
            i++;
        if(s.at(i) < 48 || s.at(i) > 57)
        return false;
    }
    return true;
}
bool is_zero_or_negative(string s)
{
    if(s.at(0) == '-')
        return true;
    for(int i = 0; i < s.length(); i++)
        if(s.at(i) != '0')
            return false;
    return true;
}