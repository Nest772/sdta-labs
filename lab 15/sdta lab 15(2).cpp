#include <iostream>
#include <string>
#include <vector>

using namespace std;



struct Time {
    int hours;
    int minutes;
};

struct Train {
    int trainNumber;
    string destination;
    double distanceKm;
    Time departureTime;
    Time arrivalTime;
    int travelTimeMinutes; 
};


void selectionSortTrainsByTime(vector<Train>& trains) {
    int n = trains.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (trains[j].travelTimeMinutes > trains[maxIdx].travelTimeMinutes) {
                maxIdx = j;
            }
        }
        swap(trains[i], trains[maxIdx]);
    }
}

void runTrainSubsystem() {
    int n;
    cout << "\n===== [PART A] TRAIN TIMETABLE MANAGEMENT =====\n";
    cout << "Enter the number of trains to register: ";
    cin >> n;

    vector<Train> timetable(n);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Train #" << i + 1 << " ---\n";
        cout << "Train Number: "; cin >> timetable[i].trainNumber;
        cout << "Destination Station: "; cin.ignore(); getline(cin, timetable[i].destination);
        cout << "Distance (km): "; cin >> timetable[i].distanceKm;
        cout << "Departure Time (Hours Minutes): "; cin >> timetable[i].departureTime.hours >> timetable[i].departureTime.minutes;
        cout << "Arrival Time (Hours Minutes): "; cin >> timetable[i].arrivalTime.hours >> timetable[i].arrivalTime.minutes;
        cout << "Total Travel Time (in minutes): "; cin >> timetable[i].travelTimeMinutes;
    }

    if (n == 0) return;

    
    int longestIdx = 0;
    for (int i = 1; i < n; i++) {
        if (timetable[i].travelTimeMinutes > timetable[longestIdx].travelTimeMinutes) {
            longestIdx = i;
        }
    }
    cout << "\n-> [Result A]: Longest journey train discovered via direct scan:\n";
    cout << "   Train No: " << timetable[longestIdx].trainNumber 
         << " bound for " << timetable[longestIdx].destination 
         << " (" << timetable[longestIdx].travelTimeMinutes << " mins)\n";

    
    selectionSortTrainsByTime(timetable);
    
    cout << "\n-> [Result B]: Train records sorted by maximum travel time (Selection Sort):\n";
    for (const auto& train : timetable) {
        cout << "   Train No: " << train.trainNumber 
             << " | Destination: " << train.destination 
             << " | Duration: " << train.travelTimeMinutes << " mins\n";
    }
}



struct Television {
    string manufacturer;
    int screenSize; 
    double priceUah;
};


void advancedTelevisionSort(vector<Television>& tvs) {
    int n = tvs.size();

    
    for (int i = 1; i < n; i++) {
        Television key = tvs[i];
        int j = i - 1;
        while (j >= 0 && tvs[j].screenSize > key.screenSize) {
            tvs[j + 1] = tvs[j];
            j--;
        }
        tvs[j + 1] = key;
    }

  
    int index = 0;
    while (index < n) {
        if (index == 0) index++;
        
        if (tvs[index].screenSize == tvs[index - 1].screenSize) {
            if (tvs[index].priceUah > tvs[index - 1].priceUah) { 
                swap(tvs[index], tvs[index - 1]);
                index--;
            } else {
                index++;
            }
        } else {
            index++;
        }
    }
}

void runTelevisionSubsystem() {
    int n;
    cout << "\n===== [PART B] TELEVISION INVENTORY MANAGEMENT =====\n";
    cout << "Enter the number of TVs to register: ";
    cin >> n;

    vector<Television> catalog(n);

    for (int i = 0; i < n; i++) {
        cout << "\n--- TV #" << i + 1 << " ---\n";
        cout << "Manufacturer brand name: "; cin.ignore(); getline(cin, catalog[i].manufacturer);
        cout << "Screen Size (e.g., 32, 45, 60): "; cin >> catalog[i].screenSize;
        cout << "Price (UAH): "; cin >> catalog[i].priceUah;
    }

    advancedTelevisionSort(catalog);

    cout << "\n================= SORTED TV CATALOG =================\n";
    cout << "Manufacturer\tScreen Size\tPrice (UAH)\n";
    cout << "-----------------------------------------------------\n";
    for (const auto& tv : catalog) {
        cout << tv.manufacturer << "\t\t" << tv.screenSize << " inches\t" << tv.priceUah << " UAH\n";
    }
    cout << "=====================================================\n";
}


int main() {
    int choice;
    while (true) {
        cout << "\n================= MAIN SELECTION MENU =================\n";
        cout << "1. Run Train Timetable Management (Task 2 - Part A)\n";
        cout << "2. Run Television Catalog Sorting   (Task 2 - Part B)\n";
        cout << "3. Close Application\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        if (choice == 3) {
            cout << "Exiting application. Goodbye!\n";
            break;
        }

        switch (choice) {
            case 1:
                runTrainSubsystem();
                break;
            case 2:
                runTelevisionSubsystem();
                break;
            default:
                cout << "Invalid choice! Please select an option between 1 and 3.\n";
        }
    }
    return 0;
}