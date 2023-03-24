#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};

Node* binaryTree(Node* root) {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if(data == -1)
        return NULL;
    
    root = new Node(data);

    cout << "Enter the data to the left of " << data << endl;
    root -> left = binaryTree(root -> left);
    cout << "Enter the data to the right of " << data << endl;
    root -> right = binaryTree(root -> right);

    return root;
}

void LevelOrderTraversal(Node* root) {
    queue<Node*> q;

    q.push(root);
    q.push(NULL);

    while(!q.empty())
    {
        Node* tmp = q.front();
        q.pop();

        if(tmp == NULL)
        {
            cout << endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << tmp -> data << " ";

            if(tmp -> left != NULL)
            {
                q.push(tmp -> left);
            }

            if(tmp -> right != NULL)
            {
                q.push(tmp -> right);
            }
        }
    }
}

int main() {
    struct Node* root = NULL;

    root = binaryTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    LevelOrderTraversal(root);
}