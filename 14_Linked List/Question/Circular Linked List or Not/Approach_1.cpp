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

void insertAtTail(Node* &head, int data) {
    Node* node = new Node(data);
    
    Node* temp = head;
    if(temp -> next == head)
    {
        temp -> next = node;
        node -> next = head;
        return;
    }

    while(temp -> next != head)
    {
        temp = temp -> next;
    }

    temp -> next = node;
    node -> next = head;
}

void print(Node* &head) {
    Node* temp = head;
    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    while(temp != head);

    cout << endl;
}

bool isCircular(Node* head){
    if(head == NULL || head -> next == head)
        return true; 
    else if(head -> next == NULL)
        return false;
    
    Node* temp = head -> next;
    
    while(temp != head && temp != NULL)
    {        
        temp = temp -> next;
    }
    
    if(temp == head)
        return true;
    else
        return false;
}

int main() {
    Node* node = new Node(10);
    Node* head = node;
    head -> next = node;

    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);
    insertAtTail(head, 70);
    insertAtTail(head, 80);
    insertAtTail(head, 90);
    cout << "Before: ";
    print(head);

    if(isCircular(head))
        cout << "YES" << endl;
    else   
        cout << "NO" << endl;
}