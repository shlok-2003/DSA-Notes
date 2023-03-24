#include <bits/stdc++.h>
using namespace std;

class Queue{
    private:
        int front;
        int rear;
        int size;
        int* arr;

    public:
        Queue(int size) {
            this -> size = size;
            front = rear = -1;
            arr = new int[size];
        }

        void push(int data) {
            if((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
                cout << "Queue is Full" << endl;
            else if(front == -1)
            {
                front = rear = 0;
                arr[rear] = data;
            }
            else if(front != 0 && rear == size - 1)
            {
                rear = 0;
                arr[rear] = data;
            }
            else
            {
                rear++;
                arr[rear] = data;
            }
        }

        int pop() {
            if(front == -1)
            {
                cout << "Queue is empty" << endl;
                return -1;
            }

            int ans = arr[front];
            if(front == rear)
                front = rear = -1;
            else if(front == size - 1)
                front = 0;
            else    
                front++;
            
            return ans;
        }

        bool isempty() {
            return front == -1;
        }

        void display() {
            int i = front, j = rear;

            for(i; i <= j; i++)
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q(5);

    q.push(10);
    q.push(1);
    q.push(5);

    cout << q.pop() << endl;
    q.push(3);
    q.push(6);
    q.display();

    
    // 10 2 5 3 6
}