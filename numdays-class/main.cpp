//
// Nicholas Vitanza
// 9/26/25
// NumDays Class Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

class NumDays {
private:
    double hours;

    // Helper to calculate days from hours
    double calculateDays() const {
        return hours / 8.0;
    }

public:
    // Constructor
    NumDays(double h = 0.0) {
        hours = h;
    }

    // Getters
    double getHours() const {
        return hours;
    }

    double getDays() const {
        return calculateDays();
    }

    // Setters
    void setHours(double h) {
        hours = h;
    }

    // Overload + operator
    NumDays operator+(const NumDays& other) const {
        return NumDays(hours + other.hours);
    }

    // Overload - operator
    NumDays operator-(const NumDays& other) const {
        return NumDays(hours - other.hours);
    }

    // Prefix ++
    NumDays& operator++() {
        ++hours;
        return *this;
    }

    // Postfix ++
    NumDays operator++(int) {
        NumDays temp = *this;
        hours++;
        return temp;
    }

    // Prefix --
    NumDays& operator--() {
        --hours;
        return *this;
    }

    // Postfix --
    NumDays operator--(int) {
        NumDays temp = *this;
        hours--;
        return temp;
    }
};

// Demonstration
int main() {
    NumDays work1(12);  // 12 hours = 1.5 days
    NumDays work2(18);  // 18 hours = 2.25 days

    cout << "Work1: " << work1.getHours() << " hours = " << work1.getDays() << " days\n";
    cout << "Work2: " << work2.getHours() << " hours = " << work2.getDays() << " days\n";

    // Addition
    NumDays totalWork = work1 + work2;
    cout << "Total work (work1 + work2): " << totalWork.getHours() << " hours = " << totalWork.getDays() << " days\n";

    // Subtraction
    NumDays diffWork = work2 - work1;
    cout << "Difference (work2 - work1): " << diffWork.getHours() << " hours = " << diffWork.getDays() << " days\n";

    // Prefix increment
    ++work1;
    cout << "After prefix ++work1: " << work1.getHours() << " hours = " << work1.getDays() << " days\n";

    // Postfix increment
    work1++;
    cout << "After postfix work1++: " << work1.getHours() << " hours = " << work1.getDays() << " days\n";

    // Prefix decrement
    --work2;
    cout << "After prefix --work2: " << work2.getHours() << " hours = " << work2.getDays() << " days\n";

    // Postfix decrement
    work2--;
    cout << "After postfix work2--: " << work2.getHours() << " hours = " << work2.getDays() << " days\n";

    return 0;
}