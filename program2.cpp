# include <iostream>
using namespace std;

class Array{
    private:
        int *arr;
        int n;
    public:
        Array(){
            n=0;
        }
        Array(int );
        void show_data();
        int largest();
};

Array::Array(int a)
{
    n=a;
    arr=new int [n];
    cout<<"Enter the elements: "<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter arr["<<i<<"]: ";
        cin>>arr[i];
    }
}
void Array::show_data()
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
int Array::largest()
{
    int max=arr[0];
    for(int i=1;i<n;i++)
    {
        if(max<arr[i])
            max=arr[i];
    }
    return max;
}
int main()
{
    Array a1;
    a1.show_data();
    Array a2(5);
    a2.show_data();
    cout<<a2.largest();
    return 0;
}