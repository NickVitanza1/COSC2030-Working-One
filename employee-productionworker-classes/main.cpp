//
// Nicholas Vitanza
// 10/3/25
// Employee and ProductionWorker Classes Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

// Base class
class Employee {
private:
    string name;
    string employeeNumber;
    string hireDate;

public:
    // Constructors
    Employee() : name(""), employeeNumber(""), hireDate("") {}
    Employee(string n, string num, string date) : name(n), employeeNumber(num), hireDate(date) {}

    // Accessors
    string getName() const { return name; }
    string getEmployeeNumber() const { return employeeNumber; }
    string getHireDate() const { return hireDate; }

    // Mutators
    void setName(const string& n) { name = n; }
    void setEmployeeNumber(const string& num) { employeeNumber = num; }
    void setHireDate(const string& date) { hireDate = date; }
};

// Derived class
class ProductionWorker : public Employee {
private:
    int shift;           // 1 for day, 2 for night
    double hourlyPayRate;

public:
    // Constructors
    ProductionWorker() : Employee(), shift(1), hourlyPayRate(0.0) {}
    ProductionWorker(string n, string num, string date, int s, double rate)
        : Employee(n, num, date), shift(s), hourlyPayRate(rate) {}

    // Accessors
    int getShift() const { return shift; }
    double getHourlyPayRate() const { return hourlyPayRate; }

    // Mutators
    void setShift(int s) { shift = s; }
    void setHourlyPayRate(double rate) { hourlyPayRate = rate; }

    // Helper to get shift as string
    string getShiftName() const {
        return (shift == 1) ? "Day" : (shift == 2) ? "Night" : "Invalid";
    }
};

// Demonstration
int main() {
    // Create a ProductionWorker object
    ProductionWorker worker("Nick Vitanza", "39563", "2025-06-21", 2, 25.50);

    // Display employee info
    cout << "Employee Information:\n";
    cout << "Name: " << worker.getName() << endl;
    cout << "Employee Number: " << worker.getEmployeeNumber() << endl;
    cout << "Hire Date: " << worker.getHireDate() << endl;
    cout << "Shift: " << worker.getShiftName() << " (" << worker.getShift() << ")" << endl;
    cout << "Hourly Pay Rate: $" << worker.getHourlyPayRate() << endl;

    return 0;
}