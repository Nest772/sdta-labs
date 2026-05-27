#include <iostream>
#include <ctime>
using namespace std;

int main() {
    int n = 10;
    int A[n];
    int X;

    cout << "Enter X: ";
    cin >> X;

    srand(time(0));


    for (int i = 0; i < n; i++) {
        bool unique;
        do {
            unique = true;
            A[i] = rand() % 100;

            for (int j = 0; j < i; j++) {
                if (A[i] == A[j]) {
                    unique = false;
                    break;
                }
            }
        } while (!unique);
    }


    cout << "Array before:"<<endl;
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    
    int k = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] > X) {
            A[k] = A[i];
            k++;
        }
    }

    
    while (k < n) {
        A[k] = 0;
        k++;
    }

    
    cout << "\nArray after deleting and adding zeros:\n";
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";

    return 0;
}