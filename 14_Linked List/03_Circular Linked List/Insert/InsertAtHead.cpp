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
    insertAtHead(head, 20);
    insertAtHead(head, 30);
    insertAtHead(head, 40);
    print(head);
    return 0;
}