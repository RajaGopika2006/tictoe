
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& desc) {
        tasks.emplace_back(desc);
        cout << "Task added: " << desc << endl;
    }

    void viewTasks() {
        cout << "Tasks:\n";
        for (const auto& task : tasks) {
            cout << (task.completed ? "[X] " : "[ ] ") << task.description << endl;
        }
    }

    void markTaskCompleted(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].completed = true;
            cout << "Task marked as completed: " << tasks[index].description << endl;
        } else {
            cout << "Invalid task index.\n";
        }
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
            cout << "Task removed.\n";
        } else {
            cout << "Invalid task index.\n";
        }
    }
};

int main() {
    ToDoList todo;

    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                string desc;
                cout << "Enter task description: ";
                cin.ignore(); // Clear newline from previous input
                getline(cin, desc);
                todo.addTask(desc);
                break;
            }
            case 2:
                todo.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                todo.markTaskCompleted(index);
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                todo.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting. Have a great day!\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}