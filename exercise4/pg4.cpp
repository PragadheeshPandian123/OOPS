# include <iostream>
using namespace std;
class Array{
    int arr[10];
    public:
        Array();
        void get_data();
        void show_data();
        int & operator [](int i);
        Array * operator -> (){
            return this;
        }
};
Array::Array(){
    for(int i=0;i<10;i++){
        arr[i]=0;
    }
}
void Array::get_data(){
    cout<<"\nEnter the array elements : ";
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
}

void Array::show_data(){
    cout<<"\nThe Array is : \n";
    for(int i=0;i<10;i++){
        cout<<" "<<arr[i];
    }
    cout<<endl;
}
int & Array ::operator[](int i){
    if(i<0 || i>9)
    {
        cout<<"Array index out of bounds\n";
        exit(1);
    }
    return arr[i];
}

int main(){
    Array A;
    Array * aptr=&A;
    A.get_data();
    aptr->show_data();
    cout<<"\n Modified Array Elements are : \n";
    for(int i=0;i<10;i++){
        cout<<" "<<A[i]*2;
    }
    cout<<endl;
    
    return 0;
}