# include <iostream>
using namespace std;

class Student {
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
        get_rno();
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) cin >> marks[i];
    }
    void display() {
        show_rno();
        int total = 0;
        for (int i = 0; i < 3; i++) total += marks[i];
        cout << "Total Marks: " << total << endl;
    }
};

class Attendance : public Student {
    int days_present;
public:
    void get_attendance() {
        get_rno();
        cout << "Enter days present: ";
        cin >> days_present;
    }
    void show_attendance() {
        show_rno();
        cout << "Days Present: " << days_present << endl;
    }
};


int main()
{
    Result R;
    R.get_data();
    R.display();
    return 0;
}