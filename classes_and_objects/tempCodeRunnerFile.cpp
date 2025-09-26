#include <iostream>
using namespace std;

class Sample {
private:
    int a;          
    double b;       
    char c;         
public:
    void setValues(int x, double y, char z) {
        a = x;
        b = y;
        c = z;
    }

    void display() {
        cout << "a = " << a << ", b = " << b << ", c = " << c << endl;
    }
};

int main() {
    Sample obj1, obj2;

    obj1.setValues(10, 20.5, 'X');
    obj2.setValues(30, 40.25, 'Y');

    cout << "\n--- Object Values ---\n";
    cout << "Object 1: ";
    obj1.display();
    cout << "Object 2: ";
    obj2.display();

    cout << "\n--- Memory Allocation Info ---\n";
    cout << "Size of class Sample: " << sizeof(Sample) << " bytes" << endl;
    cout << "Size of object obj1: " << sizeof(obj1) << " bytes" << endl;
    cout << "Size of object obj2: " << sizeof(obj2) << " bytes" << endl;

    return 0;
}
