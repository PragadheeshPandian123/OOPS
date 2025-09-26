# include <iostream>
# include <cstring>
using namespace std;

class Person{
    int age;
    char name[20];
    float salary;
    public:
        void setdata(){
            age=0;
            strcpy(name,"Unknown");
            salary=0;
        }
        void setdata(int);
        void setdata(int , const char *);
        void setdata(int,const char *,float);
        void display(){
            cout<<"Age: "<<age<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Salary: "<<salary<<endl;
        }
};

void Person::setdata(int a){
    age=a;
    strcpy(name,"Unknown");
    salary=0;
}

void Person::setdata(int a,const char * n){
    age=a;
    strcpy(name,n);
    salary=0;
}

void Person::setdata(int a,const char * n,float sal){
    age=a;
    strcpy(name,n);
    salary=sal;
}

int main(){
    Person p1;
    p1.setdata();
    Person p2;
    p2.setdata(12);
    Person p3;
    p3.setdata(15,"Pragadheesh");
    Person p4;
    p4.setdata(18,"Hello",50000);
    p1.display();
    p2.display();
    p3.display();
    p4.display();
    return 0;
}