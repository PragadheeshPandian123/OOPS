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
        get_rno();
        get_sport_score();
        cout << "Enter marks in 3 subjects: ";
        for (int i = 0; i < 3; i++) cin >> marks[i];
    }
    int total() {
        int sum = sport_score;
        for (int i = 0; i < 3; i++) sum += marks[i];
        return sum;
    }
    void display() {
        show_rno();
        show_sport_score();
        cout << "Total Score (Academic + Sports): " << total() << endl;
    }
};

int main()
{
    Result R;
    R.get_data();  
    R.display();
    return 0;
}