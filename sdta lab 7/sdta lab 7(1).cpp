#include <iostream>
using namespace std;

struct Node {
    int day;
    double temp;
    Node* prev;
    Node* next;
};


void add(Node*& head, Node*& tail, int day, double temp) {
    Node* newNode = new Node{day, temp, NULL, NULL};

    if (head == NULL) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void print(Node* head) {
    Node* cur = head;
    while (cur != NULL) {
        cout << "Day: " << cur->day << " Temp: " << cur->temp << endl;
        cur = cur->next;
    }
}


void merge(Node*& head1, Node*& tail1, Node* head2, Node* tail2) {
    if (head1 == NULL) {
        head1 = head2;
        tail1 = tail2;
    } else if (head2 != NULL) {
        tail1->next = head2;
        head2->prev = tail1;
        tail1 = tail2;
    }
}


void findMinMax(Node* head, double& minT, double& maxT) {
    if (head == NULL) return;

    minT = maxT = head->temp;
    Node* cur = head;

    while (cur != NULL) {
        if (cur->temp < minT) minT = cur->temp;
        if (cur->temp > maxT) maxT = cur->temp;
        cur = cur->next;
    }
}


void clear(Node*& head) {
    while (head != NULL) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head1 = NULL;
    Node* tail1 = NULL;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    
    add(head1, tail1, 1, 10.5);
    add(head1, tail1, 2, 12.3);
    add(head1, tail1, 3, 8.7);

   
    add(head2, tail2, 4, 15.2);
    add(head2, tail2, 5, 9.1);
    add(head2, tail2, 6, 18.4);

    cout << "List 1:\n";
    print(head1);

    cout << "\nList 2:\n";
    print(head2);

    
    merge(head1, tail1, head2, tail2);

    cout << "\nMerged list:\n";
    print(head1);

    
    double minT, maxT;
    findMinMax(head1, minT, maxT);

    cout << "\nMin temperature: " << minT << endl;
    cout << "Max temperature: " << maxT << endl;

    
    clear(head1);

    return 0;
}