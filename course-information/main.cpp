//
// Nicholas Vitanza
// 10/24/25
// Course Information Programming Project
// COSC 2030
//

#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    // Maps for course information
    map<string, string> roomNumber = {
        {"CS101", "3004"},
        {"CS102", "4501"},
        {"CS103", "6755"},
        {"NT110", "1244"},
        {"CM240", "1411"}
    };

    map<string, string> instructor = {
        {"CS101", "Haynes"},
        {"CS102", "Alvarado"},
        {"CS103", "Rich"},
        {"NT110", "Burke"},
        {"CM240", "Lee"}
    };

    map<string, string> meetingTime = {
        {"CS101", "8:00 a.m."},
        {"CS102", "9:00 a.m."},
        {"CS103", "10:00 a.m."},
        {"NT110", "11:00 a.m."},
        {"CM240", "1:00 p.m."}
    };

    string course;
    cout << "Enter a course number (e.g., CS101): ";
    cin >> course;

    // Check if the course exists in the map
    if (roomNumber.find(course) != roomNumber.end()) {
        cout << "\nCourse Information:\n";
        cout << "Course Number: " << course << endl;
        cout << "Room Number: " << roomNumber[course] << endl;
        cout << "Instructor: " << instructor[course] << endl;
        cout << "Meeting Time: " << meetingTime[course] << endl;
    } else {
        cout << "\nError: Course number '" << course << "' not found." << endl;
    }

    return 0;
}