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

void insertAtHead(Node* &head, int data) {
    Node* temp = new Node(data);
    temp -> next = head;
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
    Node* n1 = new Node(10);
    Node* head = n1;
    print(head);

    insertAtHead(head, 20);
    insertAtHead(head, 30);
    print(head);
}