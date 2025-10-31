//
// Nicholas Vitanza
// 10/31/25
// Your Own Linked List Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

// Linked List class
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        cout << "Linked list destroyed.\n";
    }

    // Append a node at the end
    void append(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert a node at a given position (0-based index)
    void insert(int value, int position) {
        Node* newNode = new Node(value);
        if (position == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < position - 1 && temp; i++) {
            temp = temp->next;
        }

        if (!temp) {
            cout << "Position out of bounds.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete a node with a given value
    void remove(int value) {
        if (!head) return;

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* temp = head;
        while (temp->next && temp->next->data != value) {
            temp = temp->next;
        }

        if (!temp->next) {
            cout << "Value not found.\n";
            return;
        }

        Node* nodeToDelete = temp->next;
        temp->next = temp->next->next;
        delete nodeToDelete;
    }

    // Display the list
    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

// Driver program
int main() {
    LinkedList list;

    cout << "Appending 10, 20, 30...\n";
    list.append(10);
    list.append(20);
    list.append(30);
    list.display();

    cout << "Inserting 15 at position 1...\n";
    list.insert(15, 1);
    list.display();

    cout << "Deleting 20...\n";
    list.remove(20);
    list.display();

    cout << "Inserting 5 at position 0...\n";
    list.insert(5, 0);
    list.display();

    cout << "Deleting 100 (nonexistent)...\n";
    list.remove(100);
    list.display();

    return 0;
}