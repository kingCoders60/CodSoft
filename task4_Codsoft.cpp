#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    Task(const string& description) : description(description) {}

    const string& getDescription() const {
        return description;
    }

private:
    string description;
};

class ToDoList {
public:
    void addTask(const string& description) {
        Task task(description);
        tasks.push_back(task);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() const {
        cout << "Tasks in the to-do list:" << endl;
        if (tasks.empty()) {
            cout << "No tasks found." << endl;
        } else {
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << i + 1 << ". " << tasks[i].getDescription() << endl;
            }
        }
        cout << endl;
    }

    void deleteTask(int index) {
        if (index >= 1 && index <= static_cast<int>(tasks.size())) {
            cout << "Task deleted: " << tasks[index - 1].getDescription() << endl;
            tasks.erase(tasks.begin() + index - 1);
        } else {
            cout << "Invalid task index." << endl;
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    ToDoList toDoList;

    while (true) {
        cout << "Menu:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Delete Task" << endl;
        cout << "4. Exit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to delete: ";
                cin >> index;
                toDoList.deleteTask(index);
                break;
            }
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }

        cout << endl;
    }
}