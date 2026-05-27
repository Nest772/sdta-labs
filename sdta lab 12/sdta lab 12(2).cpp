#include <iostream>
#include <string>

using namespace std;

struct Car {
    string brand;
    int manufactureYear;
    double mileage;
};

struct Node {
    Car data;
    Node* next;
};


Node* createNode() {
    Node* newNode = new Node();
    cout << "Enter brand/name: "; cin.ignore(); getline(cin, newNode->data.brand);
    cout << "Enter manufacture year: "; cin >> newNode->data.manufactureYear;
    cout << "Enter mileage (km): "; cin >> newNode->data.mileage;
    newNode->next = nullptr;
    return newNode;
}


void insertFirstElement(Node*& head) {
    if (head != nullptr) {
        cout << "List already exists. Overwriting list root element.\n";
    }
    head = createNode();
}


void insertAtBeginning(Node*& head) {
    Node* newNode = createNode();
    newNode->next = head;
    head = newNode;
}


void insertAtEnd(Node*& head) {
    Node* newNode = createNode();
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertAfterElement(Node* head) {
    if (head == nullptr) { cout << "List is empty.\n"; return; }
    string targetName;
    cout << "Enter the car brand name to insert AFTER: "; cin.ignore(); getline(cin, targetName);
    
    Node* temp = head;
    while (temp != nullptr && temp->data.brand != targetName) {
        temp = temp->next;
    }
    if (temp != nullptr) {
        Node* newNode = createNode();
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        cout << "Specified car brand not found!\n";
    }
}


void insertBeforeElement(Node*& head) {
    if (head == nullptr) { cout << "List is empty.\n"; return; }
    string targetName;
    cout << "Enter the car brand name to insert BEFORE: "; cin.ignore(); getline(cin, targetName);

    if (head->data.brand == targetName) {
        insertAtBeginning(head);
        return;
    }

    Node* prev = nullptr;
    Node* curr = head;
    while (curr != nullptr && curr->data.brand != targetName) {
        prev = curr;
        curr = curr->next;
    }

    if (curr != nullptr) {
        Node* newNode = createNode();
        newNode->next = curr;
        prev->next = newNode;
    } else {
        cout << "Specified car brand not found!\n";
    }
}


void searchNode(Node* head) {
    if (head == nullptr) { cout << "List is empty.\n"; return; }
    string targetName;
    cout << "Enter target car brand name: "; cin.ignore(); getline(cin, targetName);

    Node* temp = head;
    while (temp != nullptr) {
        if (temp->data.brand == targetName) {
            cout << "Car with name '" << targetName << "' is in the list.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Car with name '" << targetName << "' is not in the list.\n";
}


void deleteByYearThreshold(Node*& head) {
    if (head == nullptr) { cout << "List is empty.\n"; return; }
    int limitYear;
    cout << "Delete cars manufactured before what year? "; cin >> limitYear;

    while (head != nullptr && head->data.manufactureYear < limitYear) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    Node* curr = head;
    while (curr != nullptr && curr->next != nullptr) {
        if (curr->next->data.manufactureYear < limitYear) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
        } else {
            curr = curr->next;
        }
    }
    cout << "Deletions handled completed.\n";
}


void viewList(Node* head) {
    if (head == nullptr) {
        cout << "The list is currently empty.\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << " -> [" << temp->data.brand << " | Year: " << temp->data.manufactureYear << " | " << temp->data.mileage << " km]";
        temp = temp->next;
    }
    cout << "\n";
}

int main() {
    Node* head = nullptr;
    int option;

    while (true) {
        cout << "\n------ MENU FOR WORKING WITH THE LIST ------\n";
        cout << "1. Input first element into the list\n";
        cout << "2. Insert element at the beginning of the list\n";
        cout << "3. Insert element at the end of the list\n";
        cout << "4. Insert element after a specified element\n";
        cout << "5. Insert element before a specified element\n";
        cout << "6. Search for required node\n";
        cout << "7. Delete node smaller than specified year\n";
        cout << "8. View list\n";
        cout << "9. Exit\n";
        cout << "Enter operation number: ";
        cin >> option;

        if (option == 9) break;

        switch (option) {
            case 1: insertFirstElement(head); break;
            case 2: insertAtBeginning(head); break;
            case 3: insertAtEnd(head); break;
            case 4: insertAfterElement(head); break;
            case 5: insertBeforeElement(head); break;
            case 6: searchNode(head); break;
            case 7: deleteByYearThreshold(head); break;
            case 8: viewList(head); break;
            default: cout << "Invalid choice\n";
        }
    }
    return 0;
}