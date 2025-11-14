//
// Nicholas Vitanza
// 11/14/25
// Recursive Multiplication Programming Project
// COSC 2030
//

int multiply(int x, int y) {
    // Base case: anything times 0 is 0
    if (y == 0)
        return 0;

    // If y is positive, add x recursively
    if (y > 0)
        return x + multiply(x, y - 1);

    // If y is negative, convert to positive multiplication
    // and then negate the result
    return -multiply(x, -y);
}