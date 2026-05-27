#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct Worker {
    string name;       
    string position;
    int hireYear;
    double baseSalary;
};


int getExperience(const Worker& w) {
    const int CURRENT_YEAR = 2026;
    return CURRENT_YEAR - w.hireYear;
}

double getNetSalary(const Worker& w) {
    double taxRate = 0.33;
    return w.baseSalary * (1.0 - taxRate);
}

int main() {
    int n;
    cout << "Enter the number of workers: ";
    cin >> n;
    cin.ignore(); 

    vector<Worker> workers(n);

    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Enter details for Worker #" << i + 1 << " ---\n";
        cout << "Name and initials: ";
        getline(cin, workers[i].name);
        cout << "Position: ";
        getline(cin, workers[i].position);
        cout << "Year of employment: ";
        cin >> workers[i].hireYear;
        cout << "Base salary: ";
        cin >> workers[i].baseSalary;
        cin.ignore(); 
    }

    
    cout << "\n================ WORKER RESULTS ================\n";
    for (int i = 0; i < n; i++) {
        cout << "\nWorker: " << workers[i].name << "\n";
        cout << "Position: " << workers[i].position << "\n";
        cout << "Experience: " << getExperience(workers[i]) << " years\n";
        cout << "Net Salary (after 33% tax): " << getNetSalary(workers[i]) << "\n";
    }

    return 0;
}