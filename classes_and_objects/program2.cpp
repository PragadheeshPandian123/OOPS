#include <iostream>
#include <string>
using namespace std;

class Citizen {
    string name;
    int age;
    bool isEligible() {
        return age >= 18;
    }
public:
    void getDetails(string n, int a) {
        name = n;
        age = a;
    }
    void checkVotingEligibility() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        if (isEligible())
            cout << "Status: Eligible to vote." << endl;
        else
            cout << "Status: Not eligible to vote." << endl;
    }
};

int main() {
    string name;
    int age;
    Citizen c1;
    cout<<"Enter name of citizen : ";
    cin>>name;
    cout<<"Enter the age : ";
    cin>>age;
    c1.getDetails(name,age);
    c1.checkVotingEligibility();

    cout << endl;

    Citizen c2;
    cout<<"Enter name of citizen : ";
    cin>>name;
    cout<<"Enter the age : ";
    cin>>age;
    c2.getDetails(name,age);
    c2.checkVotingEligibility();

    return 0;
}
