# include <iostream>
using namespace std;
typedef struct {
    int id;
    char name[50];
    float salary;
}Employee;
typedef union{
    int intVal;
    char charVal;
    float floatVal;
}Data;

int main(){
    Employee e1;
    cout<<"Enter id: ";
    cin>>e1.id;
    cout<<"Enter name: ";
    cin>>e1.name;
    cout<<"Enter salary: ";
    cin>>e1.salary;

    cout<<"Employee details"<<endl;
    cout<<"Id: "<<e1.id;
    cout<<"Name: "<<e1.name;
    cout<<"Salary: "<<e1.salary;
    Data d;
    cout<<"\n Union Behaviour \n";
    d.intVal=100;
    cout<<"intVal = "<<d.intVal<<endl;
    d.floatVal=98.76;
    cout<<"floatVal = "<<d.floatVal<<endl;
    cout<<"intVal (after flaotVal set )= "<<d.intVal<<" (may be garbage) "<<endl;
    d.charVal='A';
    cout<<"charVal= "<<d.charVal<<endl;
    return 0;
}