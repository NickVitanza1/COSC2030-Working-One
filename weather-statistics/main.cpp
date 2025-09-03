//
// Nicholas Vitanza
// 9/3/25
// Weather Statistics Programming Project
// COSC 2030
//

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Constant for the number of months
const int NUM_MONTHS = 12;
const string MONTH_NAMES[NUM_MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Structure to store weather data
struct WeatherData {
    double totalRainfall;
    double highTemp;
    double lowTemp;
    double avgTemp;
};

// Function to validate temperature input
double getValidatedTemperature(const string& prompt) {
    double temp;
    while (true) {
        cout << prompt;
        cin >> temp;
        if (temp >= -100 && temp <= 140)
            return temp;
        else
            cout << "Invalid temperature. Must be between -100 and 140°F.\n";
    }
}

// Function to input data for one month
void inputWeatherData(WeatherData& data, const string& month) {
    cout << "\nEnter data for " << month << ":\n";

    cout << "Total Rainfall (in inches): ";
    cin >> data.totalRainfall;

    data.highTemp = getValidatedTemperature("High Temperature (°F): ");
    data.lowTemp = getValidatedTemperature("Low Temperature (°F): ");

    // Calculate average temperature
    data.avgTemp = (data.highTemp + data.lowTemp) / 2.0;
}

// Function to display results
void displayResults(WeatherData yearData[]) {
    double totalRainfall = 0, avgMonthlyRainfall;
    double totalAvgTemp = 0, avgOfAvgTemps;
    double highestTemp = -101, lowestTemp = 141;
    int highMonthIndex = -1, lowMonthIndex = -1;

    for (int i = 0; i < NUM_MONTHS; ++i) {
        totalRainfall += yearData[i].totalRainfall;
        totalAvgTemp += yearData[i].avgTemp;

        if (yearData[i].highTemp > highestTemp) {
            highestTemp = yearData[i].highTemp;
            highMonthIndex = i;
        }
        if (yearData[i].lowTemp < lowestTemp) {
            lowestTemp = yearData[i].lowTemp;
            lowMonthIndex = i;
        }
    }

    avgMonthlyRainfall = totalRainfall / NUM_MONTHS;
    avgOfAvgTemps = totalAvgTemp / NUM_MONTHS;

    cout << fixed << setprecision(2);
    cout << "\n====== Weather Summary ======\n";
    cout << "Total Rainfall for the year: " << totalRainfall << " inches\n";
    cout << "Average Monthly Rainfall: " << avgMonthlyRainfall << " inches\n";
    cout << "Highest Temperature: " << highestTemp << " °F in " << MONTH_NAMES[highMonthIndex] << "\n";
    cout << "Lowest Temperature: " << lowestTemp << " °F in " << MONTH_NAMES[lowMonthIndex] << "\n";
    cout << "Average of Monthly Average Temperatures: " << avgOfAvgTemps << " °F\n";
}

int main() {
    WeatherData yearWeather[NUM_MONTHS];

    cout << "=== Weather Data Collection ===\n";

    // Collect data for each month
    for (int i = 0; i < NUM_MONTHS; ++i) {
        inputWeatherData(yearWeather[i], MONTH_NAMES[i]);
    }

    // Display results
    displayResults(yearWeather);

    return 0;
}