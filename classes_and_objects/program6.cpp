#include <iostream>
using namespace std;

class Semester {
    float gpa;
    int credits;

public:

    void getDetails(int semNum) {
        cout << "\nEnter GPA for Semester " << semNum << ": ";
        cin >> gpa;
        cout << "Enter credits for Semester " << semNum << ": ";
        cin >> credits;
    }

    void showDetails() const {
        cout << "GPA: " << gpa << ", Credits: " << credits << endl;
    }

    void showCGPA()const{
        cout << "CGPA: " << gpa << ", Credits: " << credits << endl;
    }
    friend Semester calculateCGPA(Semester s1, Semester s2);
};

Semester calculateCGPA(Semester s1, Semester s2) {
    Semester result;
    int totalCredits = s1.credits + s2.credits;
    float weightedGPA = ((s1.gpa * s1.credits) + (s2.gpa * s2.credits)) / totalCredits;

    result.gpa = weightedGPA;
    result.credits = totalCredits;

    return result;
}

int main() {
    Semester sem1, sem2, finalCGPA;

    sem1.getDetails(1);
    sem2.getDetails(2);

    cout << "\n--- Semester Details ---\n";
    cout << "Semester 1: "; sem1.showDetails();
    cout << "Semester 2: "; sem2.showDetails();


    finalCGPA = calculateCGPA(sem1, sem2);
    cout << "\n=== Final CGPA ===\n";
    finalCGPA.showCGPA();

    return 0;
}
