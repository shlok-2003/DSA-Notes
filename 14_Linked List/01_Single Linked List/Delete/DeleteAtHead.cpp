#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this -> data = data;
        this -> next = NULL;
    }

    //Destructor
    ~Node() {
        int value = this -> data;
        if( this -> next != NULL)
        {
            delete next;
            next = NULL;
        }

        cout << "deleted value is: " << value << endl;
    }
};

void insertAfterHead(Node* &head, int data) {
    Node* temp = new Node(data);
    head -> next = temp;
}

void deleteAtHead(Node* &head) {
    Node* temp = head;
    head = head -> next;
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
    Node* NODE = new Node(10);
    Node* head = NODE;

    insertAfterHead(head, 20);
    cout << "Before deletion: ";
    print(head);

    // To delete from head, we make DeleteAtHead();
    deleteAtHead(head);
    cout << "After Deletion: ";
    print(head);
}