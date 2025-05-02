#include "task.h"
#include <iostream>
#include <algorithm>
using namespace std;

// --- Task implementation ---
Task::Task() {
    description = "";
    priority = 0;
}

Task::Task(const std::string& desc, int prio) {
    description = desc;
    priority = prio;
}

std::string Task::getDescription() const {
    return description;
}

int Task::getPriority() const {
    return priority;
}

// --- TaskManager implementation ---
TaskManager::TaskManager() {
    capacity = 10;
    size = 0;
    tasks = new Task[capacity];
}

TaskManager::~TaskManager() {
    delete[] tasks;
}

void TaskManager::expand() {
    capacity *= 2;
    Task* newTasks = new Task[capacity];
    for (int i = 0; i < size; ++i) {
        newTasks[i] = tasks[i];
    }
    delete[] tasks;
    tasks = newTasks;
}

void TaskManager::addTask(const std::string& desc, int prio) {
    if (size >= capacity) {
        expand();
    }
    tasks[size++] = Task(desc, prio);
}

void TaskManager::completeTask() {
    if (size == 0) {
        cout << "No tasks to complete.\n";
        return;
    }

    sort(tasks, tasks + size, [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
        });

    cout << "Select a task to complete:\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << tasks[i].getDescription()
            << " (priority: " << tasks[i].getPriority() << ")\n";
    }

    int taskIndex;
    cout << "Enter the task number to complete: ";
    cin >> taskIndex;
    cin.ignore();

    if (taskIndex < 1 || taskIndex > size) {
        cout << "Invalid task number.\n";
        return;
    }

    cout << "Completed task: " << tasks[taskIndex - 1].getDescription() << "\n";

    for (int i = taskIndex - 1; i < size - 1; ++i) {
        tasks[i] = tasks[i + 1];
    }

    --size;
}

void TaskManager::showTasks() const {
    if (size == 0) {
        cout << "Task list is empty.\n";
        return;
    }

    Task* sortedTasks = new Task[size];
    for (int i = 0; i < size; ++i) {
        sortedTasks[i] = tasks[i];
    }

    sort(sortedTasks, sortedTasks + size, [](const Task& a, const Task& b) {
        return a.getPriority() < b.getPriority();
        });

    cout << "Current tasks:\n";
    for (int i = 0; i < size; ++i) {
        cout << i + 1 << ". " << sortedTasks[i].getDescription()
            << " (priority: " << sortedTasks[i].getPriority() << ")\n";
    }

    delete[] sortedTasks;
}
