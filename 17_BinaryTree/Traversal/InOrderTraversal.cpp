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

void inOrder(Node* root) {
    if(root == NULL)
        return;

    if(root -> left)
        inOrder(root -> left);
    
    cout << root -> data << " ";

    if(root -> right)
        inOrder(root -> right);
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

    inOrder(root);
}