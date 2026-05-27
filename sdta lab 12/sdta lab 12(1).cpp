#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string author;
    string genre;
    double price;
    int popularity; 
    int arrivalYear; 
};


void addBook(vector<Book>& inventory) {
    Book b;
    cout << "Enter title: "; cin.ignore(); getline(cin, b.title);
    cout << "Enter author: "; getline(cin, b.author);
    cout << "Enter genre: "; getline(cin, b.genre);
    cout << "Enter price: "; cin >> b.price;
    cout << "Enter popularity rating: "; cin >> b.popularity;
    cout << "Enter arrival year: "; cin >> b.arrivalYear;
    inventory.push_back(b);
    cout << "Book added successfully!\n";
}


void removeBook(vector<Book>& inventory) {
    string targetTitle;
    cout << "Enter the title of the book to remove: ";
    cin.ignore();
    getline(cin, targetTitle);

    auto it = remove_if(inventory.begin(), inventory.end(), [&](const Book& b) {
        return b.title == targetTitle;
    });

    if (it != inventory.end()) {
        inventory.erase(it, inventory.end());
        cout << "Book removed successfully.\n";
    } else {
        cout << "Book not found.\n";
    }
}


void displayInventory(const vector<Book>& inventory) {
    if (inventory.empty()) {
        cout << "Inventory is empty.\n";
        return;
    }
    for (const auto& b : inventory) {
        cout << "[" << b.title << " by " << b.author << "] Genre: " << b.genre 
             << " | Price: $" << b.price << " | Pop: " << b.popularity 
             << " | Year: " << b.arrivalYear << "\n";
    }
}

int main() {
    vector<Book> inventory;
    int choice;

    while (true) {
        cout << "\n--- BOOKSTORE MENU ---\n";
        cout << "1. Add Book\n2. Remove Book\n3. Sort by Price\n4. Sort by Popularity\n";
        cout << "5. Filter by Genre & Price\n6. Display All\n7. Exit\nChoice: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
            case 1: addBook(inventory); break;
            case 2: removeBook(inventory); break;
            case 3:
                sort(inventory.begin(), inventory.end(), [](const Book& a, const Book& b) { return a.price < b.price; });
                cout << "Sorted by price (ascending).\n";
                break;
            case 4:
                sort(inventory.begin(), inventory.end(), [](const Book& a, const Book& b) { return a.popularity > b.popularity; });
                cout << "Sorted by popularity (descending).\n";
                break;
            case 5: {
                string targetGenre;
                double minPrice, maxPrice;
                cout << "Enter genre: "; cin.ignore(); getline(cin, targetGenre);
                cout << "Enter min price: "; cin >> minPrice;
                cout << "Enter max price: "; cin >> maxPrice;
                
                cout << "\nFiltered Books:\n";
                for (const auto& b : inventory) {
                    if (b.genre == targetGenre && b.price >= minPrice && b.price <= maxPrice) {
                        cout << "- " << b.title << " ($" << b.price << ")\n";
                    }
                }
                break;
            }
            case 6: displayInventory(inventory); break;
            default: cout << "Invalid option!\n";
        }
    }
    return 0;
}