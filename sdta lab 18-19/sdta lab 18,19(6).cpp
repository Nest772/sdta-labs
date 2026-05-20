#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <chrono>
#include <thread>

using namespace std;


map<char, string> enc;
map<string, char> decod;


void initMaps() {
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string Alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string codes[] = {
        ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
        "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
        "..-", "...-", ".--", "-..-", "-.--", "--.."
    };

    for (size_t i = 0; i < alphabet.length(); i++) {
        enc[Alphabet[i]] = codes[i];
        enc[alphabet[i]] = codes[i]; 
        decod[codes[i]] = Alphabet[i];
    }
    enc[' '] = "/"; 
    decod["/"] = ' ';
}


void playMorse(const string& morse) {
    for (char c : morse) {
        if (c == '.' || c == '-') {
            cout << '\a' << flush;
            this_thread::sleep_for(chrono::milliseconds(250)); 
        } else if (c == ' ') {
            this_thread::sleep_for(chrono::milliseconds(200)); 
        } else if (c == '/') {
            this_thread::sleep_for(chrono::milliseconds(400)); 
        }
    }
}

int main() {
    initMaps();

    cout << "--- MORSE CODE ---\n";
    cout << "1. Encrypt \n";
    cout << "2. Decrypt \n";
    cout << "Select: ";
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "(1 - Console, 2 - File 'input.txt'): ";
        int src;
        cin >> src;
        cin.ignore();

        string text;
        if (src == 1) {
            cout << "Enter text: ";
            getline(cin, text);
        } else {
            ifstream inFile("input.txt");
            if (inFile.is_open()) {
                getline(inFile, text);
                inFile.close();
            } else {
                cout << "Error: Could not open input.txt\n";
                return 1;
            }
        }

        
        string morseResult = "";
        for (char c : text) {
            if (enc.find(c) != enc.end()) {
                morseResult += enc[c] + " ";
            }
        }

        cout << "Encrypted Morse code: " << morseResult << "\n";

        ofstream outFile("output_morse.txt");
        if (outFile.is_open()) {
            outFile << morseResult;
            outFile.close();
            cout << "Saved to 'output_morse.txt'\n";
        }

        cout << "Playing sound...\n";
        playMorse(morseResult);

    } else if (choice == 2) {
        cout << "(1 - Console, 2 - File 'morse.txt'): ";
        int src;
        cin >> src;
        cin.ignore();

        string morseInput;
        if (src == 1) {
            cout << "Enter Morse code: ";
            getline(cin, morseInput);
        } else {
            ifstream inFile("morse.txt");
            if (inFile.is_open()) {
                getline(inFile, morseInput);
                inFile.close();
            } else {
                cout << "Error: Could not open morse.txt\n";
                return 1;
            }
        }

        
        string textResult = "";
        string currentSymbol = "";
        string trackingMorse = morseInput + " "; 

        for (char c : trackingMorse) {
            if (c == ' ' || c == '\n' || c == '\r') {
                if (!currentSymbol.empty()) {
                    if (decod.find(currentSymbol) != decod.end()) {
                        textResult += decod[currentSymbol];
                    }
                    currentSymbol = "";
                }
            } else {
                currentSymbol += c;
            }
        }

        cout << "Decrypted text: " << textResult << "\n";

        ofstream outFile("output_text.txt");
        if (outFile.is_open()) {
            outFile << textResult;
            outFile.close();
            cout << "Saved to 'output_text.txt'\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }

    return 0;
}