//
// Nicholas Vitanza
// 11/7/25
// File Compare Programming Project
// COSC 2030
//

#include <iostream>
#include <fstream>
#include <queue>
#include <string>

using namespace std;

int main() {
    string file1Name, file2Name;
    cout << "Enter the first file name: ";
    cin >> file1Name;
    cout << "Enter the second file name: ";
    cin >> file2Name;

    ifstream file1(file1Name);
    ifstream file2(file2Name);

    // Check if files opened successfully
    if (!file1.is_open() || !file2.is_open()) {
        cerr << "Error: Unable to open one or both files." << endl;
        return 1;
    }

    queue<char> q1, q2;
    char ch;

    // Read characters from first file into queue
    while (file1.get(ch)) {
        q1.push(ch);
    }

    // Read characters from second file into queue
    while (file2.get(ch)) {
        q2.push(ch);
    }

    file1.close();
    file2.close();

    bool identical = true;
    int position = 0; // track position of comparison

    // Compare characters from both queues
    while (!q1.empty() && !q2.empty()) {
        position++;
        if (q1.front() != q2.front()) {
            cout << "Files are NOT identical." << endl;
            cout << "Difference found at character position " << position << "." << endl;
            cout << "File1: '" << q1.front() << "' | File2: '" << q2.front() << "'" << endl;
            identical = false;
            break;
        }
        q1.pop();
        q2.pop();
    }

    // If one queue still has characters left, they're not identical
    if (identical && (q1.empty() != q2.empty())) {
        cout << "Files are NOT identical (different lengths)." << endl;
        identical = false;
    }

    if (identical) {
        cout << "Files are IDENTICAL." << endl;
    }

    return 0;
}