#include <iostream>
using namespace std;

class Base {
public:
    virtual void show() {  
        cout << "Base class function\n";
    }
};

class Derived : public Base {
public:
    void show() override {
        cout << "Derived class function\n";
    }
};

int main() {
    cout << "---- 1. static_cast ----" << endl;
    int a , b;
    cout<<"Enter a and b : ";
    cin>>a>>b;
    double result = static_cast<double>(a) / b; 
    cout << "Result of division a( converted to float ) : " << result << endl;

    cout << "\n---- 2. const_cast ----" << endl;
    const int x = 100;
    const int* ptr = &x;
    int* modPtr = const_cast<int*>(ptr);
    *modPtr = 200;  
    cout << "Original const variable (x): " << x << endl;
    cout << "Modified value through const_cast pointer: " << *modPtr << endl;

    cout << "\n---- 3. reinterpret_cast ----" << endl;
    int num ;
    cout<<"Enter num value for reinterpret cast : ";
    cin>>num;
    char* ch = reinterpret_cast<char*>(&num); 
    cout << "Reinterpreted value : " << *ch << endl;

    cout << "\n---- 4. dynamic_cast ----" << endl;
    Base* basePtr = new Derived;  
    Derived* derivedPtr = dynamic_cast<Derived*>(basePtr);  

    if (derivedPtr)
        derivedPtr->show();
    else
        cout << "Dynamic cast failed!" << endl;

    Base* base2 = new Base;
    Derived* wrongCast = dynamic_cast<Derived*>(base2);  
    if (wrongCast)
        wrongCast->show();
    else
        cout << "Dynamic cast failed for Base* to Derived*" << endl;

    delete basePtr;
    delete base2;

    return 0;
}