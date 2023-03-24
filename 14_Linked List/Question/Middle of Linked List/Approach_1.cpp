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

int getLength(Node* head) {
    int count = 0;
    while(head != NULL)
    {
        count++;
        head = head -> next;
    }
    return count;
}

void middle(Node* head, int length) {
    if(length == 1 || length == 0)
    {
        cout << head -> data << endl;
        return;
    }
    
    int current = 0;
    while(current < length)
    {
        current++;
        head = head -> next;
    }

    cout << head -> data << endl;
    
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
    insertAtTail(head, 100);
    cout << "Before: ";
    print(head);

    int length = getLength(head);
    length /= 2;
    middle(head, length);
}