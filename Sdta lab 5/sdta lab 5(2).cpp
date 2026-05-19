#include <iostream>
#include <string>
using namespace std;

struct Node {
    string city;
    double distance;
    Node* next;
};

void addEnd(Node*& head, string city, double dist) {
    Node* newNode = new Node{city, dist, NULL};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}


void findFarthest(Node* head) {
    Node *max1 = head, *max2 = head;

    while (head) {
        if (head->distance > max1->distance) {
            max2 = max1;
            max1 = head;
        } else if (head->distance > max2->distance && head != max1) {
            max2 = head;
        }
        head = head->next;
    }

    cout << "Farthest cities: " << max1->city << ", " << max2->city << endl;
}

void clearList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = NULL;

    addEnd(head, "Lviv", 540);
    addEnd(head, "Kharkiv", 480);
    addEnd(head, "Odesa", 475);

    findFarthest(head);

    addEnd(head, "Warsaw", 690);

    clearList(head);
    
    return 0;
}