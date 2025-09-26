#include <iostream>
using namespace std;

void square(int x) {
    cout << "Square of " << x << " = " << x * x << endl;
}

int main() {
    int a = 10;
    int *p = &a;  
    cout << "Value of a: " << a << endl;
    cout << "Address of a (&a): " << &a << endl;
    cout << "Pointer p stores: " << p << endl;
    cout << "Value at *p: " << *p << endl;

    cout << "\n--- Pointer Arithmetic on Arrays ---\n";
    int arr[5] = {10, 20, 30, 40, 50};
    int *q = arr;   

    cout << "Array traversal using pointer arithmetic:\n";
    for(int i=0; i<5; i++) {
        cout << "*(q + " << i << ") = " << *(q + i) 
             << "  [address: " << (q+i) << "]" << endl;
    }

    cout << "\n--- Increment & Decrement Rules ---\n";
    cout << "q points to arr[0] = " << *q << endl;
    q++; 
    cout << "After q++, q points to arr[1] = " << *q << endl;
    q--;
    cout << "After q--, q points back to arr[0] = " << *q << endl;

    cout << "\n--- Pointer Difference ---\n";
    int *r = &arr[4];
    cout << "r points to arr[4] = " << *r << endl;
    cout << "Number of elements between r and q = " << (r - q) << endl;

    cout << "\n--- Const with Pointers ---\n";
    const int x = 100;
    const int *ptr1 = &x;
    cout << "Pointer to const data: *ptr1 = " << *ptr1 << endl;

    int y = 200;
    int *const ptr2 = &y;  
    *ptr2 = 300;           
    cout << "Const pointer to variable: *ptr2 = " << *ptr2 << endl;

    cout << "\n--- Void Pointer (Generic Pointer) ---\n";
    const void *vp;
    vp = &a;
    cout << "Void pointer pointing to a, value = " << *(int*)vp << endl;
    vp = &x;
    cout << "Void pointer pointing to x, value = " << *(const int*)vp << endl;

    cout << "\n--- Function Pointer ---\n";
    void (*fp)(int) = square; 
    fp(5);

    cout << "\n--- Double Pointer ---\n";
    int **pp = &p; 
    cout << "pp stores address of p: " << pp << endl;
    cout << "Value at *pp (i.e. address in p): " << *pp << endl;
    cout << "Value at **pp (i.e. a): " << **pp << endl;

    return 0;
}
