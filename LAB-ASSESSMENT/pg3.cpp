#include <iostream>
#include <string>
using namespace std;

class LibraryBook {
private:
    string title;
    string author;
    int bookID;
    bool isIssued;
    static int totalBooks;          // shared among all books
    const double FINE_RATE;         // fine per day

public:
    // Default constructor
    LibraryBook() : title("Unknown"), author("Unknown"), bookID(0),
                    isIssued(false), FINE_RATE(2.0) {}

    // Parameterized constructor
    LibraryBook(string t, string a, int id)
        : title(t), author(a), bookID(id), isIssued(false), FINE_RATE(2.0) {
        totalBooks++;   // update total books
    }

    // Function Overloading: issueBook
    void issueBook() {
        if (!isIssued) {
            isIssued = true;
            cout << "Book \"" << title << "\" issued successfully (no due date).\n";
        } else {
            cout << "Book \"" << title << "\" is already issued.\n";
        }
    }

    void issueBook(int days) {
        if (!isIssued) {
            isIssued = true;
            cout << "Book \"" << title << "\" issued for " << days << " days.\n";
        } else {
            cout << "Book \"" << title << "\" is already issued.\n";
        }
    }

    // Function to return a book with delay calculation
    void returnBook(int delayedDays = 0) {
        if (isIssued) {
            isIssued = false;
            if (delayedDays > 0) {
                double fine = delayedDays * FINE_RATE;
                cout << "Book \"" << title << "\" returned with delay. Fine: ₹" << fine << "\n";
            } else {
                cout << "Book \"" << title << "\" returned on time.\n";
            }
        } else {
            cout << "Book \"" << title << "\" was not issued.\n";
        }
    }

    // Operator Overloading: Add copies of book (+)
    LibraryBook& operator+(int copies) {
        totalBooks += copies;
        cout << copies << " copies of \"" << title << "\" added.\n";
        return *this;
    }

    // Operator Overloading: Remove copies of book (-)
    LibraryBook& operator-(int copies) {
        if (copies <= totalBooks) {
            totalBooks -= copies;
            cout << copies << " copies of \"" << title << "\" removed.\n";
        } else {
            cout << "Cannot remove more copies than available.\n";
        }
        return *this;
    }

    // Friend input operator
    friend istream& operator>>(istream& in, LibraryBook& b) {
        cout << "Enter title: ";
        getline(in, b.title);
        cout << "Enter author: ";
        getline(in, b.author);
        cout << "Enter book ID: ";
        in >> b.bookID;
        in.ignore();
        b.isIssued = false;
        totalBooks++;
        return in;
    }

    // Friend output operator
    friend ostream& operator<<(ostream& out, const LibraryBook& b) {
        out << "\n--- Book Details ---\n";
        out << "Title   : " << b.title << "\n";
        out << "Author  : " << b.author << "\n";
        out << "Book ID : " << b.bookID << "\n";
        out << "Status  : " << (b.isIssued ? "Issued" : "Available") << "\n";
        return out;
    }

    // Destructor
    ~LibraryBook() {
        cout << "\n[Library Update] Total books remaining in library: " 
             << totalBooks << "\n";
    }
};

// Initialize static member
int LibraryBook::totalBooks = 0;

// Main function
int main() {
    // Create books
    LibraryBook b1("C++ Programming", "Bjarne Stroustrup", 101);
    LibraryBook b2;
    cin >> b2;

    cout << b1;
    cout << b2;

    // Issue and return operations
    b1.issueBook();
    b2.issueBook(10);
    b2.returnBook(3);   // returned after delay with fine
    b1.returnBook();    // returned on time

    // Add/remove copies
    b1 + 5;
    b1 - 2;

    cout << b1;
    cout << b2;

    return 0;
}
