# include <iostream>
using namespace std;


struct student {
    int roll_no;
    char name[50];
    float math, physics, chemistry;
    float total;
    int rank;
};

void computeRanks(struct student s[], int n) {
    int i, j;
    struct student temp;

    for (i = 0; i < n; i++) {
        s[i].total = s[i].math + s[i].physics + s[i].chemistry;
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].total < s[j + 1].total) {
                temp = s[j];
                s[j] = s[j + 1];
                s[j + 1] = temp;
            }
        }
    }

    for (i = 0; i < n; i++) {
        if (i > 0 && s[i].total == s[i - 1].total) {
            s[i].rank = s[i - 1].rank; 
        } else {
            s[i].rank = i + 1;
        }
    }
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;

    student Students[n];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent " << i + 1 << ":\n";
        cout << "Roll Number: ";
        cin >> Students[i].roll_no;

        cin.ignore(); 
        cout << "Name: ";
        cin.getline(Students[i].name,50);

        cout << "Mathematics mark: ";
        cin >> Students[i].math;

        cout << "Physics mark: ";
        cin >> Students[i].physics;

        cout << "Chemistry mark: ";
        cin >> Students[i].chemistry;
    }

    computeRanks(Students,n);

    cout << "\n=== Student Results ===\n";
    for (size_t i = 0; i < n; i++) {
        cout << "\nS.no " << i + 1 << ":\n";
        cout << "Roll number: " << Students[i].roll_no << endl;
        cout << "Name: " << Students[i].name << endl;
        cout << "Total mark: " << Students[i].total << endl;
        cout << "Computed rank: " << Students[i].rank << endl;
    }

    return 0;
}