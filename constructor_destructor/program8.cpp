#include <iostream>
#include <string>
using namespace std;

class Book {
    string title;
    double price;
public:
    Book(string t, double p) : title(t), price(p) {
        cout << "Book \"" << title << "\" created.\n";
    }

    void showDetails() const {
        cout << "Title: " << title << ", Price: ₹" << price << endl;
    }

    ~Book() {
        cout << "Book \"" << title << "\" destroyed.\n";
    }
};

int main() {
    const Book b1("C++ Basics", 299.50); 
    b1.showDetails(); 
    
    cout << "End of program.\n";
    return 0;
}
