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

void insertAtHed(Node* &head, int data) {
    Node* temp = new Node(data);

    temp -> next = head;
    head -> prev = temp;
    head = temp;
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

    insertAtHed(head, 20);
    insertAtHed(head, 30);
    insertAtHed(head, 40);
    print(head);
}