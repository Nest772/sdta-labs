#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, string> phoneBook;
    int choice;

    while (true) {
        cout << "\n--- PHONE BOOK MENU ---\n";
        cout << "1. Add New Contact\n";
        cout << "2. Search Number by Name\n";
        cout << "3. Delete Contact\n";
        cout << "4. View All Contacts\n";
        cout << "5. Exit\n";
        cout << "Enter option: ";
        cin >> choice;

        if (choice == 5) break;

        string name, phone;
        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter phone number: ";
                getline(cin, phone);
                phoneBook[name] = phone;
                cout << "Contact added/updated.\n";
                break;
            case 2:
                cout << "Enter name to search: ";
                cin.ignore();
                getline(cin, name);
                if (phoneBook.find(name) != phoneBook.end()) {
                    cout << "Phone number: " << phoneBook[name] << "\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;
            case 3:
                cout << "Enter name to delete: ";
                cin.ignore();
                getline(cin, name);
                if (phoneBook.erase(name)) {
                    cout << "Contact deleted successfully.\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;
            case 4:
                cout << "\n--- Contact List ---\n";
                for (const auto& entry : phoneBook) {
                    cout << entry.first << " -> " << entry.second << "\n";
                }
                break;
            default:
                cout << "Invalid choice\n";
        }
    }
    return 0;
}