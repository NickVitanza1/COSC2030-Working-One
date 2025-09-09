//
// Nicholas Vitanza
// 9/8/25
// File Encryption Programming Project
// COSC 2030
//

// File Encryption Filter
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
    ifstream inputFile;
    ofstream outputFile;

    string inFileName;
    string outFileName;
    char data;

    // Get the input file name
    cout << "Enter the input file name: ";
    getline(cin, inFileName);

    // Get the output file name
    cout << "Enter the output file name: ";
    getline(cin, outFileName);

    // Open the files
    inputFile.open(inFileName.c_str());
    outputFile.open(inFileName.c_str());

    // Read the first character from the input file
    inputFile.get(data);

    // Read the contents of the input file, one character at a time,
    // encrypt it, and store it in the output file
    while (inputFile)
    {
        // Encrypt the character by adding 10 to it
        data += 10;

        // Write the character to output file
        outputFile.put(data);

        // Get the character from the input file
        inputFile.get(data);
    }

    cout << "The file has been encrypted.\n";

    // Close both files
    inputFile.close();
    outputFile.close();

    return 0;
}