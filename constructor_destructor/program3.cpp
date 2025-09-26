#include <iostream>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    string accountNumber;
    float balance;

public:
    BankAccount(string name, string number, float amount) {
        accountHolder = name;
        accountNumber = number;
        balance = amount;
    }

    BankAccount(const BankAccount &acc) {
        accountHolder = acc.accountHolder;
        accountNumber = acc.accountNumber + "_COPY";  
        balance = acc.balance;
    }

    void display() {
        cout << "Account Holder : " << accountHolder << endl;
        cout << "Account Number : " << accountNumber << endl;
        cout << "Balance        : ₹" << balance << endl;
    }
};

int main() {
    string name;
    string acnum;
    float balance;
    cout<<"Enter name: ";
    cin>>name;
    cout<<"Enter account number: ";
    cin>>acnum;
    cout<<"Enter balance: ";
    cin>>balance;

    BankAccount acc1(name,acnum,balance);
    
    BankAccount acc2 = acc1;

    cout << "--- Original Account ---\n";
    acc1.display();

    cout << "\n--- Copied Account ---\n";
    acc2.display();

    return 0;
}
