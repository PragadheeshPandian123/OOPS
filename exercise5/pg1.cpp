# include <iostream>
using namespace std;

class Student
{
    int roll_no;
    protected:
    char course[10];
    public:
    void get_rno()
    {
        cout<<"Enter the roll no : ";
        cin>>roll_no;
    }
    void show_rno()
    {
        cout<<"Roll Number : "<<roll_no<<endl;
    }
};

class Result: public Student
{
    private:
    int marks[3];
    public:
    void get_data();
    int total();
    void display()
    {
        show_rno();
        cout<<"Course : "<<course<<endl;
        cout<<"Total Marks : "<<total()<<endl;
    }
};

void Result::get_data()
{
    get_rno();
    cout<<"Enter the course : ";
    cin.ignore();
    cin.getline(course,10);
    cout<<"Enter marks in three subjects : ";
    for(int i=0;i<3;i++)
    {
        cin>>marks[i];
    }
}

int Result::total()
{
    int total_marks=0;
    for(int i=0;i<3;i++)
    {
        total_marks+=marks[i];
    }
    return total_marks;
}

int main()
{
    Result R;
    R.get_data();
    R.display();
    return 0;
}