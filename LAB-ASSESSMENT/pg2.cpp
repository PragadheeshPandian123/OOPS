#include <iostream>
#include <string>
using namespace std;

class ShoppingCart {
private:
    string customerName;
    const int customerID;        // constant unique ID
    double totalAmount;
    static double totalTransactions;  // shared across all carts

public:
    // Default constructor
    ShoppingCart() : customerName("Unknown"), customerID(0), totalAmount(0.0) {}

    // Parameterized constructor
    ShoppingCart(string name, int id, double amt = 0.0)
        : customerName(name), customerID(id), totalAmount(amt) {
        totalTransactions += amt;
    }

    // Function Overloading: add item
    void addItem(string itemName, double price) {
        totalAmount += price;
        totalTransactions += price;
        cout << "Item: " << itemName << " | Price: ₹" << price << " added.\n";
    }

    void addItem(string itemName, int quantity, double price) {
        double cost = quantity * price;
        totalAmount += cost;
        totalTransactions += cost;
        cout << "Item: " << itemName << " | Qty: " << quantity 
             << " | Price: ₹" << cost << " added.\n";
    }

    // Operator Overloading: Apply discount (-)
    ShoppingCart& operator-(double discount) {
        if (discount <= totalAmount) {
            totalAmount -= discount;
            totalTransactions -= discount;
            cout << "Discount of ₹" << discount << " applied.\n";
        } else {
            cout << "Invalid discount! Exceeds total amount.\n";
        }
        return *this;
    }

    // Operator Overloading: Add delivery charge (+)
    ShoppingCart& operator+(double charge) {
        totalAmount += charge;
        totalTransactions += charge;
        cout << "Delivery charge of ₹" << charge << " added.\n";
        return *this;
    }

    // Friend input operator
    friend istream& operator>>(istream& in, ShoppingCart& c) {
        cout << "Enter customer name: ";
        getline(in, c.customerName);
        cout << "Enter initial bill amount: ";
        in >> c.totalAmount;
        totalTransactions += c.totalAmount;
        in.ignore(); // clear buffer
        return in;
    }

    // Friend output operator
    friend ostream& operator<<(ostream& out, const ShoppingCart& c) {
        out << "\n--- Shopping Cart Details ---\n";
        out << "Customer Name: " << c.customerName << "\n";
        out << "Customer ID  : " << c.customerID << "\n";
        out << "Total Amount : ₹" << c.totalAmount << "\n";
        return out;
    }

    // Destructor
    ~ShoppingCart() {
        cout << "\n[Session Ended] Total Transactions across all carts: ₹"
             << totalTransactions << "\n";
    }
};

// Initialize static member
double ShoppingCart::totalTransactions = 0.0;

int main() {
    // Create cart with constructor
    ShoppingCart cart1("Pragadheesh", 101, 500.0);
    cout << cart1;

    // Add items
    cart1.addItem("Headphones", 1500);
    cart1.addItem("Keyboard", 2, 700);

    // Apply discount and delivery charge
    cart1 - 500;
    cart1 + 100;

    cout << cart1;

    // Another customer cart
    ShoppingCart cart2("Alice", 102);
    cart2.addItem("Shoes", 2000);
    cart2 - 200;
    cart2 + 50;

    cout << cart2;

    return 0;
}
