//
// Nicholas Vitanza
// 9/18/25
// Trivia Game Programming Project
// COSC 2030
//

#include <iostream>
#include <string>
using namespace std;

// Question class definition
class Question {
private:
    string questionText;
    string answer1;
    string answer2;
    string answer3;
    string answer4;
    int correctAnswer; // 1-4

public:
    // Default constructor
    Question() {
        questionText = "";
        answer1 = "";
        answer2 = "";
        answer3 = "";
        answer4 = "";
        correctAnswer = 1;
    }

    // Parameterized constructor
    Question(string q, string a1, string a2, string a3, string a4, int correct) {
        questionText = q;
        answer1 = a1;
        answer2 = a2;
        answer3 = a3;
        answer4 = a4;
        correctAnswer = correct;
    }

    // Accessors
    string getQuestionText() const { return questionText; }
    string getAnswer1() const { return answer1; }
    string getAnswer2() const { return answer2; }
    string getAnswer3() const { return answer3; }
    string getAnswer4() const { return answer4; }
    int getCorrectAnswer() const { return correctAnswer; }

    // Ask the question and check the answer
    bool askQuestion(int playerNumber) const {
        cout << "\nPlayer " << playerNumber << ", here's your question:\n";
        cout << questionText << "\n";
        cout << "1. " << answer1 << "\n";
        cout << "2. " << answer2 << "\n";
        cout << "3. " << answer3 << "\n";
        cout << "4. " << answer4 << "\n";
        cout << "Enter the number of your answer (1-4): ";

        int userAnswer;
        cin >> userAnswer;

        if (userAnswer == correctAnswer) {
            cout << "Correct!\n";
            return true;
        } else {
            cout << "Wrong! The correct answer was: " << correctAnswer << "\n";
            return false;
        }
    }
};

// Function to set up the 10 questions
void setupQuestions(Question questions[]) {
    questions[0] = Question("What is the capital of France?", "London", "Berlin", "Paris", "Rome", 3);
    questions[1] = Question("Which planet is known as the Red Planet?", "Venus", "Mars", "Jupiter", "Saturn", 2);
    questions[2] = Question("What is the largest mammal?", "Elephant", "Blue Whale", "Giraffe", "Hippo", 2);
    questions[3] = Question("Who wrote 'Romeo and Juliet'?", "Mark Twain", "William Shakespeare", "Charles Dickens", "Jane Austen", 2);
    questions[4] = Question("What gas do plants absorb?", "Oxygen", "Nitrogen", "Carbon Dioxide", "Hydrogen", 3);
    questions[5] = Question("What is the square root of 64?", "6", "7", "8", "9", 3);
    questions[6] = Question("Which element has the symbol 'O'?", "Gold", "Oxygen", "Iron", "Hydrogen", 2);
    questions[7] = Question("What is the longest river in the world?", "Amazon", "Mississippi", "Yangtze", "Nile", 4);
    questions[8] = Question("Who painted the Mona Lisa?", "Van Gogh", "Da Vinci", "Picasso", "Rembrandt", 2);
    questions[9] = Question("How many continents are there?", "5", "6", "7", "8", 3);
}

// Main game function
int main() {
    const int TOTAL_QUESTIONS = 10;
    Question questions[TOTAL_QUESTIONS];

    setupQuestions(questions);

    int player1Score = 0;
    int player2Score = 0;

    cout << "Welcome to the Two-Player Trivia Game!\n";

    // First 5 questions for Player 1
    for (int i = 0; i < 5; i++) {
        if (questions[i].askQuestion(1)) {
            player1Score++;
        }
    }

    // Last 5 questions for Player 2
    for (int i = 5; i < 10; i++) {
        if (questions[i].askQuestion(2)) {
            player2Score++;
        }
    }

    // Show final scores
    cout << "\nGame Over!\n";
    cout << "Player 1 Score: " << player1Score << endl;
    cout << "Player 2 Score: " << player2Score << endl;

    // Declare winner
    if (player1Score > player2Score) {
        cout << "Player 1 wins!\n";
    } else if (player2Score > player1Score) {
        cout << "Player 2 wins!\n";
    } else {
        cout << "It's a tie!\n";
    }

    return 0;
}