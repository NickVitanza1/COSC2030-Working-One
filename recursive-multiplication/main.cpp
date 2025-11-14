//
// Nicholas Vitanza
// 11/14/25
// Recursive Multiplication Programming Project
// COSC 2030
//

#include <iostream>
using namespace std;

int multiply(int, int);

int main()
{
    int num1, num2;   // <-- You forgot to declare these

    cout << "Enter 2 numbers and I will multiply them: ";
    cin >> num1 >> num2;

    cout << "Their product is " << multiply(num1, num2) << endl;  // endl, not end1

    return 0;
}

int multiply(int x, int y)
{
    if (x == 0 || y == 0)
        return 0;
    else if (y == 1)
        return x;
    else
        return x + multiply(x, y - 1);
}