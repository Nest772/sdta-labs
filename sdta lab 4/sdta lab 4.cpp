#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct ABITURIENT {
    string name;
    string gender;
    string spec;
    int exam[3];
};


int countVowels(string s) {
    int count = 0;

    for (char c : s) {
        c = tolower(c);

        if (c == 'a' || c == 'e' || c == 'i' ||
            c == 'o' || c == 'u' || c == 'y') {
            count++;
        }
    }

    return count;
}


double averageMark(ABITURIENT a) {
    return (a.exam[0] + a.exam[1] + a.exam[2]) / 3.0;
}


void showVowels(ABITURIENT arr[], int n) {
    cout << "\nStudents with <= 3 vowels in surname:\n";

    for (int i = 0; i < n; i++) {
        if (countVowels(arr[i].name) <= 3) {
            cout << arr[i].name << " - " << arr[i].spec << endl;
        }
    }
}


void showBelowPassing(ABITURIENT arr[], int n, double passing) {
    bool found = false;

    cout << "\nStudents below passing mark:\n";

    for (int i = 0; i < n; i++) {
        if (averageMark(arr[i]) < passing) {
            cout << arr[i].name << " - " << arr[i].spec << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No such students.\n";
    }
}


void sortStudents(ABITURIENT arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].name > arr[j].name) {
                swap(arr[i], arr[j]);
            }
        }
    }
}


void deleteAverageFive(ABITURIENT arr[], int &n) {
    for (int i = 0; i < n; i++) {
        if (averageMark(arr[i]) == 5) {

            for (int j = i; j < n - 1; j++) {
                arr[j] = arr[j + 1];
            }

            n--;
            i--;
        }
    }
}


void printArray(ABITURIENT arr[], int n) {
    cout << "\nStudents list:\n";

    for (int i = 0; i < n; i++) {
        cout << "\nName: " << arr[i].name << endl;
        cout << "Gender: " << arr[i].gender << endl;
        cout << "Speciality: " << arr[i].spec << endl;
        cout << "Marks: ";

        for (int j = 0; j < 3; j++) {
            cout << arr[i].exam[j] << " ";
        }

        cout << "\nAverage: " << averageMark(arr[i]) << endl;
    }
}

int main() {
    int n;

    cout << "Enter number of students: ";
    cin >> n;

    ABITURIENT arr[100];

    for (int i = 0; i < n; i++) {
        cout << "\nStudent #" << i + 1 << endl;

        cin.ignore();

        cout << "Enter surname and initials: ";
        getline(cin, arr[i].name);

        cout << "Enter gender: ";
        getline(cin, arr[i].gender);

        cout << "Enter speciality: ";
        getline(cin, arr[i].spec);

        cout << "Enter 3 exam marks: ";
        for (int j = 0; j < 3; j++) {
            cin >> arr[i].exam[j];
        }
    }

    showVowels(arr, n);

    double passing;
    cout << "\nEnter passing average mark: ";
    cin >> passing;

    showBelowPassing(arr, n, passing);

    sortStudents(arr, n);

    cout << "\nSorted array:\n";
    printArray(arr, n);

    deleteAverageFive(arr, n);

    cout << "\nArray after deleting students with average = 5:\n";
    printArray(arr, n);

    return 0;
}