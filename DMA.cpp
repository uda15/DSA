#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

// Base Class: Dynamic Memory Allocation
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() {
        head = NULL;
    }

    // Insert at beginning
    void insert_at_beginning(int data) {
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        cout << "Node inserted at beginning.\n";
    }

    // Display list
    void display() {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "Linked List: ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Search node
    void search(int key) {
        Node* temp = head;
        int position = 1;

        while (temp != NULL) {
            if (temp->data == key) {
                cout << "Node found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        }
        cout << "Node not found.\n";
    }

    // Delete node by value
    void delete_node(int key) {
        if (head == NULL) {
            cout << "List is empty.\n";
            return;
        }

        // If head needs to be deleted
        if (head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Node deleted successfully.\n";
            return;
        }

        Node* curr = head;
        Node* prev = NULL;

        while (curr != NULL && curr->data != key) {
            prev = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Node not found.\n";
            return;
        }

        prev->next = curr->next;
        delete curr;
        cout << "Node deleted successfully.\n";
    }

    // Reverse linked list
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        head = prev;
        cout << "Linked list reversed successfully.\n";
    }
};

int main() {
    LinkedList list;
    int choice, value;

    do {
        cout << "\n----- Linked List Menu -----";
        cout << "\n1. Insert at Beginning";
        cout << "\n2. Display List";
        cout << "\n3. Search Node";
        cout << "\n4. Delete Node";
        cout << "\n5. Reverse List";
        cout << "\n0. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            list.insert_at_beginning(value);
            break;

        case 2:
            list.display();
            break;

        case 3:
            cout << "Enter value to search: ";
            cin >> value;
            list.search(value);
            break;

        case 4:
            cout << "Enter value to delete: ";
            cin >> value;
            list.delete_node(value);
            break;

        case 5:
            list.reverse();
            break;

        case 0:
            cout << "Program exited successfully.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 0);

    return 0;
}
