//
// Nicholas Vitanza
// 9/18/25
// Employee Class Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

// Employee class definition
class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;

public:
    // Default constructor
    Employee() {
        name = "";
        idNumber = 0;
        department = "";
        position = "";
    }

    // Constructor with name and ID only
    Employee(string empName, int empId) {
        name = empName;
        idNumber = empId;
        department = "";
        position = "";
    }

    // Constructor with all parameters
    Employee(string empName, int empId, string dept, string pos) {
        name = empName;
        idNumber = empId;
        department = dept;
        position = pos;
    }

    // Mutator (setter) functions
    void setName(string empName) {
        name = empName;
    }

    void setIdNumber(int empId) {
        idNumber = empId;
    }

    void setDepartment(string dept) {
        department = dept;
    }

    void setPosition(string pos) {
        position = pos;
    }

    // Accessor (getter) functions
    string getName() const {
        return name;
    }

    int getIdNumber() const {
        return idNumber;
    }

    string getDepartment() const {
        return department;
    }

    string getPosition() const {
        return position;
    }
};

// Main function to demonstrate the Employee class
int main() {
    // Creating Employee objects
    Employee emp1("Kynleigh Barney", 47899, "Accounting", "Vice President");
    Employee emp2("Ryan Dworshack", 39119, "IT", "Programmer");
    Employee emp3("Andrew Mejia", 81774, "Manufacturing", "Engineer");

    // Display employee information
    cout << "Employee Information:\n\n";

    Employee employees[] = {emp1, emp2, emp3};

    for (int i = 0; i < 3; i++) {
        cout << "Name: " << employees[i].getName() << endl;
        cout << "ID Number: " << employees[i].getIdNumber() << endl;
        cout << "Department: " << employees[i].getDepartment() << endl;
        cout << "Position: " << employees[i].getPosition() << "\n\n";
    }

    return 0;
}