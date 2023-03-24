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

void insertAtHead(Node* &head, int data) {
    Node* node = new Node(data);

    if(head == NULL)
    {
        head = node;
        return;
    }

    node -> next = head;
    head -> prev = node;
    head = node;
}

void deleteAtHead(Node* &head) {
    Node* temp = head;

    temp -> next -> prev = NULL;
    head = temp -> next;
    temp -> next = NULL;
    delete temp;
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

    insertAtHead(head, 20);
    insertAtHead(head, 30);
    cout << "Before deletion: ";
    print(head);

    deleteAtHead(head);
    cout << "After Deletion: ";
    print(head);
}