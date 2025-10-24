#include <iostream>
#include <map>
#include <string>
using namespace std;
void addBook(map<string, int> &library, const string &title, int copies)
{
    library[title] += copies;
    cout << copies << " copy/copies of \"" << title << "\" added.\n";
}
void displayLibrary(const map<string, int> &library)
{
    cout << "\n--- Library Books ---\n";
    for (const auto &book : library)
    {
        cout << "\"" << book.first << "\": " << book.second << " copy/copies\n";
    }
}
void searchBook(const map<string, int> &library, const string &title)
{
    auto it = library.find(title);
    if (it != library.end())
    {
        cout << "\"" << title << "\" has " << it->second << " copy/copies.\n";
    }
    else
    {
        cout << "\"" << title << "\" not found in library.\n";
    }
}
void removeBook(map<string, int> &library, const string &title)
{
    if (library.erase(title))
    {
        cout << "\"" << title << "\" removed from library.\n";
    }
    else
    {
        cout << "\"" << title << "\" not found.\n";
    }
}
int main()
{
    map<string, int> library;
    int choice, copies;
    string title;
    do
    {
        cout << "\n--- Library Menu ---\n";
        cout << "1. Add book\n";
        cout << "2. Display books\n";
        cout << "3. Search book\n";
        cout << "4. Remove book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
            cout << "Enter book title: ";
            getline(cin, title);
            cout << "Enter number of copies: ";
            cin >> copies;
            addBook(library, title, copies);
            break;
        case 2:
            displayLibrary(library);
            break;
        case 3:
            cout << "Enter book title to search: ";
            getline(cin, title);
            searchBook(library, title);
            break;
        case 4:
            cout << "Enter book title to remove: ";
            getline(cin, title);
            removeBook(library, title);
            break;
        case 0:
            cout << "Exiting Library Tracker.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}