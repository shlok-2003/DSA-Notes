#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        data = d;
        left = right = NULL;
    }
};

Node* createBST(Node* root, int data) {
    if(!root)
    {
        root = new Node(data);
        return root;
    }

    if(data <= root -> data)
        root -> left = createBST(root -> left, data);
    else
        root -> right = createBST(root -> right, data);
    return root;
}

int MinValue(Node* root) {
    if(!root)
        return -1;

    while(root -> left)
        root = root -> left;

    return root -> data;
}

int MaxValue(Node* root) {
    if(!root)
        return -1;

    while(root -> right)
        root = root -> right;

    return root -> data;
}

int main() {
    Node* root = NULL;

    int data;
    cout << "Enter the data: ";
    cin >> data;

    while(data != -1)
    {
        root = createBST(root, data);
        cin >> data;
    }

    cout << "Min Value is: " << MinValue(root) << endl;
    cout << "Max Value is: " << MaxValue(root) << endl;
}