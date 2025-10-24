#include <iostream>
using namespace std;

// Function that can throw multiple exceptions
// Specifying the throw list: this function may throw const char*, int, char
void performOperation() throw(const char*, int, char) {
    int choice;
    cout << "Choose operation:\n1. Division\n2. Access array element\nEnter choice: ";
    cin >> choice;

    if (choice == 1) {
        int a, b;
        cout << "Enter numerator and denominator: ";
        cin >> a >> b;
        if (b == 0) {
            throw "Division by zero error!"; // throw string exception
        }
        cout << "Result = " << a / b << endl;
    }
    else if (choice == 2) {
        int arr[5] = {10, 20, 30, 40, 50};
        int index;
        cout << "Enter array index (0-4): ";
        cin >> index;
        if (index < 0 || index >= 5) {
            throw index; // throw integer exception
        }
        cout << "arr[" << index << "] = " << arr[index] << endl;
    }
    else {
        throw 'x'; // throw char exception for invalid choice
    }
}

int main() {
    try {
        performOperation();
    }
    catch (const char* msg) {
        cout << "String Exception: " << msg << endl;
    }
    catch (int i) {
        cout << "Integer Exception: Invalid array index " << i << endl;
    }
    catch (char c) {
        cout << "Char Exception: Invalid choice '" << c << "'" << endl;
    }
    catch (...) {
        cout << "Unknown Exception caught!" << endl;
    }

    cout << "Program continues after exception handling." << endl;
    return 0;
}
