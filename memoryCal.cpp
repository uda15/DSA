#include <iostream>
#include <vector>
using namespace std;

// Class Template
template <class T>
class MemoryCalculate {
    T id;
    string name;

public:
    // Constructor
    MemoryCalculate(T i, string n) {
        id = i;
        name = n;
    }

    // Getter for ID
    T getId() {
        return id;
    }

    // Display method
    void display() {
        cout << "ID: " << id << " | Name: " << name << endl;
    }
};

int main() {
    vector<MemoryCalculate<int>> students;
    int choice;

    do {
        cout << "\n----- Student Management Menu -----\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Remove Student by ID\n";
        cout << "4. Search Student by ID\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id;
            string name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;

            students.push_back(MemoryCalculate<int>(id, name));
            cout << "Student Added Successfully\n";
        }

        else if (choice == 2) {
            for (auto &s : students) {
                s.display();
            }
        }

        else if (choice == 3) {
            int id;
            cout << "Enter ID to remove: ";
            cin >> id;

            for (auto it = students.begin(); it != students.end(); it++) {
                if (it->getId() == id) {
                    students.erase(it);
                    cout << "Student Removed\n";
                    break;
                }
            }
        }

        else if (choice == 4) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            bool found = false;

            for (auto &s : students) {
                if (s.getId() == id) {
                    s.display();
                    found = true;
                    break;
                }
            }

            if (!found)
                cout << "Student Not Found\n";
        }

    } while (choice != 5);

    return 0;
}