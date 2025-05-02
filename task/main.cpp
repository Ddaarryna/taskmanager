#include "task.h"
#include <iostream>
#include <string>
using namespace std;

int main() {
    TaskManager manager;
    int choice;

    while (true) {
        cout << "\n--- Task Manager ---\n";
        cout << "1. Add a task\n";
        cout << "2. Complete a task\n";
        cout << "3. Show task list\n";
        cout << "4. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            string desc;
            int priority;

            cout << "Enter task description: ";
            getline(cin, desc);
            cout << "Enter priority (1-10): ";
            cin >> priority;
            cin.ignore();

            manager.addTask(desc, priority);
        }
        else if (choice == 2) {
            manager.completeTask();
        }
        else if (choice == 3) {
            manager.showTasks();
        }
        else if (choice == 4) {
            cout << "Goodbye!\n";
            break;
        }
        else {
            cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
