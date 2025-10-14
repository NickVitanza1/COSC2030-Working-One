//
// Nicholas Vitanza
// 10/14/25
// TestScores Class Programming Project
// COSC 2030
//

#include <iostream>
#include <vector>
#include <stdexcept>
#include <numeric>  // For std::accumulate

class TestScores {
private:
    std::vector<double> scores;

public:
    // Constructor with validation
    TestScores(const std::vector<double>& inputScores) {
        for (double score : inputScores) {
            if (score < 0.0 || score > 100.0) {
                throw std::invalid_argument("Invalid score: " + std::to_string(score) + ". Must be between 0 and 100.");
            }
        }
        scores = inputScores;
    }

    // Function to calculate average
    double getAverage() const {
        if (scores.empty()) {
            return 0.0;  // Handle empty vector gracefully
        }

        double total = std::accumulate(scores.begin(), scores.end(), 0.0);
        return total / scores.size();
    }
};

// Demonstration in main
int main() {
    try {
        std::vector<double> myScores = {88.5, 92.0, 76.5, 100.0};  // Change to test
        TestScores test(myScores);
        std::cout << "Average score: " << test.getAverage() << std::endl;
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }

    // Uncomment this block to see exception handling in action:
    /*
    try {
        std::vector<double> badScores = {90.0, -10.0, 85.5};  // -10.0 is invalid
        TestScores test(badScores);  // This will throw
        std::cout << "Average score: " << test.getAverage() << std::endl;
    }
    catch (const std::invalid_argument& ex) {
        std::cerr << "Error: " << ex.what() << std::endl;
    }
    */

    return 0;
}