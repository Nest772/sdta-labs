#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Product {
    string name;
    double price;
    double nutrients[3]; 
    double calories;
};

double calculateCalories(const double n[3]) {
    return 4 * n[0] + 9 * n[1] + 4 * n[2];
}


vector<Product> inputProducts() {
    vector<Product> arr = {
        {"Apple", 20, {1, 0.5, 14}},
        {"Bread", 25, {8, 1, 50}},
        {"Milk", 30, {3, 3, 5}},
        {"Meat", 80, {20, 15, 0}},
        {"Fish", 70, {18, 10, 0}},
        {"Rice", 40, {7, 1, 60}}
    };

    
    for (auto &p : arr) {
        p.calories = calculateCalories(p.nutrients);
    }

    return arr;
}

void printProducts(const vector<Product>& arr) {
    for (const auto& p : arr) {
        cout << "\nName: " << p.name
             << "\nPrice: " << p.price
             << "\nP/F/C: "
             << p.nutrients[0] << " / "
             << p.nutrients[1] << " / "
             << p.nutrients[2]
             << "\nCalories: " << p.calories
             << "\n-------------------------";
    }
    cout << endl;
}

void selectionSortByCalories(vector<Product>& arr) {
    int n = arr.size();

    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j].calories > arr[maxIndex].calories) {
                maxIndex = j;
            }
        }

        swap(arr[i], arr[maxIndex]);
    }
}

void gnomeSortByPrice(vector<Product>& arr) {
    int i = 0;
    int n = arr.size();

    while (i < n) {
        if (i == 0 || arr[i].price >= arr[i - 1].price) {
            i++;
        } else {
            swap(arr[i], arr[i - 1]);
            i--;
        }
    }
}

vector<Product> searchByPrice(const vector<Product>& arr, double price) {
    vector<Product> result;

    for (const auto& p : arr) {
        if (p.price == price) {
            result.push_back(p);
        }
    }

    return result;
}

int main() {
    vector<Product> products = inputProducts();

    cout << "\n=== Initial Array ===\n";
    printProducts(products);

    vector<Product> sortedCalories = products;
    selectionSortByCalories(sortedCalories);

    cout << "\n=== Sort by calories ===\n";
    printProducts(sortedCalories);

    vector<Product> sortedPrice = products;
    gnomeSortByPrice(sortedPrice);

    cout << "\n=== Sort by price ===\n";
    printProducts(sortedPrice);

    
    double targetPrice;
    cout << "\nEnter price to search: ";
    cin >> targetPrice;

    vector<Product> found = searchByPrice(products, targetPrice);


    cout << "\n=== Search result ===\n";
    if (found.empty()) {
        cout << "Nothing found\n";
    } else {
        printProducts(found);
    }
    return 0;
}