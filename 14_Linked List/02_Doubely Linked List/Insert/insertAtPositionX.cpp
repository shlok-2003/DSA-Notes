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

void insertAtTail(Node* &head, Node* &tail, int data) {      // To initialize tha data
    Node* node = new Node(data);
    if(head == NULL)
    {
        head = node;
        tail = node;
    }
    else
    {
        tail -> next = node;
        node -> prev = tail;
        tail = node;
    }
}

void insertAtHead(Node* &head, int data) {
    Node* node = new Node(data);

    if(head == NULL)
    {
        head = node;
    }
    else
    {
        node -> next = head;
        head -> prev = node;
        head = node;
    }

}

void insertAtTailX(Node* &head, int data) {
    Node* node = new Node(data);

    if(head == NULL)
    {  
        head = node;
    }
    else
    {
        Node* tail = head;
        while(tail -> next != NULL)
        {
            tail = tail -> next;
        }

        tail -> next = node;
        node -> prev = tail;
        tail = node;
    }
}

void insertAtPositionX(Node* &head, int data, int position) {
    if(head == NULL)
    {
        Node* newNode = new Node(data);
        head = newNode;
        return;
    }
    
    if(position == 1)
    {
        insertAtHead(head, data);
        return;
    }
    else if(position == 5)          // i.e size of linked list
    {
        insertAtTailX(head, data);
        return;
    }

    Node* node = new Node(data);
    Node* temp = head;

    int curr = 1;

    while(curr < position - 1)
    {
        curr++;
        temp = temp -> next;
    }

    node -> next = temp -> next;
    temp -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
    // 10 20 30 40 50
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

void insertAtPosition(Node* &head, int data, int val) {
    Node* node = new Node(data);
    Node* temp = head;

    if(head == NULL)
    {
        head = node;
        return;
    }

    while(temp -> next -> data != val)
    {
        temp = temp -> next;
    }

    node -> next = temp -> next;
    temp -> next -> prev = node;
    temp -> next = node;
    node -> prev = temp;
}

int main() {
    Node* node = new Node(10);
    Node* head = node;
    Node* tail = node;

    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 40);
    insertAtTail(head, tail, 50);
    print(head);

    insertAtPositionX(head, 60, 3);              // Insert Node at position 3
    print(head);

    insertAtPosition(head, 70, 40);             // If you want to insert before 40
    print(head);
}