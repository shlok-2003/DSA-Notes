#include<bits/stdc++.h>
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

    if(head == NULL)
    {
        head = node;
        node -> next = head;
        return;
    }

    Node* temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }

    node -> next = head;
    temp -> next = node;
}

void insertAtHead(Node* &head, int data) {
    Node* node = new Node(data);

    if(head == NULL)
    {
        head = node;
        node -> next = head;
        return;
    }

    Node* temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }

    node -> next = head;
    temp -> next = node;
    head = node;
}

void insertAtPositionX(Node* &head, int data, int position) {
    Node* node = new Node(data);
    if(head == NULL)
    {
        
        head = node;
        node -> next = head;
        return;
    }
    if(position == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node* temp = head;
    int current = 1;
    while(current < position - 1)
    {
        current++;
        temp = temp -> next;
    }
    
    node -> next = temp -> next;
    temp -> next = node;
}

void print(Node* &head) {
    Node* temp = head;
    do
    {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    while(temp != head);

    cout << endl;
}

Node* getLastElement(Node* &head) {
    Node* temp = head;
    while(temp -> next != head)
    {
        temp = temp -> next;
    }

    cout << "Loop after: " << temp -> data << endl;
    return temp;
}

bool FloydCycleDetection(Node* &head) {
    if(head == NULL || head -> next == NULL)
    {
        return false;
    }

    Node* fast = head;
        Node* slow = head;

        while(fast != NULL && slow != NULL)
        {
            fast = fast -> next;
            if(fast != NULL)
            {
                fast = fast -> next;
            }

            slow = slow -> next;

            if(fast == slow)
                return true;
        }

        return false;
}

void removeCycle(Node* &head) {
    if(head == NULL || head -> next == NULL)
    {
        cout << "No cycle is detected " << endl;
        return;    
    }

    Node* fast = head;
    Node* slow = head;

    bool flag = false;          // To keep track of cycle detection
    while(fast != NULL && slow != NULL)
    {
        fast = fast -> next;
        if(fast != NULL)
        {
            fast = fast -> next;
        }
        slow = slow -> next;

        if(fast == slow)
        {
            flag = true;
            break;
        }
    }

    if(flag == false)
    {
        cout << "No cycle is detected " << endl;
        return; 
    }
    else
    {
        slow = head;
        while(slow != fast)                 
        {
            slow = slow -> next;
            fast = fast -> next;
        }

        cout << "Starting point of loop" << slow -> data << endl;
    }
}

int main(){
    Node* node = new Node(10);
    node -> next = node;        // To make circular linked list

    Node* head = node;
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);
    insertAtTail(head, 60);          
    insertAtPositionX(head, 70, 7);
    print(head);                // Initial linked list

    Node* tail = getLastElement(head);
    tail -> next = head -> next -> next -> next;            // Making a loop in Linked list
    if(FloydCycleDetection(head))       // O(1) space complexity method
    {
        cout << "It is a circular linked list" << endl;
    }
    else
    {
        cout << "It is not a circular linked list" << endl;
    }

    removeCycle(head);                                  // Fuction to remove cycle

    return 0;
}