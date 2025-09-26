#include <iostream>
using namespace std;

class Student {
private:
    string name;
    int rollNumber;
    float marks;

public:
    Student(string n, int r, float m) {
        name = n;
        rollNumber = r;
        marks = m;
    }

    void display() {
        cout << "Student Name  : " << name << endl;
        cout << "Roll Number   : " << rollNumber << endl;
        cout << "Marks         : " << marks << "%" << endl;
    }
};

int main() {
    string name;
    int roll;
    float marks;

    cout<<"Enter string: ";
    cin>>name;
    cout<<"Enter roll number: ";
    cin>>roll;
    cout<<"Enter marks: ";
    cin>>marks;
    Student s1(name,roll,marks);

    cout << "\n--- Student 1 ---\n";
    s1.display();

    return 0;
}
