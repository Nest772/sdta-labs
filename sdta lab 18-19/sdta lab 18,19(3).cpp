#include <iostream>
#include <string>

using namespace std;

const string ALPHABET =
"abcdefghijklmnopqrstuvwxyz";

int getIndex(char c) {
    return ALPHABET.find(tolower(c));
}

string vigenereCipher(string text,
                      string key,
                      bool encrypt = true) {

    int n = ALPHABET.size();

    for (int i = 0, j = 0; i < text.size(); i++) {

        bool isUpper = isupper(text[i]);

        int textIdx = getIndex(text[i]);

        if (textIdx == string::npos)
            continue;

        int keyIdx =
            getIndex(key[j % key.size()]);

        char result;

        if (encrypt)
            result =
                ALPHABET[(textIdx + keyIdx) % n];
        else
            result =
                ALPHABET[(textIdx - keyIdx + n) % n];

        if (isUpper)
            result = toupper(result);

        text[i] = result;

        j++;
    }

    return text;
}

int main() {

    string text;
    string key;

    cout << "Enter text: ";
    getline(cin, text);

    cout << "Enter keyword: ";
    getline(cin, key);

    int mode;

    cout << "1 - Encrypt\n";
    cout << "2 - Decrypt\n";
    cin >> mode;

    if (mode == 1) {

        cout << "Result: "
             << vigenereCipher(text, key, true);
    }
    else {

        cout << "Result: "
             << vigenereCipher(text, key, false);
    }

    return 0;
}