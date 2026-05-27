#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

int main() {
    multimap<char, string> groupedWords;
    string word;

    cout << "Enter a list of words separated by spaces (type 'STOP' to finish):\n";

    while (cin >> word) {
        if (word == "STOP" || word == "stop") break;
        
        if (!word.empty()) {
            char firstLetter = word[0];
            groupedWords.insert({firstLetter, word});
        }
    }

    
    cout << "\n--- Words Grouped by Initial Letter ---\n";
    char currentKey = '\0';
    
    for (const auto& pair : groupedWords) {
        if (pair.first != currentKey) {
            currentKey = pair.first;
            cout << "\n[" << currentKey << "]:\n";
        }
        cout << "  - " << pair.second << "\n";
    }

    return 0;
}