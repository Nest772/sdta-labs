#include <iostream>
#include <string>

using namespace std;

const string ALPHABET = "abcdefghijklmnopqrstuvwxyz";

int getIndex(char c) {
    return ALPHABET.find(tolower(c));
}

char shiftChar(char c, int shift) {

    bool isUpper = isupper(c);

    int idx = getIndex(c);

    if (idx == string::npos)
        return c;

    int n = ALPHABET.size();

    int newIdx = (idx + shift + n) % n;

    char result = ALPHABET[newIdx];

    if (isUpper)
        result = toupper(result);

    return result;
}

string caesarCipher(string text, int shift) {

    for (char &c : text) {
        c = shiftChar(c, shift);
    }

    return text;
}

int main() {

    string text;
    int shift;
    int mode;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "1 - Encrypt\n";
    cout << "2 - Decrypt\n";
    cin >> mode;

    cout << "Enter shift: ";
    cin >> shift;

    if (mode == 1) {
        cout << "Result: "
             << caesarCipher(text, shift);
    }
    else {
        cout << "Result: "
             << caesarCipher(text, -shift);
    }

    return 0;
}