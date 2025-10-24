#include <iostream>
using namespace std;

class InvalidAgeException {
    int age;
public:
    InvalidAgeException(int a) : age(a) {}
    void displayMessage() {
        cout << "Invalid Age Entered: " << age << ". Age must be between 0 and 150.\n";
    }
};

void checkVotingEligibility(int age) {
    try {
        if (age < 0 || age > 150) {
            throw InvalidAgeException(age); 
        }
        if (age >= 18) {
            cout << "You are eligible to vote." << endl;
        } else {
            cout << "You are NOT eligible to vote." << endl;
        }
    }
    catch (InvalidAgeException &e) {
        cout << "Caught in checkVotingEligibility(): ";
        e.displayMessage();
        cout << "Re-throwing the exception to main()." << endl;
        throw;  
    }
}

int main() {
    int age;
    cout << "Enter your age: ";
    cin >> age;

    try {
        checkVotingEligibility(age);
    }
    catch (InvalidAgeException &e) {
        cout << "Caught in main(): ";
        e.displayMessage();
    }

    cout << "Program continues after exception handling." << endl;
    return 0;
}
