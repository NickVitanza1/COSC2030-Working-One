//
// Nicholas Vitanza
// 9/26/25
// Numbers Class Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

class Numbers {
private:
    int number;

    static string lessThan20[20];
    static string tens[10];
    static string hundred;
    static string thousand;

public:
    // Constructor
    Numbers(int n) {
        if (n < 0 || n > 9999) {
            cout << "Number out of range (0-9999)." << endl;
            exit(1);
        }
        number = n;
    }

    // Function to print number in words
    void print() const {
        if (number == 0) {
            cout << lessThan20[0] << endl;
            return;
        }

        int n = number;
        string result = "";

        // Thousands
        if (n >= 1000) {
            result += lessThan20[n / 1000] + " " + thousand;
            n %= 1000;
            if (n) result += " ";
        }

        // Hundreds
        if (n >= 100) {
            result += lessThan20[n / 100] + " " + hundred;
            n %= 100;
            if (n) result += " ";
        }

        // Less than 100
        if (n >= 20) {
            result += tens[n / 10];
            n %= 10;
            if (n) result += " " + lessThan20[n];
        } else if (n > 0) {
            result += lessThan20[n];
        }

        cout << result << endl;
    }
};

// Initialize static members
string Numbers::lessThan20[20] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
    "sixteen", "seventeen", "eighteen", "nineteen"
};

string Numbers::tens[10] = {
    "", "", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"
};

string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

// Main program
int main() {
    int input;

    cout << "Enter a number between 0 and 9999: ";
    cin >> input;

    if (cin.fail() || input < 0 || input > 9999) {
        cout << "Invalid input. Please enter a number between 0 and 9999." << endl;
        return 1;
    }

    Numbers num(input);
    cout << "In words: ";
    num.print();

    return 0;
}