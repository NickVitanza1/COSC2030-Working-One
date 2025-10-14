//
// Nicholas Vitanza
// 10/14/25
// Exception Project Programming Project
// COSC 2030
//

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

// Custom Exceptions
class InvalidEmployeeNumber : public runtime_error {
public:
    InvalidEmployeeNumber(const string& message) : runtime_error(message) {}
};

class InvalidShift : public runtime_error {
public:
    InvalidShift(const string& message) : runtime_error(message) {}
};

class InvalidPayRate : public runtime_error {
public:
    InvalidPayRate(const string& message) : runtime_error(message) {}
};

// Employee Class
class Employee {
protected:
    string name;
    int employeeNumber;

public:
    Employee(string empName, int empNumber) {
        name = empName;
        setEmployeeNumber(empNumber);
    }

    void setEmployeeNumber(int empNumber) {
        if (empNumber < 0 || empNumber > 9999) {
            throw InvalidEmployeeNumber("Employee number must be between 0 and 9999.");
        }
        employeeNumber = empNumber;
    }

    string getName() const {
        return name;
    }

    int getEmployeeNumber() const {
        return employeeNumber;
    }
};

// ProductionWorker Class
class ProductionWorker : public Employee {
private:
    int shift; // 1 = day, 2 = night
    double payRate;

public:
    ProductionWorker(string empName, int empNumber, int empShift, double rate)
        : Employee(empName, empNumber)
    {
        setShift(empShift);
        setPayRate(rate);
    }

    void setShift(int empShift) {
        if (empShift != 1 && empShift != 2) {
            throw InvalidShift("Shift must be 1 (Day) or 2 (Night).");
        }
        shift = empShift;
    }

    void setPayRate(double rate) {
        if (rate < 0) {
            throw InvalidPayRate("Pay rate must be non-negative.");
        }
        payRate = rate;
    }

    void display() const {
        cout << "Name: " << name << endl;
        cout << "Employee Number: " << employeeNumber << endl;
        cout << "Shift: " << (shift == 1 ? "Day" : "Night") << endl;
        cout << "Pay Rate: $" << payRate << endl;
    }
};

// Driver Program
int main() {
    try {
        Employee emp("Alice", -5);
    } catch (const InvalidEmployeeNumber& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    try {
        ProductionWorker worker1("Bob", 1234, 3, 20.0);
    } catch (const InvalidShift& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    try {
        ProductionWorker worker2("Charlie", 2345, 1, -15.0);
    } catch (const InvalidPayRate& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    try {
        ProductionWorker worker3("Dana", 3456, 2, 25.0);
        cout << "\nValid Worker Created:\n";
        worker3.display();
    } catch (const exception& e) {
        cout << "Unexpected exception: " << e.what() << endl;
    }

    return 0;
}