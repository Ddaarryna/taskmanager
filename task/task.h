#pragma once
#include <string>

class Task {
private:
    std::string description;
    int priority;

public:
    Task();
    Task(const std::string& desc, int prio);
    std::string getDescription() const;
    int getPriority() const;
};

class TaskManager {
private:
    Task* tasks;
    int capacity;
    int size;

    void expand();

public:
    TaskManager();
    ~TaskManager();
    void addTask(const std::string& desc, int prio);
    void completeTask();
    void showTasks() const;
};

