#include <iostream>
#include <cmath>
using namespace std;

class Queue{
    private:
        int front, rear, size;
        int* arr;
    
    public:
        Queue() {
            size = 1000005;
            front = rear = 0;
            arr = new int[size];
        }

        void push(int x) {
            if(rear == size - 1)
                cout << "Queue Overflow" << endl;
            else
            {
                arr[rear] = x;
                rear++;
            }
        }

        int pop() {
            if(front == rear)
                return -1;
            else
            {
                int ans = arr[front];
                front++;
                if(front == rear)
                {
                    front = rear = 0;
                }
                return ans;
            }
        }

        bool isEmpty() {
            if(front == rear)
                return true;
            else    
                return false;
        }

        int Front() {
            return arr[front];
        }

        int Rear() {
            return arr[rear]; 
        }

        void display() {
            for(int i = front; i < rear; i++) 
            {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
};

int main() {
    Queue q;

    q.push(1);
    q.push(3);
    q.push(6);

    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;
    cout << q.pop() << endl;

    q.push(4);
    q.push(6);
    q.push(10);
    q.display();
}