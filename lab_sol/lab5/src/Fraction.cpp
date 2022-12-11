#include "Fraction.h"

int Fraction::Gcd(int a, int b) {
    if (b == 0)
        return 1;
    if (a % b == 0)
        return b;
    return Gcd(b, a % b);
}

void Fraction::Reduce() {
    int gcd = Gcd(numerator, denominator);
    if (denominator / gcd < 0)
        gcd = -gcd;
    numerator /= gcd;
    denominator /= gcd;
}

Fraction Fraction::operator+(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    int commul = this->denominator * oprand.denominator;
    Fraction res(n1 + n2, commul);
    return res;
}

Fraction Fraction::operator-(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    int commul = this->denominator * oprand.denominator;
    Fraction res(n1 - n2, commul);
    return res;
}

Fraction Fraction::operator*(const Fraction& oprand) {
    int num = this->numerator * oprand.numerator;
    int den = this->denominator * oprand.denominator;
    Fraction res(num, den);
    return res;
}

Fraction Fraction::operator/(const Fraction& oprand) {
    int num = this->numerator * oprand.denominator;
    int den = this->denominator * oprand.numerator;
    Fraction res(num, den);
    return res;
}

bool Fraction::operator<(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    return n1 < n2;
}

bool Fraction::operator<=(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    return n1 <= n2;
}

bool Fraction::operator==(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    return n1 == n2;
}

bool Fraction::operator!=(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    return n1 != n2;
}

bool Fraction::operator>=(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    return n1 >= n2;
}

bool Fraction::operator>(const Fraction& oprand) {
    int n1 = this->numerator * oprand.denominator;
    int n2 = this->denominator * oprand.numerator;
    return n1 > n2;
}

double Fraction::toDouble() const {
    return double(this->numerator) / double(this->denominator);
}

string Fraction::toString() const {
    string res;
    if (this->numerator == this->denominator) {
        res = "1";
    } else if (this->numerator == 0) {
        res = "0";
    } else if (this->denominator == 1) {
        res = to_string(this->numerator);
    } else {
        res = to_string(this->numerator);
        res += "/";
        res += to_string(this->denominator);
    }
    return res;
}

ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.toString();
    return os;
}

istream& operator>>(std::istream& is, Fraction& frac) {
    char c;
    is >> frac.numerator >> c >> frac.denominator;
    if (c != '/') {
        cout << "Not a legal input" << endl;
        system("PAUSE");
        exit(0);
    } else {
        frac.Reduce();
        return is;
    }
}
