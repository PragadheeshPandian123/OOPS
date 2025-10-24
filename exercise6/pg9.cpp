#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    int choice;

    cout << "Enter first string: ";
    getline(cin, str1);

    do {
        cout << "\n========== STRING OPERATIONS MENU ==========\n";
        cout << "1. Concatenate another string\n";
        cout << "2. Find length of string\n";
        cout << "3. Insert substring\n";
        cout << "4. Delete (erase) substring\n";
        cout << "5. Compare with another string\n";
        cout << "6. Extract substring\n";
        cout << "7. Replace substring\n";
        cout << "8. Find position of substring\n";
        cout << "9. Display current string\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // clear newline from buffer

        switch (choice) {
            case 1: {
                cout << "Enter string to concatenate: ";
                getline(cin, str2);
                str1 = str1 + str2;
                cout << "After concatenation: " << str1 << endl;
                break;
            }

            case 2: {
                cout << "Length of string: " << str1.length() << endl;
                break;
            }

            case 3: {
                int pos;
                cout << "Enter position to insert: ";
                cin >> pos;
                cin.ignore();
                cout << "Enter substring to insert: ";
                getline(cin, str2);
                str1.insert(pos, str2);
                cout << "After insertion: " << str1 << endl;
                break;
            }

            case 4: {
                int pos, len;
                cout << "Enter starting position: ";
                cin >> pos;
                cout << "Enter length to delete: ";
                cin >> len;
                str1.erase(pos, len);
                cout << "After deletion: " << str1 << endl;
                break;
            }

            case 5: {
                cout << "Enter string to compare: ";
                getline(cin, str2);
                int result = str1.compare(str2);
                if (result == 0)
                    cout << "Strings are equal.\n";
                else if (result > 0)
                    cout << "First string is greater.\n";
                else
                    cout << "First string is smaller.\n";
                break;
            }

            case 6: {
                int pos, len;
                cout << "Enter starting position: ";
                cin >> pos;
                cout << "Enter length of substring: ";
                cin >> len;
                cout << "Substring: " << str1.substr(pos, len) << endl;
                break;
            }

            case 7: {
                int pos, len;
                cout << "Enter starting position: ";
                cin >> pos;
                cout << "Enter length to replace: ";
                cin >> len;
                cin.ignore();
                cout << "Enter new substring: ";
                getline(cin, str2);
                str1.replace(pos, len, str2);
                cout << "After replacement: " << str1 << endl;
                break;
            }

            case 8: {
                cout << "Enter substring to find: ";
                getline(cin, str2);
                size_t pos = str1.find(str2);
                if (pos != string::npos)
                    cout << "Found at position: " << pos << endl;
                else
                    cout << "Substring not found!" << endl;
                break;
            }

            case 9: {
                cout << "Current string: " << str1 << endl;
                break;
            }

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}