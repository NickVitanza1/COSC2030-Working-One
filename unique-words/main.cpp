//
// Nicholas Vitanza
// 10/24/25
// Unique Words Programming Project
// COSC 2030
//

#include <iostream>
#include <fstream>
#include <set>
#include <string>

using namespace std;

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    ifstream file(filename);
    if (!file) {
        cerr << "Error: Could not open file '" << filename << "'." << endl;
        return 1;
    }

    set<string> uniqueWords;
    string word;

    // Read each word from the file
    while (file >> word) {
        uniqueWords.insert(word);
    }

    file.close();

    cout << "\nUnique words found in the file:\n" << endl;
    for (const auto& w : uniqueWords) {
        cout << w << endl;
    }

    return 0;
}