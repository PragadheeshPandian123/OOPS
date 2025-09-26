#include <iostream>
using namespace std;

class Student {
public:
    int rollNo;
    float marks;
    void display() {
        cout << "Roll No: " << rollNo << ", Marks: " << marks << endl;
    }
};

int main() {
    Student s1;
    int roll;
    float marks;
    int Student::*ptrRoll = &Student::rollNo;
    float Student::*ptrMarks = &Student::marks;

    void (Student::*ptrDisplay)() = &Student::display;
    cout<<"Enter roll no: ";
    cin>>roll;
    cout<<"Enter marks: ";
    cin>>marks;
    s1.*ptrRoll = roll;
    s1.*ptrMarks = marks;

    (s1.*ptrDisplay)();

    return 0;
}
