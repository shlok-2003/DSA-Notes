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

Node* middle(Node* &head) {
    if(head == NULL || head -> next == NULL)    
        return head;

    Node* fast = head -> next;
    Node* slow = head;
    while(fast != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }

        slow = slow -> next;
    }

    return slow;
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

    cout << middle(head) -> data << endl;
}