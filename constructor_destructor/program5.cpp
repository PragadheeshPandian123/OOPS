#include <iostream>
#include <string>
using namespace std;

class Student {
    string name;
    int age;
    string course;

public:
    Student(string n = "Unknown", int a = 18, string c = "Not Assigned") {
        name = n;
        age = a;
        course = c;
    }

    void display() {
        cout << "Name   : " << name << endl;
        cout << "Age    : " << age << endl;
        cout << "Course : " << course << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    Student s1; 
    string name,course;
    int age;
    Student s2("Pragadheesh");
    Student s3("Anita", 21); 
    Student s4("Ravi",20,"Computer Science");

    s1.display();
    s2.display();
    s3.display();
    s4.display();

    return 0;
}
