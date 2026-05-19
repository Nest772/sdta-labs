#include <iostream>
#include <string>
using namespace std;

struct Team {
    string name;
    string city;
    int points;
};

struct Node {
    Team data;
    Node* next;
};


void enqueue(Node*& front, Node*& rear, Team t) {
    Node* temp = new Node;
    temp->data = t;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}


bool dequeue(Node*& front, Node*& rear, Team& t) {
    if (front == NULL) return false;

    Node* temp = front;
    t = temp->data;
    front = front->next;

    if (front == NULL) rear = NULL;

    delete temp;
    return true;
}


bool cityExists(Node* front, string city) {
    while (front != NULL) {
        if (front->data.city == city) return true;
        front = front->next;
    }
    return false;
}


void printQueue(Node* front) {
    while (front != NULL) {
        cout << front->data.name << " (" 
             << front->data.city << ") - "
             << front->data.points << endl;
        front = front->next;
    }
}

int main() {
    Node *front = NULL, *rear = NULL;
    Node *tempFront = NULL, *tempRear = NULL;

    Node *uniqueFront = NULL, *uniqueRear = NULL;
    Node *filteredFront = NULL, *filteredRear = NULL;

    int n;
    cout << "Enter number of teams: ";
    cin >> n;

   
    for (int i = 0; i < n; i++) {
        Team t;
        cout << "\nTeam name: ";
        cin >> t.name;
        cout << "City: ";
        cin >> t.city;
        cout << "Points: ";
        cin >> t.points;

        enqueue(front, rear, t);
    }

    int limit;
    cout << "\nEnter points limit: ";
    cin >> limit;

    Team leader, outsider, t;
    bool first = true;

    
    while (dequeue(front, rear, t)) {

        
        enqueue(tempFront, tempRear, t);

        
        if (first) {
            leader = outsider = t;
            first = false;
        } else {
            if (t.points > leader.points) leader = t;
            if (t.points < outsider.points) outsider = t;
        }

        
        if (!cityExists(uniqueFront, t.city)) {
            enqueue(uniqueFront, uniqueRear, t);
        }

       
        if (t.points > limit) {
            enqueue(filteredFront, filteredRear, t);
        }
    }

    
    while (dequeue(tempFront, tempRear, t)) {
        enqueue(front, rear, t);
    }

    
    cout << "\nLeader:\n";
    cout << leader.name << " (" << leader.city << ") - " << leader.points << endl;

    cout << "\nOutsider:\n";
    cout << outsider.name << " (" << outsider.city << ") - " << outsider.points << endl;

    cout << "\nUnique cities queue:\n";
    printQueue(uniqueFront);

    cout << "\nTeams with points > " << limit << ":\n";
    printQueue(filteredFront);

    cout << "\nRestored original queue:\n";
    printQueue(front);

    return 0;
}