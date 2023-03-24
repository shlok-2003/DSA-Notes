#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtTail(Node* &head, int data) {
    Node* node = new Node(data);

    if(head == NULL)
    {
        head = node;
        node -> next = head;
        return;
    }

    Node* temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }

    node -> next = head;
    temp -> next = node;
}

void insertAtHead(Node* &head, int data) {
    Node* node = new Node(data);

    if(head == NULL)
    {
        head = node;
        node -> next = head;
        return;
    }

    Node* temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }

    node -> next = head;
    temp -> next = node;
    head = node;
}

void insertAtPositionX(Node* &head, int data, int position) {
    Node* node = new Node(data);
    if(head == NULL)
    {
        
        head = node;
        node -> next = head;
        return;
    }
    if(position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int current = 1;
    while(current < position - 1)
    {
        current++;
        temp = temp -> next;
    }
    
    node -> next = temp -> next;
    temp -> next = node;
}

void print(Node* &head) {
    Node* temp = head;
    do
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    while(temp != head);

    cout << endl;
}

int main(){
    Node* node = new Node(10);
    node -> next = node;        // To make circular linked list

    Node* head = node;
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    cout << "Before: ";
    print(head);                // Existing linked list

    insertAtPositionX(head, 70, 7);
    print(head);
    return 0;
}