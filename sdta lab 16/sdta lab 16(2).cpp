#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Product {
    string name;
    double proteins;
    double fats;
    double carbohydrates;
    double calories;
};

int main() {
    cout << "===== FOOD PRODUCT CALORIE ANALYSIS =====\n";
    int n;
    cout << "Enter the number of food items (n): ";
    cin >> n;

    vector<Product> catalog(n);
    double maxCalories = -1.0;

    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Product #" << i + 1 << " ---\n";
        cout << "Product name: ";
        cin.ignore();
        getline(cin, catalog[i].name);
        cout << "Proteins (grams): "; cin >> catalog[i].proteins;
        cout << "Fats (grams): ";     cin >> catalog[i].fats;
        cout << "Carbs (grams): ";    cin >> catalog[i].carbohydrates;

     
        catalog[i].calories = (4.0 * catalog[i].proteins) + (9.0 * catalog[i].fats) + (4.0 * catalog[i].carbohydrates);
        cout << "   Computed energy density value: " << catalog[i].calories << " kcal\n";

        if (catalog[i].calories > maxCalories) {
            maxCalories = catalog[i].calories;
        }
    }

    
    cout << "\n-> [Linear Search Results - Max Calories]:\n";
    cout << "Highest calculated energy density: " << maxCalories << " kcal\n";
    int maxProductCount = 0;
    for (int i = 0; i < n; i++) {
        if (catalog[i].calories == maxCalories) {
            cout << "   Index position in array [" << i << "]: " << catalog[i].name << "\n";
            maxProductCount++;
        }
    }
    cout << "Total count of items matching peak energy density: " << maxProductCount << "\n";

  
    double rangeA, rangeB;
    cout << "\n-> [Range Filtering Mode]:\n";
    cout << "Enter lower calorie bound limit (A): "; cin >> rangeA;
    cout << "Enter upper calorie bound limit (B): "; cin >> rangeB;

    cout << "\nProducts falling into range [" << rangeA << " to " << rangeB << " kcal]:\n";
    bool rangeFound = false;
    for (const auto& prod : catalog) {
        if (prod.calories >= rangeA && prod.calories <= rangeB) {
            cout << " - " << prod.name << " (" << prod.calories << " kcal)\n";
            rangeFound = true;
        }
    }

    if (!rangeFound) {
        cout << "   No product records matched your specified calorie window.\n";
    }

    return 0;
}