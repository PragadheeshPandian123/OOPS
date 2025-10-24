#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void inputMarks(vector<int> &marks, int n)
{
    int mark;
    cout << "Enter marks of " << n << " students:\n";
    for (int i = 0; i < n; i++)
    {
        cin >> mark;
        marks.push_back(mark);
    }
}
void displayMarks(const vector<int> &marks)
{
    cout << "Marks: ";
    for (auto m : marks)
        cout << m << " ";
    cout << endl;
}
void findHighLow(const vector<int> &marks)
{
    int highest = *max_element(marks.begin(), marks.end());
    int lowest = *min_element(marks.begin(), marks.end());
    cout << "Highest mark: " << highest << endl;
    cout << "Lowest mark: " << lowest << endl;
}
void calculateAverage(const vector<int> &marks)
{
    double sum = 0;
    for (auto m : marks)
        sum += m;
    cout << "Average mark: " << sum / marks.size() << endl;
}
void addMark(vector<int> &marks, int mark)
{
    marks.push_back(mark);
    cout << mark << " added successfully.\n";
}
void removeMark(vector<int> &marks, int mark)
{
    auto it = find(marks.begin(), marks.end(), mark);
    if (it != marks.end())
    {
        marks.erase(it);
        cout << mark << " removed successfully.\n";
    }
    else
    {
        cout << mark << " not found in the list.\n";
    }
}
void sortMarks(vector<int> &marks)
{
    sort(marks.begin(), marks.end());
    cout << "Marks sorted in ascending order.\n";
}
int main()
{
    vector<int> marks;
    int n, choice, mark;
    cout << "Enter number of students: ";
    cin >> n;
    inputMarks(marks, n);
    do
    {
        cout << "\n--- Menu ---\n";
        cout << "1. Display marks\n";
        cout << "2. Find highest and lowest marks\n";
        cout << "3. Calculate average\n";
        cout << "4. Add a mark\n";
        cout << "5. Remove a mark\n";
        cout << "6. Sort marks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            displayMarks(marks);
            break;
        case 2:
            findHighLow(marks);
            break;
        case 3:
            calculateAverage(marks);
            break;
        case 4:
            cout << "Enter mark to add: ";
            cin >> mark;
            addMark(marks, mark);
            break;
        case 5:
            cout << "Enter mark to remove: ";
            cin >> mark;
            removeMark(marks, mark);
            break;
        case 6:
            sortMarks(marks);
            displayMarks(marks);
            break;
        case 0:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);
    return 0;
}