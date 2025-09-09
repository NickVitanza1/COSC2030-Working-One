//
// Nicholas Vitanza
// 9/8/25
// Inventory Program Programming Project
// COSC 2030
//

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstring> // for strlen
using namespace std;

// Structure for inventory record
struct Inventory {
    char description[50];
    int quantity;
    double wholesale;
    double retail;
    char date[11]; // format: YYYY-MM-DD
};

// Function prototypes
void addRecord(fstream &file);
void displayRecord(fstream &file);
void changeRecord(fstream &file);

int main() {
    fstream file("inventory.dat", ios::in | ios::out | ios::binary);

    // If file doesn’t exist, create it
    if (!file) {
        file.open("inventory.dat", ios::out | ios::binary);
        file.close();
        file.open("inventory.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    do {
        cout << "\n=== Inventory Menu ===\n";
        cout << "1. Add new record\n";
        cout << "2. Display a record\n";
        cout << "3. Change a record\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: addRecord(file); break;
        case 2: displayRecord(file); break;
        case 3: changeRecord(file); break;
        case 4: cout << "Exiting...\n"; break;
        default: cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    file.close();
    return 0;
}

// Add new record
void addRecord(fstream &file) {
    Inventory item;
    cout << "Enter item description: ";
    cin.getline(item.description, 50);

    do {
        cout << "Enter quantity on hand: ";
        cin >> item.quantity;
    } while (item.quantity < 0);

    do {
        cout << "Enter wholesale cost: ";
        cin >> item.wholesale;
    } while (item.wholesale < 0);

    do {
        cout << "Enter retail cost: ";
        cin >> item.retail;
    } while (item.retail < 0);

    cin.ignore();
    do {
        cout << "Enter date added (YYYY-MM-DD): ";
        cin.getline(item.date, 11);
    } while (strlen(item.date) != 10); // simple validation

    file.clear();
    file.seekp(0, ios::end); // move to end of file
    file.write(reinterpret_cast<char *>(&item), sizeof(item));

    cout << "Record added successfully.\n";
}

// Display record
void displayRecord(fstream &file) {
    int recordNum;
    Inventory item;

    cout << "Enter record number to display (starting at 0): ";
    cin >> recordNum;

    file.clear();
    file.seekg(recordNum * sizeof(item), ios::beg);
    file.read(reinterpret_cast<char *>(&item), sizeof(item));

    if (!file) {
        cout << "Error: Invalid record number.\n";
        file.clear();
        return;
    }

    cout << "\nRecord #" << recordNum << ":\n";
    cout << "Description: " << item.description << endl;
    cout << "Quantity: " << item.quantity << endl;
    cout << "Wholesale: $" << fixed << setprecision(2) << item.wholesale << endl;
    cout << "Retail: $" << item.retail << endl;
    cout << "Date Added: " << item.date << endl;
}

// Change record
void changeRecord(fstream &file) {
    int recordNum;
    Inventory item;

    cout << "Enter record number to change (starting at 0): ";
    cin >> recordNum;
    cin.ignore();

    file.clear();
    file.seekg(recordNum * sizeof(item), ios::beg);
    file.read(reinterpret_cast<char *>(&item), sizeof(item));

    if (!file) {
        cout << "Error: Invalid record number.\n";
        file.clear();
        return;
    }

    cout << "\nEditing Record #" << recordNum << ":\n";
    cout << "Current Description: " << item.description << endl;
    cout << "Enter new description: ";
    cin.getline(item.description, 50);

    do {
        cout << "Enter new quantity: ";
        cin >> item.quantity;
    } while (item.quantity < 0);

    do {
        cout << "Enter new wholesale cost: ";
        cin >> item.wholesale;
    } while (item.wholesale < 0);

    do {
        cout << "Enter new retail cost: ";
        cin >> item.retail;
    } while (item.retail < 0);

    cin.ignore();
    do {
        cout << "Enter new date (YYYY-MM-DD): ";
        cin.getline(item.date, 11);
    } while (strlen(item.date) != 10);

    file.clear();
    file.seekp(recordNum * sizeof(item), ios::beg);
    file.write(reinterpret_cast<char *>(&item), sizeof(item));

    cout << "Record updated successfully.\n";
}