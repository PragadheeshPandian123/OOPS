#include<iostream> 
#include<cstdlib> 
using namespace std; 
class ElecBill 
{ 
    string Cname; 

 
    long Cnumber; 
    int No_of_units; 
    float Amount; 
 
    void Calc_Amount( ); 
 
    public: 
        void Accept(); 
        void Display(); 
}; 
void ElecBill  :: Calc_Amount( ) 
{ 
if(No_of_units<=50) 
    { 
        Amount=0; 
    } 
    else if(No_of_units<=150) 
    { 
        Amount=(No_of_units-50)*0.80; 
    } 
    else if(No_of_units<=350) 
    { 
        Amount=80+(No_of_units-150)*1.00; 
    } 
    else 
    { 
        Amount=80+200+(No_of_units-350)*1.20; 
    } 
} 
void ElecBill :: Accept( ) 
{ 
cout<<"\nEnter customer name:"; 
cin.ignore();
getline(cin,Cname); 
cout<<"\nEnter customer number:"; 
cin>>Cnumber; 
cout<<"\nEnter number of units consumed:"; 
cin>>No_of_units; 
Calc_Amount( ); 
 
} 
void ElecBill  :: Display( ) 
{ 
cout<<"\nCustomer Name:"<<Cname; 
cout<<"\nCustomer Number:"<<Cnumber; 
cout<<"\nNumber of units:"<<No_of_units; 
cout<<"\nAmount:"<<Amount; 
} 
int main() 
{ 
    int n; 
cout<<"\nEnter n:"; 
cin>>n; 
ElecBill *c=new ElecBill[n]; 
    int i; 
    for(i=0;i<n;i++) 

 
    { 
        (c+i)->Accept(); 
    } 
    for(i=0;i<n;i++) 
    { 
        (c+i)->Display(); 
    } 
} 