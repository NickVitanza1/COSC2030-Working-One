//
// Nichola Vitanza
// 8/28/25
// Backward String Programming Project
// COSC 2030
//

#include <iostream>
#include <cstring>   // for strlen
using namespace std;

// Function that prints a C-string backward
void displayBackward(const char *str) {
    int length = strlen(str); // find string length
    for (int i = length - 1; i >= 0; i--) {
        cout << str[i];
    }
    cout << endl;
}

int main() {
    const int SIZE = 100;
    char input[SIZE];

    cout << "Enter a string: ";
    cin.getline(input, SIZE); // read user input

    cout << "String backward: ";
    displayBackward(input);

    return 0;
}