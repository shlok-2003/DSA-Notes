#include <iostream>
#include <queue>
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

void PreOrder(Node* root) {
    if(!root)
        return;
    
    cout << root -> data << " ";
    PreOrder(root -> left);
    PreOrder(root -> right);
}

void InOrder(Node* root) {
    if(!root)
        return;
    
    InOrder(root -> left);
    cout << root -> data << " ";
    InOrder(root -> right);
}

void PostOrder(Node* root) {
    if(!root)
        return;
    
    PostOrder(root -> left);
    PostOrder(root -> right);
    cout << root -> data << " ";
}

void LevelOrder(Node* root) {
    if(!root)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0; i < size; i++)
        {
            Node* tmp = q.front();
            q.pop();

            cout << tmp -> data << " ";
            if(tmp -> left)
                q.push(tmp -> left);
            if(tmp -> right)
                q.push(tmp -> right);
        }
        cout << endl;
    }
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

    cout << endl << "PreOrder Traversal is: ";
    PreOrder(root);

    cout << endl << "InOrder Traversal is: ";
    InOrder(root);

    cout << endl << "PostOrder Traversal is: ";
    PostOrder(root);

    cout << endl << "LevelOrder Traversal is: ";
    LevelOrder(root);
}