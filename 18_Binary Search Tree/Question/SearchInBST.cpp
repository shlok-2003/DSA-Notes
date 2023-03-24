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

bool Search(Node* root, int data) {
    if(!root)
        return false;

    if(root -> data == data)
        return true;
    if(data < root -> data)
        return Search(root -> left, data);
    else
        return Search(root -> right, data);
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

    int target; 
    cin >> target;

    if(Search(root, target))
        cout << "Found" << endl;
    else    
        cout << "Not Found" << endl;
}