#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;


bool isMultipleOfFour(int n) {
    return (n > 0 && n % 4 == 0);
}


void generateArray(double* arr, int n) {
    
    static bool seeded = false;
    if (!seeded) {
        srand(time(0));
        seeded = true;
    }
    
    for (int i = 0; i < n; i++) {
        double randomFraction = (double)rand() / RAND_MAX;
        arr[i] = -1.50 + randomFraction * (4.50 - (-1.50));
    }
}

void printArray(const double* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << fixed << setprecision(2) << arr[i] << " ";
    }
    cout << endl;
}


double** createMatrix(const double* arr, int n, int& rows) {
    rows = n / 4;
    double** matrix = new double*[rows];
    for (int i = 0; i < rows; i++) {
        matrix[i] = new double[4];
        for (int j = 0; j < 4; j++) {
            matrix[i][j] = arr[i * 4 + j];
        }
    }
    return matrix;
}


void bubbleSort(double* arr, int size, bool ascending) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((ascending && arr[j] > arr[j + 1]) || (!ascending && arr[j] < arr[j + 1])) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


double findMax(const double* arr, int size) {
    double maxVal = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}


void freeMatrix(double** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}


void runExperiment(int n, double& elapsedSeconds, size_t& spaceBytes) {
    if (!isMultipleOfFour(n)) {
        cout << "Error: Size " << n << " is not a multiple of 4." << endl;
        return;
    }

    
    spaceBytes = (n * sizeof(double)) + sizeof(double*) + sizeof(int);

    double* arr = new double[n];
    generateArray(arr, n);

  
    clock_t startTime = clock();

    
    int rows = 0;
    double** matrix = createMatrix(arr, n, rows);
    
  
    spaceBytes += (rows * sizeof(double*)) + (rows * 4 * sizeof(double)) + sizeof(double**);

  
    for (int i = 0; i < rows; i++) {
        
        bool ascending = (i % 2 == 0);
        bubbleSort(matrix[i], 4, ascending);
    }

   
    double maxInColumns[4];
    spaceBytes += sizeof(maxInColumns);
    
    for (int col = 0; col < 4; col++) {
        
        double colArray[1000]; 
        for (int row = 0; row < rows; row++) {
            colArray[row] = matrix[row][col];
        }
        maxInColumns[col] = findMax(colArray, rows);
    }

    // End tracking execution time
    clock_t endTime = clock();
    elapsedSeconds = (double)(endTime - startTime) / CLOCKS_PER_SEC;

    
    if (n == 20) {
        cout << "\n--- Demonstration (n = 20) ---" << endl;
        cout << "Generated Array:" << endl;
        printArray(arr, n);
        
        cout << "\nProcessed Matrix Sorted rows:" << endl;
        for (int i = 0; i < rows; i++) {
            printArray(matrix[i], 4);
        }
        
        cout << "\nMax elements for each column:" << endl;
        printArray(maxInColumns, 4);
        cout << "-------------------------------------\n" << endl;
    }

    
    freeMatrix(matrix, rows);
    delete[] arr;
}

int main() {
    int testSizes[] = {20, 100, 1000};
    double times[3] = {0};
    size_t spaces[3] = {0};

  
    for (int i = 0; i < 3; i++) {
        runExperiment(testSizes[i], times[i], spaces[i]);
    }

    
    ofstream outFile("output.txt");
    if (outFile.is_open()) {
        outFile << "|-----|-------|------------|------------|\n";
        outFile << "|  ?  |   n   | Time, sec. | Space, byte|\n";
        outFile << "|-----|-------|------------|------------|\n";
        for (int i = 0; i < 3; i++) {
            outFile << "|  " << (i + 1) << "  | " 
                    << setw(5) << testSizes[i] << " | " 
                    << setw(10) << fixed << setprecision(3) << times[i] << " | " 
                    << setw(10) << spaces[i] << " |\n";
            outFile << "|-----|-------|------------|------------|\n";
        }
        outFile.close();
        cout << "Successfully written to 'output.txt'!" << endl;
    } else {
        cerr << "Error opening file for writing." << endl;
    }

    return 0;
}