#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

void preOrder(Node* root) {
    if(root == NULL)
        return;

    cout << root -> data << endl;
    preOrder(root -> left);
    preOrder(root -> right);
}

Node* buildTree(Node* root) {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if(data == -1)
        return NULL;
    
    root = new Node(data);

    cout << "Enter the data to the left of " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter the data to the right of " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

int main() {
    Node* root = NULL;

    root = buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    preOrder(root);
}