#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};


Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


Node* insert(Node* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}


bool search(Node* root, int key) {
    if (root == NULL) return false;
    if (root->data == key) return true;
    if (key < root->data) return search(root->left, key);
    return search(root->right, key);
}


void splitTree(Node* root, Node*& evenTree, Node*& oddTree) {
    if (root == NULL) return;

    if (root->data % 2 == 0)
        evenTree = insert(evenTree, root->data);
    else
        oddTree = insert(oddTree, root->data);

    splitTree(root->left, evenTree, oddTree);
    splitTree(root->right, evenTree, oddTree);
}


int depth(Node* root) {
    if (root == NULL) return 0;
    int left = depth(root->left);
    int right = depth(root->right);
    return 1 + (left > right ? left : right);
}


void deleteTree(Node* root) {
    if (root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = NULL;
    int n, choice;

    cout << "Number of nodes: ";
    cin >> n;

    cout << "1 - manually, 2 - generate: ";
    cin >> choice;

    if (choice == 1) {
        int x;
        for (int i = 0; i < n; i++) {
            cin >> x;
            root = insert(root, x);
        }
    } else {
        int a, b;
        cout << "Enter limits [a, b]: ";
        cin >> a >> b;

        if (n > (b - a + 1)) {
            cout << "Error\n";
            return 0;
        }

        srand(time(0));
        for (int i = 0; i < n; i++) {
            int x = rand() % (b - a + 1) + a;
            root = insert(root, x);
        }
    }

    int key;
    cout << "Search: ";
    cin >> key;
    cout << (search(root, key) ? "Is in tree\n" : "not\n");

    Node* evenTree = NULL;
    Node* oddTree = NULL;

    splitTree(root, evenTree, oddTree);

    cout << "deepness of paired tree: " << depth(evenTree) << endl;
    cout << "deepness of odd tree: " << depth(oddTree) << endl;

    deleteTree(root);
    deleteTree(evenTree);
    deleteTree(oddTree);

    return 0;
}