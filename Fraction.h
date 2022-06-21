#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

class Fraction
{
public:
	// Constructors

	Fraction();
	Fraction(const Fraction &F);
	Fraction(const int numerator, const unsigned denominator);
	Fraction(const int I);
	Fraction(const float FL);
	Fraction(const string &S);

	// Destructor

	~Fraction();

	//Assignment operator

	Fraction &operator=(const Fraction &F);

	// Logical Operators

	bool operator!=(const Fraction &F) const;
	bool operator>(const Fraction &F) const;
	bool operator>=(const Fraction &F) const;
	bool operator==(const Fraction &F) const;
	bool operator<(const Fraction &F) const;
	bool operator<=(const Fraction &F) const;

	// Arithmetic Operators

	Fraction operator*=(const Fraction &F);
	Fraction operator+=(const Fraction &F);
	Fraction operator-=(const Fraction &F);
	Fraction operator/=(const Fraction &F);
	Fraction operator+(const Fraction &F) const;
	Fraction operator/(const Fraction &F) const;
	Fraction operator-(const Fraction &F) const;
	Fraction operator*(const Fraction &F) const;
	Fraction operator++();	  // Pre
	Fraction operator++(int); // Post
	Fraction operator--();	  // Pre
	Fraction operator--(int); // Post

	// Input and Output Operators

	friend istream &operator>>(istream &input, Fraction &F);
	friend ostream &operator<<(ostream &output, const Fraction &F);

	// Conversion Operators

	operator int() const;
	operator float() const;
	operator double() const;
	operator string() const;

	// Other Methods

	Fraction powi(const int pow) const;
	Fraction simplify(); // reduce to lowest terms
	Fraction reciprocal() const;

private:
	int numerator;
	unsigned denom;
	int findGCD(int denom1, int denom2) const;
	int findLCD(int denom1, int denom2) const;
	int findLCM(int denom1, int denom2) const;
	int GetDenom() const;
	int GetNumerator() const;
	void SetDenom(int denominator);
	void SetNum(int numerator);
};

#endif
