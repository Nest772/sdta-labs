#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> wordCount;
    string word;

    cout << "Enter words/text (Press Ctrl+Z then Enter on Windows, or Ctrl+D on Mac/Linux to stop reading):\n";
    
  
    while (cin >> word) {
   
        while (!word.empty() && ispunct(word.back())) {
            word.pop_back();
        }
        while (!word.empty() && ispunct(word.front())) {
            word.erase(0, 1);
        }
        
        if (!word.empty()) {
            wordCount[word]++;
        }
    }

    
    cout << "\n--- Word Frequency (Alphabetical Order) ---\n";
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << "\n";
    }

    return 0;
}