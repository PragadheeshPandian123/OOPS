#include <iostream>
using namespace std;

class B;

class A {
private:
    int data;
public:
    A(int val) : data(val) {}
    void display() { cout << "A's data: " << data << endl; }
    friend void swapData(A&, B&);
};

class B {
private:
    int data;
public:
    B(int val) : data(val) {}
    void display() { cout << "B's data: " << data << endl; }
    friend void swapData(A&, B&);
};

void swapData(A& a, B& b) {
    int temp = a.data;
    a.data = b.data;
    b.data = temp;
}

int main() {
    int x,y;
    cout<<"Enter Data for A: ";
    cin>>x;
    cout<<"Enter Data for B: ";
    cin>>y;
    A a(x);
    B b(y);

    cout << "Before swap:\n";
    a.display();
    b.display();

    swapData(a, b);

    cout << "After swap:\n";
    a.display();
    b.display();

    return 0;
}
