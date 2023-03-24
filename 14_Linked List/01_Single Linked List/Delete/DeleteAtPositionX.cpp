#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    ~Node() {
        int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Deleted value is: " << value << endl;
    }
};

void insertAtTail(Node* &tail, int data) {
    Node* temp = new Node(data);

    tail -> next = temp;
    tail = temp;
}

void deleteAtHead(Node* &head) {
    Node* temp = head;

    head = head -> next;
    temp -> next = NULL;
    delete temp;
}

void deleteAtPositionX(Node* &head, int position) {
    Node* current = head;
    Node* prev = head;

    if(position == 1)
    {
        deleteAtHead(head);
        return;
    }

    int curr = 1;
    while(curr < position)
    {
        curr++;
        prev = current;
        current = current -> next;
    }
    prev -> next = current -> next;
    current -> next = NULL;
    delete current;

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

int main() {
    Node* NODE = new Node(10);
    Node* head = NODE;
    Node* tail = NODE;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 40);
    insertAtTail(tail, 50);
    print(head);

    // Suppose we want to delete from position 3, then
    int x;
    x = 1;      // Can be any position but it should not be null

    deleteAtPositionX(head, 3);
    print(head);
}