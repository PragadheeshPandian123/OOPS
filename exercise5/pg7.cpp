#include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    Person(string n) : name(n) {
        cout << "Person constructor called\n";
    }
    void show_name() {
        cout << "Name: " << name << endl;
    }
};

class Student : virtual public Person {
protected:
    int roll_no;
public:
    Student(string n, int r) : Person(n), roll_no(r) {
        cout << "Student constructor called\n";
    }
    void show_roll() {
        cout << "Roll Number: " << roll_no << endl;
    }
};

class Employee : virtual public Person {
protected:
    int emp_id;
public:
    Employee(string n, int e) : Person(n), emp_id(e) {
        cout << "Employee constructor called\n";
    }
    void show_emp_id() {
        cout << "Employee ID: " << emp_id << endl;
    }
};

class Intern : public Student, public Employee {
public:
    Intern(string n, int r, int e)
        : Person(n), Student(n, r), Employee(n, e) {
        cout << "Intern constructor called\n";
    }
    void display() {
        show_name();      
        show_roll();
        show_emp_id();
    }
};

int main() {
    int rno,empid;
    char name[20];
    cout<<"Enter name : ";
    cin>>name;
    cout<<"Enter roll number : ";
    cin>>rno;
    cout<<"Enter employee id : ";     
    cin>>empid;
    Intern i(name, rno, empid);
    i.display();
    return 0;
}