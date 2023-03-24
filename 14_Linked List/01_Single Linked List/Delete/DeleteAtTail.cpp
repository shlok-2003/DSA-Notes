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

void deleteAtTail(Node* &head) {
    Node* temp = head;

    while(temp -> next -> next != NULL)
    {
        temp = temp -> next;
    }        

    // temp -> next -> next = NULL;     as this is already pointing to NULL, therefore no need of this line
    delete temp -> next;
    temp -> next = NULL;
    // 1 2 3 4
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
    cout << "Before Deletion: ";
    print(head);

    // To delete at tail, we have to make DeleteAtTail();
    deleteAtTail(head);     // Head is in parameter because, not always we know the tail pointer value
    print(head);
}