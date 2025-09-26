# include <iostream>
# include <cstring>
using namespace std;

class Student{
    int roll_no;
    char name[20];
    int marks[3];
    int total();
    public:
        void set_Data(int,char const *,int ,int ,int);
        void display(){
            cout<<"Roll No: "<<roll_no<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Marks: "<<total()<<endl;
        }
};

inline void Student::set_Data(int roll,char const * str,int m1,int m2,int m3){
    roll_no=roll;
    strcpy(name,str);
    marks[0]=m1;
    marks[1]=m2;
    marks[2]=m3;
}

int Student::total(){
    int sum=0;
    for(int i=0;i<3;i++){
        sum+=marks[i];
    }
}

int main(){
    Student s1;
    s1.set_Data(12,"Pragadheesh",90,90,90);
    s1.display();
    return 0;
}