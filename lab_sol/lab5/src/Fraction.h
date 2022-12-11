#pragma once
#ifndef _FRACTION_H_
#define _FRACTION_H_

#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Fraction {
   private:
    int numerator;          // Numerator
    int denominator;        // Denominator
    int Gcd(int a, int b);  // Greatest Common Divisor
    void Reduce();          // Reduction

   public:
    Fraction() : numerator(0), denominator(1){};  // Default
    ~Fraction() = default;
    Fraction(int n): numerator(n),denominator(1) {}  // ctor takes one integer as parameters
    Fraction(int num, int den) : numerator(num), denominator(den) {Reduce();}  // ctor takes two integers as parameters
    Fraction(const Fraction& copy) // Copy a fraction
        : numerator(copy.numerator), denominator(copy.denominator) {}
    Fraction(string decimal) { // conversion from a finite decimal string 
        int len = decimal.size();
        int dot = decimal.find(".");
        if (dot == decimal.npos)
            dot = -1;
        stringstream ss;
        ss << decimal;
        double value;
        ss >> value;
        numerator = value * pow(10, len - dot - 1);
        denominator = pow(10, len - dot - 1);
        Reduce();
    }

    Fraction operator+(const Fraction& oprand); // Arithmetical operators+
    Fraction operator-(const Fraction& oprand); // Arithmetical operators-
    Fraction operator*(const Fraction& oprand); // Arithmetical operators*
    Fraction operator/(const Fraction& oprand); // Arithmetical operators/

    bool operator<(const Fraction& oprand);     // Relational operators<
    bool operator<=(const Fraction& oprand);    // Relational operators<=
    bool operator==(const Fraction& oprand);    // Relational operators==
    bool operator!=(const Fraction& oprand);    // Relational operators!=
    bool operator>=(const Fraction& oprand);    // Relational operators>=
    bool operator>(const Fraction& oprand);     // Relational operators>

    double toDouble() const;        // type cast to double
    string toString() const;        // type cast to string

    friend istream& operator>>(std::istream& is, Fraction& frac);       // Extractor for streams
    friend ostream& operator<<(std::ostream& os, const Fraction& frac); // Inserter for streams

};

#endif