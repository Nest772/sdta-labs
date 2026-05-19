#include <iostream>
#include <string>
using namespace std;

struct Node {
    string title;
    string author;
    int year;
    Node* prev;
    Node* next;
};


void addNode(Node*& head, Node*& tail, string t, string a, int y) {
    Node* newNode = new Node{t, a, y, NULL, NULL};

    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}


void printForward(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->title << " | " << temp->author << " | " << temp->year << endl;
        temp = temp->next;
    }
}


void printBackward(Node* tail) {
    Node* temp = tail;
    while (temp) {
        cout << temp->title << " | " << temp->author << " | " << temp->year << endl;
        temp = temp->prev;
    }
}


void mergeLists(Node*& head1, Node*& tail1, Node*& head2, Node*& tail2) {
    if (!head1) {
        head1 = head2;
        tail1 = tail2;
    } else if (head2) {
        tail1->next = head2;
        head2->prev = tail1;
        tail1 = tail2;
    }
}


void deleteList(Node*& head) {
    Node* temp;
    while (head) {
        temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node *head1 = NULL, *tail1 = NULL;
    Node *head2 = NULL, *tail2 = NULL;

    int n, m;
    cout << "Enter n: ";
    cin >> n;

    
    for (int i = 0; i < n; i++) {
        string t, a;
        int y;
        cout << "Book " << i + 1 << ":\n";
        cin >> t >> a >> y;
        addNode(head1, tail1, t, a, y);
    }

    cout << "Enter m: ";
    cin >> m;

    
    for (int i = 0; i < m; i++) {
        string t, a;
        int y;
        cout << "Book " << i + 1 << ":\n";
        cin >> t >> a >> y;
        addNode(head2, tail2, t, a, y);
    }

    
    cout << "\nList 1 forward:\n";
    printForward(head1);
    cout << "List 1 backward:\n";
    printBackward(tail1);

    cout << "\nList 2 forward:\n";
    printForward(head2);
    cout << "List 2 backward:\n";
    printBackward(tail2);

    
    mergeLists(head1, tail1, head2, tail2);

    cout << "\nMerged list:\n";
    printForward(head1);

    
    deleteList(head1);

    return 0;
}