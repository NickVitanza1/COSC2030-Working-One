//
// Nicholas Vitanza
// 11/7/25
// Inventory Bin Stack Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// -------------------------------
// Inventory Class
// -------------------------------
class Inventory {
private:
    int serialNum;
    string manufactDate;
    int lotNum;

public:
    // Constructors
    Inventory() : serialNum(0), manufactDate(""), lotNum(0) {}
    Inventory(int s, string d, int l) : serialNum(s), manufactDate(d), lotNum(l) {}

    // Setters
    void setSerialNum(int s) { serialNum = s; }
    void setManufactDate(string d) { manufactDate = d; }
    void setLotNum(int l) { lotNum = l; }

    // Getters
    int getSerialNum() const { return serialNum; }
    string getManufactDate() const { return manufactDate; }
    int getLotNum() const { return lotNum; }

    // Display function
    void display() const {
        cout << "Serial Number: " << serialNum << endl;
        cout << "Manufacture Date: " << manufactDate << endl;
        cout << "Lot Number: " << lotNum << endl;
    }
};

// -------------------------------
// Stack Class (holds Inventory objects)
// -------------------------------
class InventoryStack {
private:
    vector<Inventory> stack;

public:
    // Push an Inventory object onto the stack
    void push(const Inventory& item) {
        stack.push_back(item);
    }

    // Pop the top Inventory object from the stack
    bool pop(Inventory& item) {
        if (stack.empty()) {
            cout << "Stack is empty! No item to remove.\n";
            return false;
        }
        item = stack.back();
        stack.pop_back();
        return true;
    }

    // Check if stack is empty
    bool isEmpty() const {
        return stack.empty();
    }

    // Display all items left on the stack
    void displayAll() const {
        if (stack.empty()) {
            cout << "No items remaining in inventory.\n";
            return;
        }
        cout << "\nRemaining items in inventory:\n";
        cout << "--------------------------------\n";
        for (size_t i = 0; i < stack.size(); ++i) {
            cout << "Item " << i + 1 << ":\n";
            stack[i].display();
            cout << "--------------------------------\n";
        }
    }
};

// -------------------------------
// Main Program
// -------------------------------
int main() {
    InventoryStack inventoryStack;
    char choice;

    cout << "===== INVENTORY MANAGEMENT SYSTEM =====\n";

    do {
        cout << "\nChoose an action:\n";
        cout << "A - Add a part to inventory\n";
        cout << "R - Remove (pop) a part from inventory\n";
        cout << "Q - Quit program\n";
        cout << "Enter choice: ";
        cin >> choice;
        choice = toupper(choice);
        cin.ignore();  // clear newline

        if (choice == 'A') {
            int serial, lot;
            string date;

            cout << "Enter serial number: ";
            cin >> serial;
            cin.ignore();

            cout << "Enter manufacture date: ";
            getline(cin, date);

            cout << "Enter lot number: ";
            cin >> lot;

            Inventory item(serial, date, lot);
            inventoryStack.push(item);

            cout << "Part added to inventory.\n";
        }
        else if (choice == 'R') {
            Inventory removedItem;
            if (inventoryStack.pop(removedItem)) {
                cout << "\nRemoved part details:\n";
                cout << "--------------------------------\n";
                removedItem.display();
                cout << "--------------------------------\n";
            }
        }
        else if (choice == 'Q') {
            cout << "\nExiting program...\n";
        }
        else {
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 'Q');

    // Display all items left in inventory before exiting
    inventoryStack.displayAll();

    cout << "Thank you for using the Inventory Management System.\n";
    return 0;
}