#include <iostream>
#include <string>
using namespace std;

class String {
    string str;
public:
    // Constructor that takes const reference
    String(const string &s) {
        str = s;
        cout << "Constructor: " << str << endl;
    }

    // Copy constructor with const reference
    String(const String &s) {
        str = s.str;
        cout << "Copy Constructor: " << str << endl;
    }
};

int main() {
    String s1 = "Hello";  // Calls constructor
    String s2("Hi");      // Also calls constructor
    String s3 = s2;       // Calls copy constructor
    return 0;
}
