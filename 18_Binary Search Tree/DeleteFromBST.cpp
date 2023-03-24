#include<iostream>
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
        return;
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

Node* deleteFromBST(Node* root, int data) {
    if(!root)
        return NULL;
    
    if(root -> data == data)
    {
        if(!root -> left && !root -> right)
        {
            delete root;
            return NULL;
        }
        else if(root -> left && !root -> right)
        {
            Node* tmp = root -> left;
            delete root;
            return tmp;
        }
        else if(!root -> left && root -> right)
        {
            Node* tmp = root -> right;
            delete root;
            return tmp;
        }
        else if(root -> left && root -> right)
        {
            int mini = MinValue(root -> right);
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(data < root -> data)
        root -> left = deleteFromBST(root -> left, data);
    else 
        root -> right = deleteFromBST(root -> right, data);

    return root;
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

    root = deleteFromBST(root, 30);
}

