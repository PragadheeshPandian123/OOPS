#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
void addTaskEnd(list<string> &tasks, const string &task)
{
    tasks.push_back(task);
    cout << "Task added at end.\n";
}
void addTaskBegin(list<string> &tasks, const string &task)
{
    tasks.push_front(task);
    cout << "Task added at beginning.\n";
}
void displayTasks(const list<string> &tasks)
{
    cout << "Tasks:\n";
    for (const auto &task : tasks)
        cout << "- " << task << endl;
}
void removeTask(list<string> &tasks, const string &task)
{
    auto it = find(tasks.begin(), tasks.end(), task);
    if (it != tasks.end())
    {
        tasks.erase(it);
        cout << "Task removed.\n";
    }
    else
    {
        cout << "Task not found.\n";
    }
}
void sortTasks(list<string> &tasks)
{
    tasks.sort();
    cout << "Tasks sorted alphabetically.\n";
}
int main()
{
    list<string> tasks;
    int choice;
    string task;
    do
    {
        cout << "\n--- Task Manager ---\n";
        cout << "1. Add task at end\n";
        cout << "2. Add task at beginning\n";
        cout << "3. Display tasks\n";
        cout << "4. Remove task\n";
        cout << "5. Sort tasks\n";
        cout << "6. Clear all tasks\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();\
        switch (choice)
        {
        case 1:
            cout << "Enter task: ";
            getline(cin, task);
            addTaskEnd(tasks, task);
            break;
        case 2:
            cout << "Enter task: ";
            getline(cin, task);
            addTaskBegin(tasks, task);
            break;
        case 3:
            displayTasks(tasks);
            break;
        case 4:
            cout << "Enter task to remove: ";
            getline(cin, task);
            removeTask(tasks, task);
            break;
        case 5:
            sortTasks(tasks);
            displayTasks(tasks);
            break;
        case 6:
            tasks.clear();
            cout << "All tasks cleared.\n";
            break;
        case 0:
            cout << "Exiting Task Manager.\n";
            break;
        default:
            cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}