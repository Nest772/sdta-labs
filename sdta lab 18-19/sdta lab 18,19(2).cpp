#include <iostream>
#include <string>

using namespace std;

const string ALPHABET =
"abcdefghijklmnopqrstuvwxyz";

string encrypt(string text,
               string normalAlphabet,
               string cipherAlphabet) {

    for (char &c : text) {

        bool isUpper = isupper(c);

        int idx =
            normalAlphabet.find(tolower(c));

        if (idx != string::npos) {

            c = cipherAlphabet[idx];

            if (isUpper)
                c = toupper(c);
        }
    }

    return text;
}

string decrypt(string text,
               string normalAlphabet,
               string cipherAlphabet) {

    for (char &c : text) {

        bool isUpper = isupper(c);

        int idx =
            cipherAlphabet.find(tolower(c));

        if (idx != string::npos) {

            c = normalAlphabet[idx];

            if (isUpper)
                c = toupper(c);
        }
    }

    return text;
}

int main() {

    string text;
    string cipherAlphabet;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter substitution alphabet:\n";
    getline(cin, cipherAlphabet);

    int mode;

    cout << "1 - Encrypt\n";
    cout << "2 - Decrypt\n";
    cin >> mode;

    if (mode == 1) {

        cout << "Result: "
             << encrypt(
                    text,
                    ALPHABET,
                    cipherAlphabet
                );
    }
    else {

        cout << "Result: "
             << decrypt(
                    text,
                    ALPHABET,
                    cipherAlphabet
                );
    }

    return 0;
}