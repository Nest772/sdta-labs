#include <iostream>
#include <string>

using namespace std;


enum Faculty { IT, ECONOMICS, LAW, MANAGEMENT };


struct Student {
    string lastName;
    int yearOfStudy;
    double averageGrade;
    Faculty facultyType;
};


string facultyToString(Faculty f) {
    switch (f) {
        case IT: return "Information Technology";
        case ECONOMICS: return "Economics";
        case LAW: return "Law";
        case MANAGEMENT: return "Management";
        default: return "Unknown";
    }
}

int main() {
    const int SIZE = 2;
    Student students[SIZE];
    double totalSum = 0;

    for (int i = 0; i < SIZE; i++) {
        cout << "\n--- Enter details for Student #" << i + 1 << " ---\n";
        cout << "Last Name: ";
        cin >> students[i].lastName;
        cout << "Year of study: ";
        cin >> students[i].yearOfStudy;
        cout << "Average Grade: ";
        cin >> students[i].averageGrade;
        
        totalSum += students[i].averageGrade;

        cout << "Select Faculty (0-IT, 1-Economics, 2-Law, 3-Management): ";
        int choice;
        cin >> choice;
        students[i].facultyType = static_cast<Faculty>(choice);
    }

    
    cout << "\nChoose a faculty to filter by (0-IT, 1-Economics, 2-Law, 3-Management): ";
    int filterChoice;
    cin >> filterChoice;
    Faculty targetFaculty = static_cast<Faculty>(filterChoice);

    cout << "\nStudents in " << facultyToString(targetFaculty) << " faculty:\n";
    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (students[i].facultyType == targetFaculty) {
            cout << "- " << students[i].lastName << " (Year: " << students[i].yearOfStudy << ", Grade: " << students[i].averageGrade << ")\n";
            found = true;
        }
    }
    if (!found) {
        cout << "No students found in this faculty.\n";
    }

    
    double overallAverage = totalSum / SIZE;
    cout << "\nOverall average grade of the entire group: " << overallAverage << endl;

    return 0;
}