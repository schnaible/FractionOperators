#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include "Fraction.h"
using namespace std;

// Constructors

Fraction::Fraction()
{
    // Fraction(0, 1);
    this->numerator = 0;
    this->denom = 1;
}
Fraction::Fraction(const Fraction &F)
{
    this->numerator = F.numerator;
    this->denom = F.denom;
}
Fraction::Fraction(const int numerator, const unsigned denominator)
{
    this->numerator = numerator;
    this->denom = denominator;
    this->simplify();
}
Fraction::Fraction(const int I)
{
    this->numerator = I;
    this->denom = 1;
    this->simplify();
}
Fraction::Fraction(const float FL)
{
    this->numerator = (FL)*10000;
    this->denom = 10000;
    this->simplify();
}
Fraction::Fraction(const string &S)
{
    string arrayNum = "";
    string arrayDenom = "";
    bool hasBar = false;
    // adapted from project 1
    for (int c = 0; c < S.size(); c++)
    {
        if (isdigit(S.at(c)))
        {
            if (hasBar == false)
                arrayNum += S.at(c);
            else
                arrayDenom += S.at(c);
        }
        else if (S.at(c) == '/')
        {
            hasBar = true;
        }
        else
        {
            if (S.at(c) == '-')
            {
                if (arrayNum.size() == 0 && hasBar == false)
                {

                    arrayNum += S.at(c);
                }
            }
            else
            {
                break;
            }
        }
    }

    this->numerator = int(stoi(arrayNum));
    this->denom = unsigned(stoi(arrayDenom));
    this->simplify();
}
// Destructor

Fraction::~Fraction() {}

//Assignment operator

Fraction &Fraction::operator=(const Fraction &F)
{
    this->numerator = F.numerator;
    this->denom = F.denom;
    return *this;
}

// Logical Operators

bool Fraction::operator!=(const Fraction &F) const
{
    return ((this->numerator * F.denom) != (F.numerator * this->denom));
}

bool Fraction::operator>(const Fraction &F) const
{
    // Checking if 'this' is negative
    if (this->numerator < 0)
    {
        // if F is also negative
        if (F.numerator < 0)
            return ((this->numerator * F.denom) > (F.numerator * this->denom));
        else
            return false;
    }
    else if (F.numerator < 0)
        return true;

    return ((this->numerator * F.denom) > (F.numerator * this->denom));
}

bool Fraction::operator>=(const Fraction &F) const
{
    if (this->numerator < 0)
    {
        if (F.numerator < 0)
            return ((this->numerator * F.denom) >= (F.numerator * this->denom));
        else
            return false;
    }
    else if (F.numerator < 0)
        return true;
    return ((this->numerator * F.denom) >= (F.numerator * this->denom));
}

bool Fraction::operator==(const Fraction &F) const
{
    return ((this->numerator * F.denom) == (F.numerator * this->denom));
}

bool Fraction::operator<(const Fraction &F) const
{
    if (this->numerator < 0)
    {
        if (F.numerator < 0)
            return ((this->numerator * F.denom) < (F.numerator * this->denom));
        else
            return true;
    }
    else if (F.numerator < 0)
        return false;
    return ((this->numerator * F.denom) < (F.numerator * this->denom));
}

bool Fraction::operator<=(const Fraction &F) const
{
    if (this->numerator < 0)
    {
        if (F.numerator < 0)
            return ((this->numerator * F.denom) <= (F.numerator * this->denom));
        else
            return true;
    }
    else if (F.numerator < 0)
        return false;
    return ((this->numerator * F.denom) <= (F.numerator * this->denom));
}

// Arithmetic Operators

Fraction Fraction::operator*=(const Fraction &F)
{
    Fraction f1((this->numerator * F.numerator), (this->denom * F.denom));
    *this = f1;
    return this->simplify();
}
Fraction Fraction::operator+=(const Fraction &F)
{
    *this = *this + F;
    return this->simplify();
}
Fraction Fraction::operator-=(const Fraction &F)
{
    *this = *this - F;
    return this->simplify();
}
Fraction Fraction::operator/=(const Fraction &F)
{
    *this = *this / F;
    return this->simplify();
}

Fraction Fraction::operator+(const Fraction &F) const
{
    Fraction f1(((this->numerator * F.denom) + (F.numerator * this->denom)), (this->denom * F.denom));
    return f1.simplify();
}

Fraction Fraction::operator/(const Fraction &F) const
{
    Fraction f1((this->numerator * F.denom), (this->denom * abs(F.numerator)));
    return f1.simplify();
}

Fraction Fraction::operator-(const Fraction &F) const
{
    Fraction f1(((this->numerator * F.denom) - (F.numerator * this->denom)), (this->denom * F.denom));
    return f1.simplify();
}

Fraction Fraction::operator*(const Fraction &F) const
{
    Fraction f1((this->numerator * F.numerator), (this->denom * F.denom));
    return f1.simplify();
}

// Referenced for pre/post increment:
// https://thispointer.com/overloading-postfix-prefix-increment-and-decrements-operators-in-c/

Fraction Fraction::operator++() // Pre
{
    int newNum = this->numerator + this->denom;
    this->numerator = newNum;
    return this->simplify();
}

Fraction Fraction::operator++(int) // Post
{
    Fraction f1(this->numerator, this->denom);
    this->numerator += this->denom;
    return f1.simplify();
}

Fraction Fraction::operator--() // Pre
{
    int newNum = this->numerator - this->denom;
    this->numerator = newNum;
    return *this;
}

Fraction Fraction::operator--(int) // Post
{
    Fraction f1(this->numerator, this->denom);
    this->numerator -= this->denom;
    return f1.simplify();
}

// Input and Output Operators

istream &operator>>(istream &input, Fraction &F)
{
    char slash;
    return (input >> F.numerator >> slash >> F.denom);
}

ostream &operator<<(ostream &output, const Fraction &F)
{
    return (output << F.numerator << "/" << F.denom);
}

// Conversion Operators

Fraction::operator int() const
{
    int quotient = (abs(this->numerator) / this->denom);
    if (this->numerator < 0)
        return -quotient;
    return quotient;
}

Fraction::operator float() const
{
    return (float(this->numerator) / float(this->denom));
}

Fraction::operator double() const
{
    return (double(this->numerator) / double(this->denom));
}

Fraction::operator string() const
{
    string ftos = "";
    ftos.append(to_string(this->numerator));
    ftos.append("/");
    ftos.append(to_string(this->denom));
    return ftos;
}

// Other Methods

Fraction Fraction::powi(const int pow) const
{
    if (pow < 0)
    {
        int powNum = std::pow(this->denom, abs(pow));
        unsigned powDenom = std::pow(this->numerator, abs(pow));
        Fraction f1(powNum, powDenom);
        return f1.simplify();
    }
    int powNum = std::pow(this->numerator, pow);
    int powDenom = std::pow(this->denom, pow);
    Fraction f1(powNum, powDenom);
    return f1.simplify();
}

Fraction Fraction::simplify()
{
    if (this->numerator == this->denom)
    {
        // Fraction f1((this->numerator / this->denom), (this->denom / this->numerator));
        this->numerator = this->numerator / this->denom;
        this->numerator = this->denom / this->numerator;
        return (*this);
    }
    else
    {
        int cd = findGCD(abs(this->GetNumerator()), abs(this->GetDenom()));
        // Fraction f1(this->GetNumerator() / cd, this->GetDenom() / cd);
        this->numerator = this->numerator / cd;
        this->denom = this->denom / cd;
        return (*this);
    }
} // reduce to lowest terms

Fraction Fraction::reciprocal() const
{
    if (this->numerator < 0)
    {
        int num = -(this->denom);
        unsigned denom = abs(this->numerator);
        Fraction f1(num, denom);
        return f1;
    }

    Fraction f1(this->denom, this->numerator);
    return (f1);
}

// Private Functions

int Fraction::findGCD(int denom1, int denom2) const
{
    if (denom2 > denom1)
        return findGCD(denom2, denom1);
    else if (denom2 == 0)
        return denom1;
    return findGCD(denom2, denom1 % denom2);
}

int Fraction::findLCD(int denom1, int denom2) const
{
    return (denom1 * denom2 / findGCD(denom1, denom2));
}

int Fraction::findLCM(int denom1, int denom2) const
{
    return 0;
}

int Fraction::GetDenom() const
{
    return denom;
}

int Fraction::GetNumerator() const
{
    return numerator;
}

void Fraction::SetDenom(int denominator)
{
    this->denom = denom;
}

void Fraction::SetNum(int numerator)
{
    this->numerator = numerator;
}