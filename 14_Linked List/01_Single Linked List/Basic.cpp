#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

int main() {
    Node* newNode = new Node(10);
    cout << newNode -> data << endl;
    cout << newNode -> next << endl;
}