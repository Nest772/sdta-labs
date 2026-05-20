#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

int main() {
    char square[5][5];
    char current = 'A';
    
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (current == 'J') current++;
            square[i][j] = current++;
        }
    }

    
    cout << "--- Polybius Square ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) cout << square[i][j] << " ";
        cout << endl;
    }

    
    int sourceChoice;
    cout << "\n1. Keyboard input\n2. Read from file (input.txt)\nChoose input source: ";
    cin >> sourceChoice;
    cin.ignore();

    string text = "";
    if (sourceChoice == 2) {
        ifstream infile("input.txt");
        if (!infile) {
            cout << "Error opening file!" << endl;
            return 1;
        }
        getline(infile, text);
        infile.close();
    } else {
        cout << "Enter text: ";
        getline(cin, text);
    }

    
    int opChoice;
    cout << "\n1. Encrypt\n2. Decrypt\nChoose operation: ";
    cin >> opChoice;
    cin.ignore();

    if (opChoice == 1) {
        cout << "\nOriginal text: " << text << endl;
        cout << "Encrypted text: ";
        for (char c : text) {
            if (!isalpha(c)) continue;
            c = toupper(c);
            if (c == 'J') c = 'I';
            
            
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (square[i][j] == c) {
                        cout << (i + 1) << (j + 1) << " ";
                    }
                }
            }
        }
        cout << endl;
    } else {
        cout << "\nOriginal coordinates: " << text << endl;
        cout << "Decrypted text: ";
        int r = -1;
        for (char c : text) {
            if (isdigit(c)) {
                if (r == -1) {
                    r = c - '1'; 
                } else {
                    int col = c - '1'; 
                    if (r >= 0 && r < 5 && col >= 0 && col < 5) {
                        cout << square[r][col];
                    }
                    r = -1; 
                }
            }
        }
        cout << endl;
    }

    return 0;
}