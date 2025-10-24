#include <iostream>
#include <cstring>
using namespace std;

class Book {
protected:
    char title[50];
    char author[30];
    int book_id;
public:
    Book(const char* t, const char* a, int id) {
        strcpy(title, t);
        strcpy(author, a);
        book_id = id;
        cout << "Book constructor called\n";
    }

    virtual void display() {
        cout << "Book ID: " << book_id << "\nTitle: " << title << "\nAuthor: " << author << endl;
    }

    virtual ~Book() {
        cout << "Book destructor called\n";
    }
};

class Member : public Book {
protected:
    char member_name[30];
    int member_id;
public:
    Member(const char* t, const char* a, int bid, const char* mname, int mid)
        : Book(t, a, bid) {
        strcpy(member_name, mname);
        member_id = mid;
        cout << "Member constructor called\n";
    }

    void display() override {
        Book::display();
        cout << "Member ID: " << member_id << "\nMember Name: " << member_name << endl;
    }

    ~Member() {
        cout << "Member destructor called\n";
    }
};

class Transaction : public Member {
    char issue_date[15];
    char return_date[15];
public:
    Transaction(const char* t, const char* a, int bid,
                const char* mname, int mid,
                const char* issue, const char* ret)
        : Member(t, a, bid, mname, mid) {
        strcpy(issue_date, issue);
        strcpy(return_date, ret);
        cout << "Transaction constructor called\n";
    }

    void display() override {
        Member::display();
        cout << "Issue Date: " << issue_date << "\nReturn Date: " << return_date << endl;
    }

    ~Transaction() {
        cout << "Transaction destructor called\n";
    }
};

int main() {
    char title[50], author[30], member_name[30], issue[15], ret[15];
    int book_id, member_id;

    cout << "Enter Book Title: ";
    cin.getline(title, 50);
    cout << "Enter Author Name: ";
    cin.getline(author, 30);
    cout << "Enter Book ID: ";
    cin >> book_id;
    cin.ignore();

    cout << "Enter Member Name: ";
    cin.getline(member_name, 30);
    cout << "Enter Member ID: ";
    cin >> member_id;
    cin.ignore(); 

    cout << "Enter Issue Date (dd-mm-yyyy): ";
    cin.getline(issue, 15);
    cout << "Enter Return Date (dd-mm-yyyy): ";
    cin.getline(ret, 15);

    Transaction t(title, author, book_id, member_name, member_id, issue, ret);

    int choice;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display Transaction Info\n";
        cout << "2. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.display();
                break;
            case 2:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 2);

    return 0;
}