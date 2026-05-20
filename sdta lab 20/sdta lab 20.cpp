#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    

    double max_calories = 0;
    double best_meat = 0, best_flour = 0, best_milk = 0, best_sugar = 0;
    
    
    double step = 0.1; 

    
    for (double meat = 0; meat <= 35.0; meat += step) {
        for (double flour = 0; flour <= (meat / 2.0); flour += step) {  
            for (double milk = 0; milk <= flour; milk += step) {        
                for (double sugar = 0; sugar <= (milk / 8.0); sugar += step) { 

                    
                    double total_weight = meat + flour + milk + sugar;
                    if (total_weight > 35.0) continue;

                    
                    double total_volume = (1.0 * meat) + (1.5 * flour) + (2.0 * milk) + (1.0 * sugar);
                    if (total_volume > 45.0) continue;

              
                    double calories = (1500.0 * meat) + (5000.0 * flour) + (5000.0 * milk) + (4000.0 * sugar);

                    
                    if (calories > max_calories) {
                        max_calories = calories;
                        best_meat = meat;
                        best_flour = flour;
                        best_milk = milk;
                        best_sugar = sugar;
                    }
                }
            }
        }
    }

    
    cout << "=== optimal backpack composition ===" << endl;
    cout << fixed << setprecision(1);
    cout << "Meat: " << best_meat << " kg" << endl;
    cout << "flour:  " << best_flour << " kg" << endl;
    cout << "dry milk: " << best_milk << " kg" << endl;
    cout << "sugar: " << best_sugar << " kg" << endl;
    cout << "---------------------------------" << endl;
    cout << "overall mass: " << (best_meat + best_flour + best_milk + best_sugar) << " kg (max. 35)" << endl;
    cout << "overall volume: " << (1.0 * best_meat + 1.5 * best_flour + 2.0 * best_milk + 1.0 * best_sugar) << " dm^3 (max. 45)" << endl;
    cout << "maximum calories: " << setprecision(0) << max_calories << " ccal" << endl;

    return 0;
}