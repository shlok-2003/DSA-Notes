#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int data;
    Node* left,* right;

    Node(int data) {
        this -> data = data;
        left = right = NULL;
    }
};

// void LevelOrder(Node* root) {
//     queue<Node*> q;
//     q.push(root);

//     q.push(NULL);
//     while(!q.empty())
//     {
//         Node* tmp = q.front();
//         q.pop();

//         if(tmp == NULL)
//         {
//             cout << endl;
//             if(!q.empty())
//             {
//                 q.push(NULL);
//             }
//         }
//         else{
//             cout << tmp -> data << " ";
//             if(tmp -> left)
//                 q.push(tmp -> left);

//             if(tmp -> right)
//                 q.push(tmp -> right);
//         }
//     }

// }

void LevelOrder(Node* root) {
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

void buildFromLevel(Node* &root) {
    queue<Node*> q;
    int dataRoot;
    // cout << "Enter the data of root: " << endl;
    cin >> dataRoot;
    
    root = new Node(dataRoot);
    q.push(root);

    while(!q.empty())
    {
        Node* tmp = q.front();
        q.pop();

        // cout << "Enter the data to left of " << root -> data << endl;
        int LeftData;
        cin >> LeftData;
        if(LeftData != -1)
        {
            tmp -> left = new Node(LeftData);
            q.push(tmp -> left);
        }

        // cout << "Enter the data to right of " << root -> data << endl;
        int RightData;
        cin >> RightData;
        if(RightData != -1)
        {
            tmp -> right = new Node(RightData);
            q.push(tmp -> right);
        }
    }

}

int main() {
    Node* root = NULL;

    buildFromLevel(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    LevelOrder(root);
}