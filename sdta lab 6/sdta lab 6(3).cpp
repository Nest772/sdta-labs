#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

struct Node {
    int data;
    Node* next;
};


void enqueue(Node*& front, Node*& rear, int value) {
    Node* temp = new Node;
    temp->data = value;
    temp->next = NULL;

    if (rear == NULL) {
        front = rear = temp;
    } else {
        rear->next = temp;
        rear = temp;
    }
}


int dequeue(Node*& front, Node*& rear) {
    if (front == NULL) return -1;

    Node* temp = front;
    int value = temp->data;

    front = front->next;
    if (front == NULL) rear = NULL;

    delete temp;
    return value;
}


bool isEmpty(Node* front) {
    return front == NULL;
}


void printQueue(Node* front) {
    while (front != NULL) {
        cout << front->data << " ";
        front = front->next;
    }
    cout << endl;
}

int main() {
    srand(time(0));

    Node *q1_front = NULL, *q1_rear = NULL;
    Node *q2_front = NULL, *q2_rear = NULL;

    int n = 10; 


    for (int i = 0; i < n; i++) {
        int num = rand() % 50 + 1; 
        enqueue(q1_front, q1_rear, num);
    }

    cout << "Original queue: ";
    printQueue(q1_front);

    
    while (!isEmpty(q1_front)) {
        int x = dequeue(q1_front, q1_rear);

        if (x % 2 == 0) {
            enqueue(q2_front, q2_rear, x);
            enqueue(q2_front, q2_rear, 100);
        }
    }

    cout << "New queue: ";
    printQueue(q2_front);

    
    double product = 1.0;
    int count = 0;

    Node* temp = q2_front;
    while (temp != NULL) {
        product *= temp->data;
        count++;
        temp = temp->next;
    }

    if (count > 0) {
        double geom = pow(product, 1.0 / count);
        cout << "Geometric mean = " << geom << endl;
    } else {
        cout << "Queue is empty!" << endl;
    }

    
    while (!isEmpty(q2_front)) {
        dequeue(q2_front, q2_rear);
    }

    return 0;
}