# include <iostream>
using namespace std;

void change_copy(int a){
    a=a*a;
}

void change_ref(int &a){
    a=a*a;
}

void change_address(int arr[],int n){
    for(int i=0;i<n;i++){
        arr[i]=arr[i]*arr[i];
    }
}

int main(){
    int arr[50],size;
    cout<<"Enter size: ";
    cin>>size;
    cout<<"Enter the array: ";
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    cout<<"The array before change is : "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        change_copy(arr[i]);
    }
    cout<<"After change_copy():"<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<size;i++){
        change_ref(arr[i]);
    }
    cout<<"After change_ref(): "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    change_address(arr,size);
    cout<<"After change_address(): "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}