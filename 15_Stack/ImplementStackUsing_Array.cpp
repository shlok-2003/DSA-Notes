#include <iostream>
using namespace std;

class Stack{
    private:
        int* arr;
        int size;
        int top;
    
    public:
        Stack(int size) {
            this -> size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int x) {
            if(top >= size)
            {
                cout << "Stack is overflow" << endl;
                return;
            }

            top += 1;
            arr[top] = x;
        }

        void pop() {
            if(top < 0)
            {
                cout << "Stack is underflow" << endl;
                return;
            }

            top--;
        }

        int peek() {
            if(top >= 0 && top < size)
            {
                return arr[top];
            }
            else
            {
                cout << "Stack is empty" << endl;
            }
        }

        void display() {
            if(top < 0)
            {
                cout << "Stack is empty" << endl;
                return;
            }

            int temp = top;
            while(temp >= 0)
            {
                cout << arr[temp] << " ";
                temp--;
            }
            cout << endl;
        }

        bool isEmpty() {
            return (top < 0);
        } 
};

int main() {
    Stack s(5);

    s.push(10);
    s.push(15);
    s.push(20);

    cout << s.peek() << endl;

    s.pop();
    cout << s.peek() << endl;

    cout << "The elements are: ";
    s.display();
}