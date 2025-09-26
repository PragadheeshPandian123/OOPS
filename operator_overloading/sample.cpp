# include <iostream>
using namespace std;

class Array{
    int *arr;
    int size;
    public:
        Array(){
            size=1;
            arr=new int[size];
        }
        Array(int a){
            size=a;
            arr=new int[size];
            cout<<"Enter the array : "<<endl;
            for(int i=0;i<size;i++){
                cin>>arr[i];
            }
        }
        int & operator [] (int i){
            return arr[i];
        }
        friend Array & operator ++(Array &);
        friend Array & operator --(Array &);
        void display(){
            cout<<"The Array is : "<<endl;
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

Array & operator++(Array & a){
    for(int i=0;i<a.size;i++){
        a.arr[i]++;
    }
    return a;
}
Array & operator --(Array & a){
    for(int i=0;i<a.size;i++){
        a.operator[](i)--;
    }
    return a;
}

int main(){
    Array a(5);
    a.display();
    cout<<a[0];
    Array *a2= new Array(5);
    return 0;
}