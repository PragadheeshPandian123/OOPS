#include <iostream>
using namespace std;

class Student {
    int rollNumber;
    string name;
    string course;

    static int totalStudents;

public:
 
    void getDetails() {
        cout << "\nEnter Roll Number: ";
        cin >> rollNumber;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Course: ";
        getline(cin, course);

        totalStudents++; 
    }

    void showDetails() const {
        cout << "\n--- Student Info ---" << endl;
        cout << "Roll Number: " << rollNumber << endl;
        cout << "Name: " << name << endl;
        cout << "Course: " << course << endl;
    }

    static void showTotalAdmissions() {
        cout << "\nTotal Students Admitted: " << totalStudents << endl;
    }
};


int Student::totalStudents = 0;

int main() {
    const int MAX = 100;
    Student students[MAX];  
    int count = 0;
    char choice;

    do {
        cout << "\n--- New Admission ---" << endl;
        students[count].getDetails();
        count++;

        cout << "Do you want to admit another student? (Y/N): ";
        cin >> choice;
    } while ((choice == 'Y' || choice == 'y') && count < MAX);

    cout << "\n=== Admission Details ===";
    for (int i = 0; i < count; i++) {
        students[i].showDetails();
    }

    Student::showTotalAdmissions();

    return 0;
}
