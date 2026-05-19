#include <iostream>
#include <map>
using namespace std;

int main() 
{
    multimap<string, string> phonebook;
    int choice;
    string name, number;

    do {
        cout << "\n1.Add\n2.Show numbers\n3.Delete number\n4.Show all\n0.Exit\n";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Name: "; cin >> name;
            cout << "Number: "; cin >> number;
            phonebook.insert({name, number});
            break;

        case 2:
            cout << "Enter name: "; cin >> name;
            for (auto it = phonebook.equal_range(name).first;
                 it != phonebook.equal_range(name).second; ++it) {
                cout << it->second << endl;
            }
            break;

        case 3:
            cout << "Name: "; cin >> name;
            cout << "Number: "; cin >> number;
            for (auto it = phonebook.begin(); it != phonebook.end(); ) {
                if (it->first == name && it->second == number)
                    it = phonebook.erase(it);
                else ++it;
            }
            break;

        case 4:
            for (auto &p : phonebook)
                cout << p.first << ": " << p.second << endl;
            break;
        }

    } while (choice != 0);

    return 0;
}