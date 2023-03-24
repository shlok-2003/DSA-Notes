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

void print(Node* &head) {
    Node* temp = head;

    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }

    cout << endl;
}

void getLength(Node* &head) {
    Node* temp = head;

    int l = 0;

    while(temp != NULL)
    {
        l++;
        temp = temp -> next;
    }

    cout << l << endl;
}

int main() {
    Node* node = new Node(10);
    Node* head = node;

    print(head);
    getLength(head);
}