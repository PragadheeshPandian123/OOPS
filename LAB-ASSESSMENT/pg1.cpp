#include <iostream>
#include <string>
using namespace std;

class EWallet {
private:
    string name;
    int age;
    string address;
    double amount;
    static double totalTransacted;   // shared among all objects
    const double MIN_BALANCE;        // constant minimum balance

public:
    // Constructor with initialization list
    EWallet(string n = "", int a = 0, string addr = "", double amt = 0.0)
        : name(n), age(a), address(addr), amount(amt), MIN_BALANCE(100.0) {
        if (amount < MIN_BALANCE) {
            amount = MIN_BALANCE; // Ensure minimum balance on initialization
        }
    }

    // Function Overloading: Add money
    void addMoney(double amt) {
        amount += amt;
        totalTransacted += amt;
        cout << "₹" << amt << " added successfully.\n";
    }

    void addMoney(double amt, string source) {
        amount += amt;
        totalTransacted += amt;
        cout << "₹" << amt << " added via " << source << ".\n";
    }

    // Operator Overloading: Deduct money ( - )
    EWallet& operator-(double amt) {
        if (amount - amt >= MIN_BALANCE) {
            amount -= amt;
            totalTransacted += amt;
            cout << "₹" << amt << " deducted successfully.\n";
        } else {
            cout << "Transaction failed! Minimum balance of ₹" << MIN_BALANCE << " required.\n";
        }
        return *this;
    }

    // Operator Overloading: Add money ( + )
    EWallet& operator+(double amt) {
        amount += amt;
        totalTransacted += amt;
        cout << "₹" << amt << " added successfully.\n";
        return *this;
    }

    // Friend function for input
    friend istream& operator>>(istream& in, EWallet& w) {
        cout << "Enter Name: ";
        getline(in, w.name);
        cout << "Enter Age: ";
        in >> w.age;
        in.ignore(); // Clear newline
        cout << "Enter Address: ";
        getline(in, w.address);
        cout << "Enter Initial Amount: ";
        in >> w.amount;
        if (w.amount < w.MIN_BALANCE) {
            w.amount = w.MIN_BALANCE;
            cout << "Initial amount set to minimum balance ₹" << w.MIN_BALANCE << ".\n";
        }
        return in;
    }

    // Friend function for output
    friend ostream& operator<<(ostream& out, const EWallet& w) {
        out << "\n--- Wallet Details ---\n";
        out << "Name: " << w.name << "\nAge: " << w.age 
            << "\nAddress: " << w.address 
            << "\nWallet Balance: ₹" << w.amount << "\n";
        return out;
    }

    // Destructor
    ~EWallet() {
        cout << "\n[Session Ended] Total Transacted across all wallets: ₹" 
             << totalTransacted << "\n";
    }
};

// Initialize static member
double EWallet::totalTransacted = 0.0;

// Main function
int main() {
    EWallet w1;
    cin >> w1;
    cout << w1;

    // Transactions
    w1.addMoney(500);
    w1.addMoney(1000, "Bank Transfer");
    w1 - 200;
    w1 + 300;

    cout << w1;

    return 0;
}
