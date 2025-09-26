#include <iostream>
using namespace std;

class Employee {
    int id;
    string name;
    float salary;

public:
    void getDetails() {
        cout << "\nEnter Employee ID: ";
        cin >> id;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Salary: ";
        cin >> salary;
    }

    void showDetails() const {
        cout << "\nID: " << id << ", Name: " << name << ", Salary: Rs. " << salary;
    }

    void compareSalary(Employee other) const {
        cout << "\n\nComparing Salaries:" << endl;
        if (salary > other.salary)
            cout << name << " earns more than " << other.name << "." << endl;
        else if (salary < other.salary)
            cout << other.name << " earns more than " << name << "." << endl;
        else
            cout << name << " and " << other.name << " earn the same." << endl;
    }
};

int main() {
    Employee emp[2]; 

    for (int i = 0; i < 2; i++) {
        cout << "\n--- Enter details for Employee " << (i + 1) << " ---";
        emp[i].getDetails();
    }

    cout << "\n=== Employee Records ===";
    for (int i = 0; i < 2; i++) {
        emp[i].showDetails();
    }

    emp[0].compareSalary(emp[1]);

    return 0;
}
