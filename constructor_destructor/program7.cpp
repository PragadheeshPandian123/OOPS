#include <iostream>
using namespace std;

class StudentMarks {
private:
    int** marks;
    int num_students;
    int num_subjects;

public:
    StudentMarks(int students, int subjects) {
        num_students = students;
        num_subjects = subjects;

        marks = new int*[num_students];
        for (int i = 0; i < num_students; ++i)
            marks[i] = new int[num_subjects];

        cout << "Enter marks for " << num_students << " students and " << num_subjects << " subjects:\n";
        for (int i = 0; i < num_students; ++i) {
            cout << "Student " << i + 1 << ":\n";
            for (int j = 0; j < num_subjects; ++j) {
                cout << "  Subject " << j + 1 << ": ";
                cin >> marks[i][j];
            }
        }
    }

    void displayMarks() const {
        cout << "\nMarks Table:\n";
        for (int i = 0; i < num_students; ++i) {
            cout << "Student " << i + 1 << ": ";
            for (int j = 0; j < num_subjects; ++j) {
                cout << marks[i][j] << " ";
            }
            cout << endl;
        }
    }

    ~StudentMarks() {
        for (int i = 0; i < num_students; ++i)
            delete[] marks[i];
        delete[] marks;
    }
};

int main() {
    int students, subjects;
    cout << "Enter number of students: ";
    cin >> students;
    cout << "Enter number of subjects: ";
    cin >> subjects;

    StudentMarks sm(students, subjects);  
    sm.displayMarks();                    

    return 0;
}
