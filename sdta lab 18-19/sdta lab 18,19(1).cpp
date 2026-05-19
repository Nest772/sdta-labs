#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

// ??????????? ???????
const string ALPHABET = "?????????????????????????????????";

// ??????? ???? ??????????? ????
map<char, double> freqTable = {
    {'?', 9.28}, {'?', 8.34}, {'?', 7.89}, {'?', 7.56},
    {'?', 6.95}, {'?', 6.29}, {'?', 5.62}, {'?', 5.01},
    {'?', 4.70}, {'?', 4.48}, {'?', 3.95}, {'?', 3.78},
    {'?', 3.61}, {'?', 3.42}, {'?', 2.90}, {'?', 2.65},
    {'?', 2.47}, {'?', 2.20}, {'?', 1.85}, {'?', 1.70},
    {'?', 1.49}, {'?', 1.35}, {'?', 1.11}, {'?', 0.95},
    {'?', 0.82}, {'?', 0.77}, {'?', 0.64}, {'?', 0.59},
    {'?', 0.52}, {'?', 0.43}, {'?', 0.22}, {'?', 0.13}
};

// ======================= ????????? =========================

int getIndex(char c) {
    return ALPHABET.find(c);
}

char shiftChar(char c, int shift) {
    int idx = getIndex(c);

    if (idx == string::npos)
        return c;

    int n = ALPHABET.size();
    int newIdx = (idx + shift + n) % n;

    return ALPHABET[newIdx];
}

// ======================= ????? =========================

string caesarCipher(string text, int shift) {
    for (char &c : text) {
        c = shiftChar(c, shift);
    }
    return text;
}

// ????????? ??????
int findBestShift(string text) {
    vector<int> count(ALPHABET.size(), 0);
    int total = 0;

    for (char c : text) {
        int idx = getIndex(c);
        if (idx != string::npos) {
            count[idx]++;
            total++;
        }
    }

    double bestFreq = 0;
    char mostFrequent = '?';

    for (int i = 0; i < ALPHABET.size(); i++) {
        double freq = (double)count[i] / total * 100;

        if (freq > bestFreq) {
            bestFreq = freq;
            mostFrequent = ALPHABET[i];
        }
    }

    int shift = getIndex(mostFrequent) - getIndex('?');

    return shift;
}

// ======================= ?????? ?????? =========================

string simpleSubstitutionEncrypt(string text,
                                 string normalAlphabet,
                                 string cipherAlphabet) {
    for (char &c : text) {
        int idx = normalAlphabet.find(c);

        if (idx != string::npos)
            c = cipherAlphabet[idx];
    }

    return text;
}

string simpleSubstitutionDecrypt(string text,
                                 string normalAlphabet,
                                 string cipherAlphabet) {
    for (char &c : text) {
        int idx = cipherAlphabet.find(c);

        if (idx != string::npos)
            c = normalAlphabet[idx];
    }

    return text;
}

// ======================= ??????? =========================

string vigenereCipher(string text, string key, bool encrypt = true) {
    int n = ALPHABET.size();

    for (int i = 0, j = 0; i < text.size(); i++) {

        int textIdx = getIndex(text[i]);

        if (textIdx == string::npos)
            continue;

        int keyIdx = getIndex(key[j % key.size()]);

        if (encrypt)
            text[i] = ALPHABET[(textIdx + keyIdx) % n];
        else
            text[i] = ALPHABET[(textIdx - keyIdx + n) % n];

        j++;
    }

    return text;
}

// ======================= ???? =========================

string readFromFile(string filename) {
    ifstream file(filename);

    string text, line;

    while (getline(file, line)) {
        text += line + '\n';
    }

    file.close();

    return text;
}

// ======================= ???? =========================

void caesarMenu() {
    string text;
    int shift, mode;

    cin.ignore();

    cout << "??????? ?????: ";
    getline(cin, text);

    cout << "1 - ??????????\n";
    cout << "2 - ????????????\n";
    cout << "3 - ??????????? ???????????? (????????? ?????)\n";
    cin >> mode;

    if (mode == 1) {
        cout << "??????? ????: ";
        cin >> shift;

        cout << "?????????: "
             << caesarCipher(text, shift) << endl;
    }
    else if (mode == 2) {
        cout << "??????? ????: ";
        cin >> shift;

        cout << "?????????: "
             << caesarCipher(text, -shift) << endl;
    }
    else if (mode == 3) {
        int bestShift = findBestShift(text);

        cout << "????????? ????: " << bestShift << endl;

        cout << "????????????? ?????: "
             << caesarCipher(text, -bestShift) << endl;
    }
}

void substitutionMenu() {
    string text;

    cin.ignore();

    cout << "??????? ?????: ";
    getline(cin, text);

    string cipherAlphabet;

    cout << "??????? ??????? ??????:\n";
    cout << "(33 ??????? ???????????? ????????)\n";

    getline(cin, cipherAlphabet);

    int mode;

    cout << "1 - ??????????\n";
    cout << "2 - ????????????\n";
    cin >> mode;

    if (mode == 1) {
        cout << "?????????: "
             << simpleSubstitutionEncrypt(
                    text,
                    ALPHABET,
                    cipherAlphabet
                ) << endl;
    }
    else {
        cout << "?????????: "
             << simpleSubstitutionDecrypt(
                    text,
                    ALPHABET,
                    cipherAlphabet
                ) << endl;
    }
}

void vigenereMenu() {
    string text, key;

    cin.ignore();

    cout << "??????? ?????: ";
    getline(cin, text);

    cout << "??????? ??????? ?????: ";
    getline(cin, key);

    int mode;

    cout << "1 - ??????????\n";
    cout << "2 - ????????????\n";
    cin >> mode;

    if (mode == 1) {
        cout << "?????????: "
             << vigenereCipher(text, key, true)
             << endl;
    }
    else {
        cout << "?????????: "
             << vigenereCipher(text, key, false)
             << endl;
    }
}

// ======================= MAIN =========================

int main() {

    setlocale(LC_ALL, "ukr");

    int choice;

    do {
        cout << "\n========= ???? =========\n";
        cout << "1 - ???? ??????\n";
        cout << "2 - ?????? ??????\n";
        cout << "3 - ???? ????????\n";
        cout << "0 - ?????\n";

        cin >> choice;

        switch (choice) {

            case 1:
                caesarMenu();
                break;

            case 2:
                substitutionMenu();
                break;

            case 3:
                vigenereMenu();
                break;

            case 0:
                cout << "?????????? ????????...\n";
                break;

            default:
                cout << "???????? ?????!\n";
        }

    } while (choice != 0);

    return 0;
}