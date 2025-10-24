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

class Sports {
protected:
    int sport_score;
public:
    void get_sport_score() {
        cout << "Enter sports score: ";
        cin >> sport_score;
    }
    void show_sport_score() {
        cout << "Sports Score: " << sport_score << endl;
    }
};

class Result : public Student, public Sports {
    int marks[3];
public:
    void get_data() {
        get_name();
        get_rno();
        get_sport_score();
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) cin >> marks[i];
    }
    void display() {
        show_name();
        show_rno();
        show_sport_score();
        int total = sport_score;
        for (int i = 0; i < 3; i++) total += marks[i];
        cout << "Total Score: " << total << endl;
    }
};

int main()
{
    Result R;
    R.get_data();
    R.display();
    return 0;
}