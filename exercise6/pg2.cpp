#include <iostream>
using namespace std;
class Student
{
private:
    int roll_no;
    char name[20];

public:
    void get_data()
    {
        cout << "\nEnter the roll number: ";
        cin >> roll_no;
        cout << "Enter the name: ";
        cin.ignore();
        cin.getline(name, 20);
    }
    void show_data()
    {
        cout << "\nROLL NUMBER: " << roll_no;
        cout << "\nNAME: " << name;
    }
};
template <class Type>
class Marks : public Student
{
private:
    Type marks[2];

public:
    void get_details()
    {
        get_data();
        cout << "Enter the marks in two subjects: ";
        cin >> marks[0] >> marks[1];
    }
    void show_details()
    {
        show_data();
        cout << "\nTOTAL: " << marks[0] + marks[1] << endl;
    }
};
int main()
{
    Marks<float> M;
    M.get_details();
    M.show_details();
    return 0;
}