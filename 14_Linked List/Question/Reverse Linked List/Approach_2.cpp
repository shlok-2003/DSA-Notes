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
    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = node;
    temp = node;
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

void helper(Node* &head, Node* &current, Node* &prev) {
    if(current == NULL)
    {   
        head = prev;
        return;
    }

    Node* forward = current -> next;
    helper(head, forward, current);
    current -> next = prev;
}

Node* reverse(Node* &head) {
    if(head == NULL || head -> next == NULL)
        return head;
    
    Node* current = head;
    Node* prev = NULL;
    helper(head, current, prev);
    return head;
}

int main() {
    Node* node = new Node(10);
    Node* head = node;

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

    head = reverse(head);
    cout << "After: ";
    print(head);
}