#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    int n = 5;
    int A[n][n];

    srand(time(0));

    
    cout << "Pochatkova matrica:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = rand() % 100; 
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    
    int max = A[0][0];
    int maxRow = 0, maxCol = 0;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (A[i][j] > max) {
                max = A[i][j];
                maxRow = i;
                maxCol = j;
            }

    cout << "\nMax element = " << max << endl;

    
        if (maxRow != 0) {
        for (int j = 0; j < n; j++) {
            int temp = A[0][j];
            A[0][j] = A[maxRow][j];
            A[maxRow][j] = temp;
        }

        cout << "\nPislya perestanovky ryadkiv:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    }

    if (maxCol != 0) {
        for (int i = 0; i < n; i++) {
            int temp = A[i][0];
            A[i][0] = A[i][maxCol];
            A[i][maxCol] = temp;
        }

        cout << "\nPislya perestanovky stovpciv:\n";
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                cout << A[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}