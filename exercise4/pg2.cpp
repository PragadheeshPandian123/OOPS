#include <iostream>
using namespace std;

class Fraction {
private:
    int num;   
    int den;   
    int gcd(int a, int b) const {
        return (b == 0) ? a : gcd(b, a % b);
    }
    void reduce() {
        int g = gcd(abs(num), abs(den));
        if (g != 0) {
            num /= g;
            den /= g;
        }
        if (den < 0) {
            num = -num;
            den = -den;
        }
    }
public:
    Fraction() : num(0), den(1) {}                       
    Fraction(int n) : num(n), den(1) {}                   
    Fraction(int n, int d) : num(n), den(d == 0 ? 1 : d) { 
        reduce();
    }

    Fraction(const Fraction &f) : num(f.num), den(f.den) {}

    Fraction operator+(const Fraction &f) const {
        return Fraction(num * f.den + f.num * den, den * f.den);
    }

    Fraction operator-(const Fraction &f) const {
        return Fraction(num * f.den - f.num * den, den * f.den);
    }

    Fraction operator*(const Fraction &f) const {
        return Fraction(num * f.num, den * f.den);
    }

    Fraction operator/(const Fraction &f) const {
        return Fraction(num * f.den, den * f.num);
    }

    bool operator==(const Fraction &f) const {
        return (num == f.num && den == f.den);
    }

    bool operator>(const Fraction &f) const {
        return (num * f.den > f.num * den);
    }

    bool operator<(const Fraction &f) const {
        return (num * f.den < f.num * den);
    }

    friend ostream& operator<<(ostream &out, const Fraction &f);
    friend istream& operator>>(istream &in, Fraction &f);
};

ostream& operator<<(ostream &out, const Fraction &f) {
    out << f.num << "/" << f.den;
    return out;
}

istream& operator>>(istream &in, Fraction &f) {
    cout << "Enter numerator: ";
    in >> f.num;
    cout << "Enter denominator: ";
    in >> f.den;
    if (f.den == 0) {
        cout << "Denominator cannot be zero, set to 1 automatically.\n";
        f.den = 1;
    }
    f.reduce();
    return in;
}

int main() {
    Fraction f1, f2;
    cout << "Enter first fraction:\n";
    cin >> f1;
    cout << "Enter second fraction:\n";
    cin >> f2;

    cout << "\nYou entered: " << f1 << " and " << f2 << endl;

    cout << "Addition: " << f1 + f2 << endl;
    cout << "Subtraction: " << f1 - f2 << endl;
    cout << "Multiplication: " << f1 * f2 << endl;
    cout << "Division: " << f1 / f2 << endl;

    cout << "Comparison results:\n";
    cout << f1 << " == " << f2 << " ? " << (f1 == f2 ? "true" : "false") << endl;
    cout << f1 << " > " << f2 << " ? " << (f1 > f2 ? "true" : "false") << endl;
    cout << f1 << " < " << f2 << " ? " << (f1 < f2 ? "true" : "false") << endl;

    return 0;
}
