#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

struct Node {
    int code;
    char name[50];
    double price;
    Node* left;
    Node* right;
};

Node* createNode(int code, const char* name, double price) {
    Node* newNode = new Node;
    newNode->code = code;
    strcpy(newNode->name, name);
    newNode->price = price;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int code, const char* name, double price) {
    if (root == NULL) return createNode(code, name, price);

    if (code < root->code)
        root->left = insert(root->left, code, name, price);
    else
        root->right = insert(root->right, code, name, price);

    return root;
}


void sumCount(Node* root, double& sum, int& count) {
    if (!root) return;
    sum += root->price;
    count++;
    sumCount(root->left, sum, count);
    sumCount(root->right, sum, count);
}


void countLevels(Node* root, int level, int levels[]) {
    if (!root) return;
    levels[level]++;
    countLevels(root->left, level + 1, levels);
    countLevels(root->right, level + 1, levels);
}


Node* find(Node* root, int code) {
    if (!root) return NULL;
    if (root->code == code) return root;
    if (code < root->code) return find(root->left, code);
    return find(root->right, code);
}


void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
   ifstream file("data.txt");

    Node* root = NULL;

    int code;
    char name[50];
    double price;

    while (file >> code >> name >> price) {
        root = insert(root, code, name, price);
    }

    file.close();

    double sum = 0;
    int count = 0;
    sumCount(root, sum, count);

    cout << "countAverage price: " << (count ? sum / count : 0) << endl;

    int levels[100] = {0};
    countLevels(root, 0, levels);

    cout << "Number of nodes per level:\n";
    for (int i = 0; i < 100; i++) {
        if (levels[i] == 0) break;
        cout << "Level " << i << ": " << levels[i] << endl;
    }

    int key;
    cout << "Enter code for search: ";
    cin >> key;

    Node* found = find(root, key);
    if (found) {
        cout << "Found: " << found->name << endl;

        deleteTree(found->left);
        deleteTree(found->right);
        found->left = found->right = NULL;
    } else {
        cout << "Not found\n";
    }

    deleteTree(root);

    return 0;
}