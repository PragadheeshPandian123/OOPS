#include <iostream>
using namespace std;

class Numbers {
private:
    int* arr;
    int size;

public:
    Numbers(int s) {
        size = s;
        arr = new int[size];  
        cout << "Enter " << size << " numbers:\n";
        for (int i = 0; i < size; i++) {
            cout << "Element " << i + 1 << ": ";
            cin >> arr[i];
        }
    }

    void display() {
        cout << "\nThe numbers you entered are:\n";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    ~Numbers() {
        delete[] arr;
        cout << "Memory released.\n";
    }
};

int main() {
    int n;
    cout << "Enter how many numbers: ";
    cin >> n;

    Numbers obj(n);  
    obj.display();

    return 0;
}
