#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    const int rollNo;        // unique constant roll number
    string name;
    int age;
    double marks;

    static int studentCount;   // total number of students
    static double totalMarks;  // total marks of all students

public:
    // Default constructor
    Student() : rollNo(0), name("Unknown"), age(0), marks(0.0) {
        studentCount++;
        totalMarks += marks;
    }

    // Parameterized constructor
    Student(int r, string n, int a, double m) 
        : rollNo(r), name(n), age(a), marks(m) {
        studentCount++;
        totalMarks += marks;
    }

    // Function Overloading: updateMarks
    void updateMarks(double newMarks) {
        totalMarks -= marks;   // adjust old marks
        marks = newMarks;
        totalMarks += marks;
    }

    void updateMarks(double internalMarks, double externalMarks) {
        totalMarks -= marks;   // adjust old marks
        marks = internalMarks + externalMarks;
        totalMarks += marks;
    }

    // Operator Overloading: Add grace marks
    Student& operator+(double grace) {
        marks += grace;
        totalMarks += grace;
        return *this;
    }

    // Operator Overloading: Deduct penalty marks
    Student& operator-(double penalty) {
        if (marks - penalty >= 0) {
            marks -= penalty;
            totalMarks -= penalty;
        } else {
            totalMarks -= marks; // remove old marks
            marks = 0;           // cannot go below 0
        }
        return *this;
    }

    // Friend input operator
    friend istream& operator>>(istream& in, Student& s) {
        cout << "Enter Roll Number: ";
        int r;
        in >> r;
        in.ignore();
        cout << "Enter Name: ";
        getline(in, s.name);
        cout << "Enter Age: ";
        in >> s.age;
        cout << "Enter Marks: ";
        in >> s.marks;

        // rollNo is const, must use initializer (simulate via const_cast for input version)
        const_cast<int&>(s.rollNo) = r;

        studentCount++;
        totalMarks += s.marks;
        in.ignore();
        return in;
    }

    // Friend output operator
    friend ostream& operator<<(ostream& out, const Student& s) {
        out << "\n--- Student Details ---\n";
        out << "Roll No : " << s.rollNo << "\n";
        out << "Name    : " << s.name << "\n";
        out << "Age     : " << s.age << "\n";
        out << "Marks   : " << s.marks << "\n";
        return out;
    }

    // Static member function
    static void showTotalStats() {
        cout << "\n[Stats] Total Students: " << studentCount
             << " | Total Marks: " << totalMarks << "\n";
    }

    // Destructor
    ~Student() {
        cout << "\n[Destroyed] Student Roll No: " << rollNo 
             << " with Marks: " << marks << "\n";
        studentCount--;
        totalMarks -= marks;
    }
};

// Initialize static members
int Student::studentCount = 0;
double Student::totalMarks = 0.0;

// Main function
int main() {
    Student s1(101, "Pragadheesh", 20, 85.5);
    Student s2(102, "Alice", 21, 90.0);

    cout << s1;
    cout << s2;

    s1.updateMarks(95);                 // update directly
    s2.updateMarks(40, 45);             // update with internal + external

    s1 + 5;                             // grace marks
    s2 - 10;                            // penalty

    cout << s1;
    cout << s2;

    Student::showTotalStats();

    // Create a new student via input
    Student s3;
    cin >> s3;
    cout << s3;

    Student::showTotalStats();

    return 0;
}
