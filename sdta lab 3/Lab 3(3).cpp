#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum PaymentType { CASH, CARD, BANK_TRANSFER };


union PaymentDetails {
    int receiptNumber;      
    long long cardNumber;    
    int transactionId;       
};


struct Payment {
    int paymentId;
    PaymentType type;
    PaymentDetails details;
};

int main() {
    int n;
    cout << "Enter number of payments to register: ";
    cin >> n;

    vector<Payment> payments(n);
    
    
    int cashCount = 0;
    int cardCount = 0;
    int bankCount = 0;

    
    for (int i = 0; i < n; i++) {
        cout << "\n--- Payment #" << i + 1 << " ---\n";
        cout << "Enter Payment ID: ";
        cin >> payments[i].paymentId;
        
        cout << "Select Payment Type (0-Cash, 1-Card, 2-Bank Transfer): ";
        int typeChoice;
        cin >> typeChoice;
        payments[i].type = static_cast<PaymentType>(typeChoice);

       
        if (payments[i].type == CASH) {
            cout << "Enter Cash Receipt Number: ";
            cin >> payments[i].details.receiptNumber;
            cashCount++;
        } 
        else if (payments[i].type == CARD) {
            cout << "Enter Card Number (digits only): ";
            cin >> payments[i].details.cardNumber;
            cardCount++;
        } 
        else if (payments[i].type == BANK_TRANSFER) {
            cout << "Enter Bank Transaction ID: ";
            cin >> payments[i].details.transactionId;
            bankCount++;
        }
    }

   
    cout << "\n================ REGISTRATION SUMMARY ================\n";
    for (int i = 0; i < n; i++) {
        cout << "ID: " << payments[i].paymentId << " | Type: ";
        if (payments[i].type == CASH) {
            cout << "Cash | Receipt No: " << payments[i].details.receiptNumber << "\n";
        } else if (payments[i].type == CARD) {
            cout << "Card | Card No: " << payments[i].details.cardNumber << "\n";
        } else if (payments[i].type == BANK_TRANSFER) {
            cout << "Bank Transfer | Transaction ID: " << payments[i].details.transactionId << "\n";
        }
    }

    
    cout << "\n================ STATISTICS ================\n";
    cout << "Total Cash Payments: " << cashCount << "\n";
    cout << "Total Card Payments: " << cardCount << "\n";
    cout << "Total Bank Transfer Payments: " << bankCount << "\n";

    return 0;
}