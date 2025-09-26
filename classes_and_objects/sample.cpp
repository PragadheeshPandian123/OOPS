# include <iostream>
using namespace std;
class item
{
    int id;
    float val;
    public:
        void getdata(int a,float b);
        void printdata();
};

void item::getdata(int a,float b)
{
    id=a;
    val=b;
}
void item::printdata()
{
    cout<<"Id: "<<id<<endl;
    cout<<"Value: "<<val<<endl;
}
int main()
{
    item a;
    int id;
    float val;
    cout<<"Enter id : ";
    cin>>id;
    cout<<"Enter val: ";
    cin>>val;
    a.getdata(id,val);
    a.printdata();
    return 0;
}