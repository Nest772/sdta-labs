#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 3;
const int COLS = 3;


void printMatrix(int arr[ROWS][COLS]) {
    cout << "\nOtimal delivery plan:\n\n";

    cout << setw(8) << " ";
    for (int j = 0; j < COLS; j++) {
        cout << setw(8) << "M" + to_string(j + 1);
    }
    cout << endl;

    for (int i = 0; i < ROWS; i++) {
        cout << setw(8) << "S" + to_string(i + 1);

        for (int j = 0; j < COLS; j++) {
            cout << setw(8) << arr[i][j];
        }
        cout << endl;
    }
}


int calculateCost(int plan[ROWS][COLS], int cost[ROWS][COLS]) {
    int total = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            total += plan[i][j] * cost[i][j];
        }
    }

    return total;
}


void northWestMethod(int supply[], int demand[], int cost[ROWS][COLS]) {
    int plan[ROWS][COLS] = {0};

    int s[ROWS];
    int d[COLS];

    
    for (int i = 0; i < ROWS; i++)
        s[i] = supply[i];

    for (int j = 0; j < COLS; j++)
        d[j] = demand[j];

    int i = 0, j = 0;

    while (i < ROWS && j < COLS) {
        int x = min(s[i], d[j]);

        plan[i][j] = x;

        s[i] -= x;
        d[j] -= x;

        if (s[i] == 0)
            i++;
        else
            j++;
    }

    cout << "===== Method zahidno-pivnichogo kuta =====";
    printMatrix(plan);

    int total = calculateCost(plan, cost);

    cout << "\nMinimal overall price: "
         << total << endl << endl;
}


void minimumCostMethod(int supply[], int demand[], int cost[ROWS][COLS]) {
    int plan[ROWS][COLS] = {0};

    int s[ROWS];
    int d[COLS];

    for (int i = 0; i < ROWS; i++)
        s[i] = supply[i];

    for (int j = 0; j < COLS; j++)
        d[j] = demand[j];

    bool done = false;

    while (!done) {
        int minCost = 100000;
        int row = -1;
        int col = -1;

        
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {

                if (s[i] > 0 && d[j] > 0 && cost[i][j] < minCost) {
                    minCost = cost[i][j];
                    row = i;
                    col = j;
                }
            }
        }

        if (row == -1 || col == -1)
            done = true;
        else {
            int x = min(s[row], d[col]);

            plan[row][col] = x;

            s[row] -= x;
            d[col] -= x;
        }
    }

    cout << "===== Minimal price method =====";
    printMatrix(plan);

    int total = calculateCost(plan, cost);

    cout << "\nMinimal overall price: "
         << total << endl;
}

int main() {

    
    int cost[ROWS][COLS] = {
        {8, 7, 2},
        {1, 4, 3},
        {5, 1, 6}
    };

    
    int supply[ROWS] = {1500, 1900, 1600};

    
    int demand[COLS] = {1800, 1200, 2000};

    northWestMethod(supply, demand, cost);

    minimumCostMethod(supply, demand, cost);

    return 0;
}