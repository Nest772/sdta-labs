#include <iostream>
#include <string>
using namespace std;

struct Music {
    string carrier;   
    string title;     
    string artist;    
    int duration;     
    int count;        
    double price;     
};

struct Node {
    Music data;
    Node* next;
};

struct Stack {
    Node* top;
};


void init(Stack &s) {
    s.top = nullptr;
}


bool isEmpty(Stack s) {
    return s.top == nullptr;
}


void push(Stack &s, Music m) {
    Node* newNode = new Node;
    newNode->data = m;
    newNode->next = s.top;
    s.top = newNode;
}


Music pop(Stack &s) {
    if (isEmpty(s)) {
        cout << "Stack empty\n";
        exit(1);
    }
    Node* temp = s.top;
    Music m = temp->data;
    s.top = temp->next;
    delete temp;
    return m;
}


int calculateTotalDurationByArtist(Stack s, string artist) {
    int total = 0;
    Node* current = s.top;
    while (current != nullptr) {
        if (current->data.artist == artist) {
            total += current->data.duration;
        }
        current = current->next;
    }
    return total;
}


Stack filterCassettes(Stack s) {
    Stack result;
    init(result);

    Node* current = s.top;
    while (current != nullptr) {
        if (current->data.carrier == "casette") {
            push(result, current->data);
        }
        current = current->next;
    }

    return result;
}


double calculateAveragePrice(Stack s) {
    if (isEmpty(s)) return 0;

    double sum = 0;
    int count = 0;
    Node* current = s.top;

    while (current != nullptr) {
        sum += current->data.price;
        count++;
        current = current->next;
    }

    return sum / count;
}


int main() {
    Stack s;
    init(s);

    
    push(s, {"gramophone", "Album1", "Artist1", 40, 10, 200});
    push(s, {"casette", "Album2", "Artist2", 50, 12, 150});
    push(s, {"laser disk", "Album3", "Artist1", 60, 8, 300});
    push(s, {"casette", "Album4", "Artist3", 30, 6, 120});

    string artist;
    cout << "enter performer: ";
    cin >> artist;

    int total = calculateTotalDurationByArtist(s, artist);
    cout << "Total time: " << total << " min\n";

    Stack cassetteStack = filterCassettes(s);

    double avg = calculateAveragePrice(cassetteStack);
    cout << "Average price of cassette: " << avg << endl;

    return 0;
}