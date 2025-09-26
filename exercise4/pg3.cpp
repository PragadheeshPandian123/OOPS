#include <iostream>
#include <cstdlib>   
using namespace std;

class MyClass {
    int data;
public:
    MyClass(int val = 0) : data(val) {
        cout << "Constructor called, data = " << data << endl;
    }

    ~MyClass() {
        cout << "Destructor called, data = " << data << endl;
    }

    void* operator new(size_t size) {
        cout << "Custom new: allocating " << size << " bytes" << endl;
        void* p = malloc(size);
        if (!p) {
            bad_alloc ba;
            throw ba;
        }
        return p;
    }

    void operator delete(void* p) {
        cout << "Custom delete: freeing memory" << endl;
        free(p);
    }
};

int main() {
    MyClass* obj = new MyClass(42);  
    delete obj;                      
    return 0;
}
