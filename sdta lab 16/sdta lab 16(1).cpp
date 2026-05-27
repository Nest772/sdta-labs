#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Student {
    string lastName;
    int examGrades[3];
    double averageGrade;
};

int main() {
    cout << "===== STUDENT SEARCH SUBSYSTEM =====\n";
    int n;
    cout << "Enter the number of students (n): ";
    cin >> n;

    vector<Student> students(n);
    double maxAverage = -1.0;


    for (int i = 0; i < n; i++) {
        cout << "\n--- Student #" << i + 1 << " ---\n";
        cout << "Last name: ";
        cin >> students[i].lastName;
        
        int sum = 0;
        cout << "Enter grades for 3 exams: ";
        for (int j = 0; j < 3; j++) {
            cin >> students[i].examGrades[j];
            sum += students[i].examGrades[j];
        }
        students[i].averageGrade = sum / 3.0;
        
        if (students[i].averageGrade > maxAverage) {
            maxAverage = students[i].averageGrade;
        }
    }


    cout << "\n-> [Linear Search Results]:\n";
    cout << "Highest calculated average score: " << maxAverage << "\n";
    int maxCount = 0;
    for (int i = 0; i < n; i++) {
        if (students[i].averageGrade == maxAverage) {
            cout << "   Index position in array [" << i << "]: " << students[i].lastName << "\n";
            maxCount++;
        }
    }
    cout << "Total count of students with maximum average: " << maxCount << "\n";

    
    sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.averageGrade < b.averageGrade;
    });

    cout << "\n-> Binary Search Mode:\n";
    double targetAverage;
    cout << "Enter an exact average grade to search for: ";
    cin >> targetAverage;

    int low = 0, high = n - 1;
    bool found = false;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        
        if (abs(students[mid].averageGrade - targetAverage) < 0.001) { 
            cout << "   Student found. Name: " << students[mid].lastName 
                 << " | Average: " << students[mid].averageGrade << "\n";
            found = true;
            break; 
        }
        else if (students[mid].averageGrade < targetAverage) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    if (!found) {
        cout << "   No student with an average grade of " << targetAverage << " exists in the system.\n";
    }

    return 0;
}