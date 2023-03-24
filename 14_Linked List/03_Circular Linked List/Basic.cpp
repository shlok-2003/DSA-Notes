#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        if(this -> next != NULL)
        {
            this -> next = NULL;
        }
        cout << "Deleted element is: " << value << endl;
    }
};

int main() {
    Node* node = new Node(10);
    node -> next = node;

    cout << node -> data << endl;
    cout << "Node is pointing to itself: ";
    cout << node -> next -> data << endl;

}