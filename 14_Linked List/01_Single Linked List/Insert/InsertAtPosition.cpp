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

void insertAtPosition(Node* &head, int data) {
    Node* temp = new Node(data);

    Node* pos = head;
    while(pos -> data != 30)
    {
        pos = pos -> next;
    }

    temp -> next = pos -> next;
    pos -> next = temp;
}

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
    head = temp;
}

void insertAtPositionX(Node* &head, int data, int position) {
    Node* temp = head;

    int curr = 1;

    if(position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    while(curr < position - 1)  // because if we run loop till pos, then temp would be pointing to the data ahead of position
    {
        temp = temp -> next;
        curr++;
    }

    Node* newInsert = new Node(data);
    newInsert -> next = temp -> next;
    temp -> next = newInsert;
}

int main() {
    Node *n1 = new Node(10);
    Node* head = n1;
    Node* tail = n1;

    insertAtTail(tail, 20);
    insertAtTail(tail, 30);
    insertAtTail(tail, 50);
    cout << "Linked list before inserting at position X: ";
    print(head);

    // Now we want to insert data 40 after 30, to do that, we will do insertAtPosition();

    insertAtPosition(head, 40);
    cout << "Linked List after inserting after 30 is: ";
    print(head);

    //If we want to insert data at position X, then
    cout << "After inserting at postion 3: ";
    insertAtPositionX(head, 29, 3);
    print(head);

    cout << "After inserting at position 1: ";
    insertAtPositionX(head, 69, 1);
    print(head);

}