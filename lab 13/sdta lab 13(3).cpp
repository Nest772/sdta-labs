#include <iostream>
#include <string>
#include <map>

using namespace std;


void updateOrAddGrade(map<string, int>& registry, string name, int newGrade) {
    
    registry[name] = newGrade;
    cout << "Processed student: " << name << " with grade " << newGrade << "\n";
}

int main() {
    
    map<string, int> studentGrades = {
        {"Alice", 95},
        {"Bob", 82},
        {"Charlie", 88}
    };

    string inputName;
    int inputGrade;

    cout << "Enter student name: ";
    cin >> inputName;
    cout << "Enter new grade: ";
    cin >> inputGrade;

  
    updateOrAddGrade(studentGrades, inputName, inputGrade);

    
    cout << "\nUpdated Student Registry List:\n";
    for (const auto& student : studentGrades) {
        cout << student.first << ": " << student.second << "\n";
    }

    return 0;
}