#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int score;

public:

    void input(const string& studentName, int studentScore);
    void input(const string& studentName);

    void display() const;
};



inline void Student::input(const string& studentName, int studentScore) {
    name = studentName;
    score = studentScore;
}

inline void Student::input(const string& studentName) {
    name = studentName;
    score = 0;  
}

inline void Student::display() const {
    cout << "Student: " << name << ", Score: " << score << endl;
}

int main() {
    Student s1, s2;
    
    s1.input("Alice", 95);
    s2.input("Bob");  

    s1.display();
    s2.display();

    return 0;
}
