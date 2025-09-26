# include <iostream>
using namespace std;

int main(){
    int arr[50],size,odd=0,even=0;
    cout<<"Enter the size of the array: ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter arr["<<i<<"] : ";
        cin>>arr[i];
    }
    cout<<"The array is: "<<endl;
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
        if(arr[i]%2==0)
            even++;
        else
            odd++;
    }
    cout<<endl;
    cout<<"The number of even elements is : "<<even;
    cout<<"The number of odd elements is : "<<odd;
    return 0;
}