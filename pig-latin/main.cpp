//
// Nicholas Vitanza
// 8/28/25
// Pig Latin Programming Project
// COSC 2030
//

#include <iostream>
#include <sstream>   // for istringstream
#include <string>
using namespace std;

// Function to convert a word to Pig Latin
string toPigLatin(const string &word) {
    if (word.length() == 0) return "";

    if (word.length() == 1) {
        // For single-character words like "I"
        return word + "AY";
    }

    // Move the first letter to the end and add "AY"
    string pigLatinWord = word.substr(1) + word[0] + "AY";
    return pigLatinWord;
}

int main() {
    string sentence;

    cout << "Enter a sentence in uppercase: ";
    getline(cin, sentence);

    istringstream iss(sentence);
    string word;

    cout << "Pig Latin: ";
    while (iss >> word) {
        cout << toPigLatin(word) << " ";
    }
    cout << endl;

    return 0;
}
