#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* prev;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> prev = NULL;
        this -> next = NULL;
    }
};

void insertAtTail(Node* head, int data) {
    Node* temp = new Node(data);

    Node* tail = head;
    while(tail -> next!= NULL)
    {
        tail = tail -> next;
    }

    tail -> next = temp;
    temp -> prev = tail;
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
    Node* node = new Node(10);
    Node* head = node;

    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    print(head);
}