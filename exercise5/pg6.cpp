# include <iostream>
# include <cstring>
using namespace std;

class Marks
{
    protected :
    int marks[3];
    public:
    Marks(int m1,int m2,int m3)
    {
        marks[0]=m1;marks[1]=m2;marks[2]=m3;
        cout<<"IN MARKS CONSTRUCTOR - SECOND BASE CLASS "<<endl;
    }
    ~Marks()
    {
        cout<<"IN MARKS DESTRUCTOR - SECOND BASE CLASS "<<endl;
    }
    int total()
    {
        return (marks[0] + marks[1] + marks[2]);
    }
};

class Student
{
    protected :
    int roll_no;
    char name[20];
    char course[10];
    public:
    Student(int r, char * n ,char * c)
    {
        roll_no=r;
        strcpy(name,n);
        strcpy(course,c);
        cout<<"IN STUDENTS' CONSTRUCTOR - FIRST BASE CLASS "<<endl;
    }
    ~Student()
    {
        cout<<"IN STUDENT'S DESTRUCTOR - FIRST BASE CLASS "<<endl;
    }
    int get_rno()
    {
        return roll_no;
    }
    char * get_name()
    {
        return name;
    }
    char * get_course()
    {
        return course;
    }
};

class Result: public Student ,public Marks
{
    public:
    Result(int r,char * n ,char * c , int m1,int m2,int m3):Student(r,n,c),Marks(m1,m2,m3)
    {
        cout<<"IN RESULT'S CONSTRUCTOR - DERIVED CLASS "<<endl;
    }
    ~Result()
    {
        cout<<"IN RESULT'S DESTRUCTOR - DERIVED CLASS "<<endl;
    }
    void display()
    {
        cout<<"ROLL NUMBER : "<<get_rno()<<endl;
        cout<<"NAME : "<<get_name()<<endl;
        cout<<"COURSE : "<<get_course()<<endl;
        cout<<"TOTAL MARKS : "<<total()<<endl;
    }
};

int main()
{
    int rno,m1,m2,m3;
    char n[20],c[10];
    cout<<"Enter roll number : ";
    cin>>rno;

    cout<<"Enter name : ";
    cin.ignore();
    cin.getline(n,20);

    cout<<"Enter course : ";
    cin.getline(c,10);
    cout<<"Enter marks in three subjects : ";
    cin>>m1>>m2>>m3;
    Result R(rno,n,c,m1,m2,m3);
    R.display();
    return 0;
}
