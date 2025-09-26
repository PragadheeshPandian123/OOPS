#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int pages;

public:
    Book() {
        title = "Unknown Title";
        author = "Unknown Author";
        pages = 0;
        cout << "Default Book Created:\n";
    }

    void displayDetails() {
        cout << "Title  : " << title << endl;
        cout << "Author : " << author << endl;
        cout << "Pages  : " << pages << endl;
    }
};

int main() {
    Book b1;
    b1.displayDetails();
    return 0;
}
