#include <iostream>
#include <ctime>

using namespace std;


void bubbleAsc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}


void bubbleDesc(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;

    int A[100], even[100], odd[100];
    int e = 0, o = 0;

    srand(time(0));

  
    cout << "\nArray:\n";
    for (int i = 0; i < n; i++) {
        A[i] = rand() % 100;
        cout << A[i] << " ";
    }

  
    for (int i = 0; i < n; i++) {
        if (A[i] % 2 == 0)
            even[e++] = A[i];
        else
            odd[o++] = A[i];
    }

    
    clock_t start1 = clock();
    bubbleAsc(even, e);
    clock_t end1 = clock();

    
    clock_t start2 = clock();
    bubbleDesc(odd, o);
    clock_t end2 = clock();

    
    cout << "\n\nResult array:\n";

    for (int i = 0; i < e; i++)
        cout << even[i] << " ";

    for (int i = 0; i < o; i++)
        cout << odd[i] << " ";

    
    double timeAsc = double(end1 - start1) / CLOCKS_PER_SEC;
    double timeDesc = double(end2 - start2) / CLOCKS_PER_SEC;

    cout << "\n\nAscending sort time: " << timeAsc;
    cout << "\nDescending sort time: " << timeDesc;

    return 0;
}