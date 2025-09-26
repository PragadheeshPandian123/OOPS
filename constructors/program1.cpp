# include <iostream>
# include <string>
using namespace std;

class Person{
    private:
        int age;
        string first_name;
        string mid_name;
        string last_name;
    public:
        Person(){
            age=-1;
            first_name='\0';
            mid_name='\0';
            last_name='\0';
        }
        Person(int a)
        {
            age=a;
            first_name='\0';
            mid_name='\0';
            last_name='\0';
        }
        Person(int a,string fname)
        {
            age=a;
            first_name=fname;
            mid_name='\0';
            last_name='\0';
        }
        Person(int a,string fname,string mname)
        {
            age=a;
            first_name=fname;
            mid_name=mname;
            last_name="\0";
        }
        Person(int a,string fname,string mname,string lname)    
        {
            age=a;
            first_name=fname;
            mid_name=mname;
            last_name=lname;
        }
        void show_data()
        {
            cout<<"NAME: "<<first_name<<" "<<mid_name<<" "<<last_name<<endl;
            cout<<"AGE: "<<age<<endl;
        }
};


int main()
{
    Person p1;
    Person p2(18);
    Person p3(17,"xyz");
    Person p4(56,"abc","poi");
    Person p5(56,"kjh","tyu","qwer");
    p1.show_data();
    p2.show_data();
    p3.show_data();
    p4.show_data();
    p5.show_data();
    return 0;
}