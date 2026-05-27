#include <iostream>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;

struct Order {
    int orderNumber;
    string clientName;
    string address;
    double price;
    string priority;   
    int orderTime;     
    string status;     
};


void addOrder(deque<Order>& orderQueue) {
    Order o;
    cout << "Order ID: "; cin >> o.orderNumber;
    cout << "Client Last Name: "; cin.ignore(); getline(cin, o.clientName);
    cout << "Delivery Address: "; getline(cin, o.address);
    cout << "Order cost: "; cin >> o.price;
    cout << "Priority (Urgent/Regular): "; cin >> o.priority;
    cout << "Placement Hour (0-23): "; cin >> o.orderTime;
    o.status = "Pending";

    if (o.priority == "Urgent" || o.priority == "urgent") {
        orderQueue.push_front(o); 
    } else {
        orderQueue.push_back(o);  
    }
    cout << "Order filed successfully.\n";
}


void removeFinishedOrders(deque<Order>& orderQueue) {
    auto it = remove_if(orderQueue.begin(), orderQueue.end(), [](const Order& o) {
        return o.status == "Completed" || o.status == "Cancelled";
    });
    if (it != orderQueue.end()) {
        orderQueue.erase(it, orderQueue.end());
        cout << "Removed all completed and cancelled orders from active queue.\n";
    } else {
        cout << "No orders met deletion criteria.\n";
    }
}


void filterOrders(const deque<Order>& orderQueue) {
    double minP, maxP;
    string targetStatus, targetPriority;
    int minT, maxT;

    cout << "\n--- Filtering Rules Initialization ---\n";
    cout << "Enter min price filter: "; cin >> minP;
    cout << "Enter max price filter: "; cin >> maxP;
    cout << "Enter target status to show (Pending/Completed/Cancelled): "; cin >> targetStatus;
    cout << "Enter target priority to show (Urgent/Regular): "; cin >> targetPriority;
    cout << "Enter min window hour: "; cin >> minT;
    cout << "Enter max window hour: "; cin >> maxT;

    cout << "\nMatched Results:\n";
    for (const auto& o : orderQueue) {
        if (o.price >= minP && o.price <= maxP && 
            o.status == targetStatus && 
            o.priority == targetPriority &&
            o.orderTime >= minT && o.orderTime <= maxT) {
            cout << "- Order #" << o.orderNumber << " for " << o.clientName << " | Price: $" << o.price << "\n";
        }
    }
}

int main() {
    deque<Order> orderQueue;
    int choice;

    while (true) {
        cout << "\n--- COURIER SERVICE DEQUE MANAGEMENT ---\n";
        cout << "1. File/Add New Order\n2. Clean Completed/Cancelled Orders\n";
        cout << "3. Filter Queue by Custom Criteria\n4. Sort Active Pipeline by Price\n5. Exit\nChoice: ";
        cin >> choice;

        if (choice == 5) break;

        switch (choice) {
            case 1: addOrder(orderQueue); break;
            case 2: removeFinishedOrders(orderQueue); break;
            case 3: filterOrders(orderQueue); break;
            case 4:
                sort(orderQueue.begin(), orderQueue.end(), [](const Order& a, const Order& b) {
                    return a.price < b.price;
                });
                cout << "Queue sorted by transaction value scale successfully.\n";
                break;
            default: cout << "Invalid prompt selection.\n";
        }
    }
    return 0;
}