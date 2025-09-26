#include <iostream>
using namespace std;

class Student {
    string name;
    int marks[5];  

    float calculateAverage() {
        int sum = 0;
        for (int i = 0; i < 5; i++) {
            sum += marks[i];
        }
        return sum / 5.0;
    }

public:
    void getDetails() {
        cout << "Enter student name: ";
        cin >> name;

        cout << "Enter marks for 5 subjects:\n";
        for (int i = 0; i < 5; i++) {
            cout << "Subject " << (i + 1) << ": ";
            cin >> marks[i];
        }
    }

    void showReport() {
        cout << "\n--- Student Report ---\n";
        cout << "Name: " << name << endl;
        cout << "Marks: ";
        for (int i = 0; i < 5; i++) {
            cout << marks[i] << " ";
        }
        cout << "\nAverage: " << calculateAverage() << endl;
    }
};

int main() {
    Student s;
    s.getDetails();
    s.showReport();
    return 0;
}
