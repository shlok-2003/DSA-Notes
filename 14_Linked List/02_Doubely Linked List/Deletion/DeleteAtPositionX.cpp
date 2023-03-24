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

    ~Node() {
        int value = this -> data;
        if(this -> next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "Deleted item is: " << value << endl;
    }
};

void insertAtTail(Node* &head, int data) {
    Node* node = new Node(data);
    Node* temp = head;

    if(head == NULL)
    {
        head -> next = temp;
        temp -> prev = head;
        return;
    }

    while(temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = node;
    node -> prev = temp;
    temp = node;
}

void deleteAtHead(Node* &head) {
    Node* temp = head;

    if(temp -> next == NULL)        // i.e only one element in linked list
    {
        head = NULL;
        delete temp;
        return;
    }

    temp -> next -> prev = NULL;
    head = temp -> next;
    temp -> next = NULL;
    delete temp;
}

void deleteAtPositionX(Node* &head, int position) {
    if(head == NULL)
    {
        cout << "Cannot delete" << endl;
        return;
    }
    
    if(position == 1)
    {
        deleteAtHead(head);
        return;
    }

    Node* current = head;
    Node* previous = head;

    int count = 1;
    while(count < position)
    {
        count++;
        previous = current;
        current = current -> next;
    }

    current -> prev = NULL;
    previous -> next = current -> next;
    current -> next -> prev = previous;
    current -> next = NULL;
    delete current;
}

void deleteAtPosition(Node* &head, int val) {
    if(head == NULL)
    {
        cout << "Cannot delete" << endl;
        return;
    }
    else if(head -> data == val)
    {
        deleteAtHead(head);
        return;
    }

    Node* current = head;
    Node* previous = head;

    while(current -> data != val)
    {
        previous = current;
        current = current -> next;
    }

    current -> prev = NULL;
    previous -> next = current -> next;
    if(current -> next != NULL)
    {
        current -> next -> prev = NULL;
        current -> next = NULL;
    }
    delete current;
}

void print(Node* &head) {
    Node* temp = head;

    if(temp == NULL)
    {
        cout << "No element" << endl;
        return;
    }

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
    insertAtTail(head, 60);
    cout << "Before Deletion: ";
    print(head);

    deleteAtPositionX(head, 2);
    cout << "After deletion: "; 
    print(head);

    deleteAtPosition(head, 60);     // To delete a particular value
    print(head);
    cout << "Head: " << head -> data << endl;
} 