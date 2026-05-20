#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct Activity {
    int id;         
    int start;      
    int finish;     
};


bool compareActivities(const Activity& a, const Activity& b) {
    if (a.finish != b.finish) {
        return a.finish < b.finish;
    }
  
    return a.start < b.start;
}

int main() {
    


    int n;
    cout << "Enter number of lessons (n): ";
    if (!(cin >> n) || n <= 0) {
        cout << "Incorrect number of lessons.\n";
        return 0;
    }

    vector<Activity> activities(n);
    cout << "Enter start and end of every lesson:\n";
    for (int i = 0; i < n; ++i) {
        activities[i].id = i + 1; 
        cin >> activities[i].start >> activities[i].finish;
    }

    
    sort(activities.begin(), activities.end(), compareActivities);


    vector<Activity> selected;


    if (n > 0) {
        selected.push_back(activities[0]);
    }

    
    for (int i = 1; i < n; ++i) {

        if (activities[i].start >= selected.back().finish) {
            selected.push_back(activities[i]);
        }
    }

    
    cout << "\n--- Result ---\n";
    cout << "Maximum number of lessons: " << selected.size() << "\n";
    cout << "List of chosen lessons:\n";
    for (const auto& act : selected) {
        cout << "Lesson #" << act.id << " (" << act.start << " -> " << act.finish << ")\n";
    }

    return 0;
}