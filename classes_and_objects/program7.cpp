#include <iostream>
using namespace std;

class Employee {
private:
    string name;
    float salary;

public:
    void setName(string n) {
        name = n;
    }

    void showDetails() const {
        cout << "Employee Name: " << name << endl;
        cout << "Salary: ₹" << salary << endl;
    }

    friend class Manager;
};

class Manager {
public:
    void setSalary(Employee &e, float newSalary = 25000.0) {
        if (newSalary >= 0) {
            e.salary = newSalary;
            cout << "Manager set salary to ₹" << e.salary << endl;
        } else {
            cout << "Invalid salary amount!" << endl;
        }
    }

    void giveRaise(Employee &e, float amount = 5000.0) {
        if (amount > 0) {
            e.salary += amount;
            cout << "Manager increased salary by ₹" << amount
                 << ". New salary is ₹" << e.salary << endl;
        } else {
            cout << "Invalid raise amount!" << endl;
        }
    }
};

int main() {
    Employee emp;
    Manager mgr;

    emp.setName("Ravi");

    mgr.setSalary(emp);

    cout << "\n--- Initial Details ---\n";
    emp.showDetails();

    mgr.giveRaise(emp);

    cout << "\n--- After Default Raise ---\n";
    emp.showDetails();

    mgr.setSalary(emp, 40000);
    mgr.giveRaise(emp, 6000);

    cout << "\n--- After Custom Update ---\n";
    emp.showDetails();

    return 0;
}
