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

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);
    
    tail -> next = temp;
    tail = temp;
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

int main() {
    Node* n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 20);
    print(head);

    insertAtTail(tail, 30);
    print(head);

    insertAtTail(tail, 40);
    print(head);
}