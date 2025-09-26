#include <iostream>
using namespace std;


int globalCount = 100;

class Counter {
    int localCount; 

public:
    void setLocal(int value) {
        int localCount = value; 
        cout << "Inside setLocal(): Local variable localCount = " << localCount << endl;
    }

    void setAndShowGlobal() {
        ::globalCount += 10;
        cout << "Inside setAndShowGlobal(): Global variable globalCount = " << ::globalCount << endl;
    }

    void setMember(int value) {
        localCount = value;  
    }

    void showMember() {
        cout << "Member variable localCount = " << localCount << endl;
    }
};

int main() {
    Counter c1;

    cout << "Initial globalCount = " << globalCount << endl;

    c1.setLocal(50);         
    c1.setAndShowGlobal();   

    c1.setMember(20);      
    c1.showMember();         

    return 0;
}
