# include <iostream>
using namespace std;

class Person {
protected:
    string name;
public:
    void get_name() {
        cout << "Enter name: ";
        cin >> name;
    }
    void show_name() {
        cout << "Name: " << name << endl;
    }
};

class Student : public Person {
protected:
    int roll_no;
public:
    void get_rno() {
        cout << "Enter roll no: ";
        cin >> roll_no;
    }
    void show_rno() {
        cout << "Roll Number: " << roll_no << endl;
    }
};

class Result : public Student {
    int marks[3];
public:
    void get_data() {
        get_name();
        get_rno();
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) cin >> marks[i];
    }
    int total() {
        int sum = 0;
        for (int i = 0; i < 3; i++) sum += marks[i];
        return sum;
    }
    void display() {
        show_name();
        show_rno();
        cout << "Total Marks: " << total() << endl;
    }
};

int main()
{
    Result R;
    R.get_data();
    R.display();
    return 0;
}