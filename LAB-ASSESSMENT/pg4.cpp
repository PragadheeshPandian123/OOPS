#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;
    static double totalDeposits;    // shared across all accounts
    const double MIN_BALANCE;       // minimum required balance

public:
    // Default constructor
    BankAccount() : accountHolder("Unknown"), accountNumber(0), balance(0.0), MIN_BALANCE(500.0) {}

    // Parameterized constructor
    BankAccount(string holder, int accNo, double openingBalance)
        : accountHolder(holder), accountNumber(accNo), balance(openingBalance), MIN_BALANCE(500.0) {
        if (balance < MIN_BALANCE) {
            balance = MIN_BALANCE;
            cout << "Opening balance set to minimum ₹" << MIN_BALANCE << "\n";
        }
        totalDeposits += balance;
    }

    // Function Overloading: deposit
    void deposit(double amount) {
        balance += amount;
        totalDeposits += amount;
        cout << "₹" << amount << " deposited successfully.\n";
    }

    void deposit(double amount, string source) {
        balance += amount;
        totalDeposits += amount;
        cout << "₹" << amount << " deposited via " << source << ".\n";
    }

    // Operator Overloading: Withdraw money (-)
    BankAccount& operator-(double amount) {
        if (balance - amount >= MIN_BALANCE) {
            balance -= amount;
            cout << "₹" << amount << " withdrawn successfully.\n";
        } else {
            cout << "Withdrawal failed! Minimum balance of ₹" << MIN_BALANCE << " required.\n";
        }
        return *this;
    }

    // Operator Overloading: Add interest (+)
    BankAccount& operator+(double interest) {
        balance += interest;
        totalDeposits += interest;
        cout << "Interest of ₹" << interest << " added.\n";
        return *this;
    }

    // Friend input operator
    friend istream& operator>>(istream& in, BankAccount& acc) {
        cout << "Enter Account Holder Name: ";
        getline(in, acc.accountHolder);
        cout << "Enter Account Number: ";
        in >> acc.accountNumber;
        cout << "Enter Opening Balance: ";
        in >> acc.balance;
        if (acc.balance < acc.MIN_BALANCE) {
            acc.balance = acc.MIN_BALANCE;
            cout << "Opening balance set to minimum ₹" << acc.MIN_BALANCE << ".\n";
        }
        totalDeposits += acc.balance;
        in.ignore(); // clear buffer
        return in;
    }

    // Friend output operator
    friend ostream& operator<<(ostream& out, const BankAccount& acc) {
        out << "\n--- Account Details ---\n";
        out << "Account Holder : " << acc.accountHolder << "\n";
        out << "Account Number : " << acc.accountNumber << "\n";
        out << "Current Balance: ₹" << acc.balance << "\n";
        return out;
    }

    // Destructor
    ~BankAccount() {
        cout << "\n[Bank Update] Total Deposited across all accounts: ₹"
             << totalDeposits << "\n";
    }
};

// Initialize static member
double BankAccount::totalDeposits = 0.0;

// Main function
int main() {
    // Create first account
    BankAccount acc1("Pragadheesh", 101, 1000.0);
    cout << acc1;

    // Deposit with and without source
    acc1.deposit(2000);
    acc1.deposit(5000, "Cheque");

    // Withdraw money
    acc1 - 1200;

    // Add interest
    acc1 + 300;

    cout << acc1;

    // Create another account with user input
    BankAccount acc2;
    cin >> acc2;
    cout << acc2;

    acc2.deposit(1000, "Cash Deposit");
    acc2 - 800;

    cout << acc2;

    return 0;
}
