# include <iostream>
using namespace std;
int main(){
    int num;
    cout<<"Enter a number : ";
    cin>>num;
    cout<<"Check if even or odd using bitwise AND "<<endl;
    cout<<num<<" is "<<((num&1)?"Odd":"Even")<<endl;
    cout<<"Check if positive or negative using bitwise shift "<<endl;
    cout<<num<<" is "<<((num>>31)?"negative":"positive")<<endl;
    cout<<"Multiply by 2 using left shift "<<endl;
    cout<<num<<" multiplied by 2 is "<<(num<<1)<<endl;
    cout<<"Divide by 2 usinf right shift "<<endl;
    cout<<num<<" divided by 2 is "<<(num>>1)<<endl;
    cout<<"Toggle sign using bitwise NOT"<<endl;
    cout<<"Sign Toggles : "<<(~num+1)<<endl;
    int a,b;
    cout<<"Enter two numbers separated by space: ";
    cin>>a>>b;
    cout<<"Check if numbers have opposite signs using XOR "<<endl;
    if((a^b)<0){
        cout<<a<<" and "<<b<<" have opposite signs "<<endl;
    }
    else{
        cout<<a<<" and "<<b<<" have same signs "<<endl;
    }
    return 0;
}