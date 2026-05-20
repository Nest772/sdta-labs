#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

using namespace std;

char matrix[5][5];


void findPos(char ch, int &r, int &c) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (matrix[i][j] == ch) {
                r = i; c = j;
                return;
            }
        }
    }
}

int main() {
    string key;
    cout << "Enter encryption key: ";
    getline(cin, key);

    bool used[26] = {false};
    used['J' - 'A'] = true; 

    int r = 0, c = 0;

    for (char ch : key) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (!used[ch - 'A']) {
                matrix[r][c] = ch;
                used[ch - 'A'] = true;
                c++; if (c == 5) { c = 0; r++; }
            }
        }
    }
  
    for (char ch = 'A'; ch <= 'Z'; ch++) {
        if (!used[ch - 'A']) {
            matrix[r][c] = ch;
            c++; if (c == 5) { c = 0; r++; }
        }
    }

    
    cout << "\n--- Playfair Matrix ---" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) cout << matrix[i][j] << " ";
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

    string prep = "";
    for (char ch : text) {
        if (isalpha(ch)) {
            ch = toupper(ch);
            if (ch == 'J') ch = 'I';
            prep += ch;
        }
    }

    
    string pairs = "";
    if (opChoice == 1) {
        for (size_t i = 0; i < prep.length(); i++) {
            pairs += prep[i];
            if (i + 1 < prep.length()) {
                if (prep[i] == prep[i + 1]) {
                    pairs += 'X'; 
                } else {
                    pairs += prep[i + 1];
                    i++;
                }
            } else {
                pairs += 'X'; 
            }
        }
    } else {
        pairs = prep;
        if (pairs.length() % 2 != 0) pairs += 'X';
    }

    
    cout << "\nResult: ";
    for (size_t i = 0; i < pairs.length(); i += 2) {
        char a = pairs[i];
        char b = pairs[i + 1];
        int r1, c1, r2, c2;
        findPos(a, r1, c1);
        findPos(b, r2, c2);

        if (r1 == r2) { 
            if (opChoice == 1) {
                c1 = (c1 + 1) % 5;
                c2 = (c2 + 1) % 5;
            } else {
                c1 = (c1 + 4) % 5;
                c2 = (c2 + 4) % 5;
            }
        } else if (c1 == c2) { 
            if (opChoice == 1) {
                r1 = (r1 + 1) % 5;
                r2 = (r2 + 1) % 5;
            } else {
                r1 = (r1 + 4) % 5;
                r2 = (r2 + 4) % 5;
            }
        } else { 
            int temp = c1;
            c1 = c2;
            c2 = temp;
        }
        cout << matrix[r1][c1] << matrix[r2][c2];
    }
    cout << endl;

    return 0;
}
