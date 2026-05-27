#include <iostream>

using namespace std;

int main() {
    int n;

    cout << "Enter matrix size: ";
    cin >> n;

    int A[100][100];

    
    cout << "\nEnter matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        A[i][i] = 0;
    }

    cout << "\nMatrix after deleting main diagonal:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

   
    int maxEl = A[0][0];
    int maxRow = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (A[i][j] > maxEl) {
                maxEl = A[i][j];
                maxRow = i;
            }
        }
    }

    
    for (int i = maxRow; i < n - 1; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = A[i + 1][j];
        }
    }

    n--;

    cout << "\nMatrix after deleting row with maximum element:\n";

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}