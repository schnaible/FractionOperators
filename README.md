# FractionOperators
C++ program that overloads operators to work for fractions. Works with int (either as Fraction(int) or Fraction(int, unsigned int)), float, or string.

Can perform Logical operations such as !=, ==, >, >=, <, <=.

Can perform arithmetic operations such as +, -, *, /, +=, *=, ++, --, etc. 

Other methods include input/output, conversion, simplify, reciprocal, and power

Examples (See example.cpp for more uses):

```
 // bool operator != (const Fraction & F) const;
	f1 = Fraction(1, 2);  // f1 = 1/2
	f2 = Fraction(2, 2);  // f2 = 2/2
	cout << "1/2 != 2/2 " << (f1 != f2) << endl;
// 1/2 != 2/2 -> 1 (true)


// Fraction operator += (const Fraction & F);
	f1 = Fraction(3, 5);  // f1 = 3/5
	f2 = Fraction(2, 5);  // f2 = 2/5
	f1 += f2;       
	cout << "3/5 += 2/5 f1=" << (f1) << endl;
// f1 += f2 = 1


// Fraction reciprocal () const;
	f1 = Fraction(-15, 5); // f1 = -3/1
	cout << "f1: " << f1 << " f1.reciprocal(): " << f1.reciprocal() << endl;
// f1 = -1/3
```
