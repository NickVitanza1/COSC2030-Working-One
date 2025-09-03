//
// Nicholas Vitanza
// 9/3/25
// Movie Data Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

// Define the structure
struct MovieData {
    string title;
    string director;
    int yearReleased;
    int runningTime; // in minutes
};

// Function to display movie data
void displayMovie(const MovieData& movie) {
    cout << "-------------------------------" << endl;
    cout << "Title:        " << movie.title << endl;
    cout << "Director:     " << movie.director << endl;
    cout << "Year Released:" << movie.yearReleased << endl;
    cout << "Running Time: " << movie.runningTime << " minutes" << endl;
    cout << "-------------------------------" << endl;
}

int main() {
    // Create first movie
    MovieData movie1 = {
        "Godzilla Minus One",
        "Takashi Yamazaki",
        2023,
        125
    };

    // Create second movie
    MovieData movie2 = {
        "Inception",
        "Christopher Nolan",
        2010,
        148
    };

    // Display movies
    displayMovie(movie1);
    displayMovie(movie2);

    return 0;
}