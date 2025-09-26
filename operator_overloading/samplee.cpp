# include <iostream>
using namespace std;

class Array {
    int *arr;
public:
    Array() {
        arr = new int[5]; // Allocate array in constructor
    }

    ~Array() {
        delete[] arr; // Free array in destructor
    }

    void* operator new(size_t size) {
        cout << "Allocating " << size << " Bytes" << endl;
        return ::operator new(size); // Correct raw memory allocation
    }

    void operator delete(void* ptr) {
        ::operator delete(ptr); // Correct raw memory deallocation
    }

    void get_Data();
    void show_Data();
};

void Array::get_Data(){
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<5;i++){
        cin>>arr[i];
    }
}

void Array::show_Data(){
    cout<<"The array elements are: "<<endl;
    for(int i=0;i<5;i++){
        cout<<arr[i]<<" ";
    }
}


int main(){
    Array * A=new Array;
    A->get_Data();A->show_Data();
    delete A;
}