#include<iostream>
using namespace std;

class Human{
    public:
        void sayHello() {
            cout << "Hello" << endl;
        }

        void sayHello(string name) {
            cout << "Hello " << name << endl;
        }

        void sayHello(char n) {
            cout << "Say " << n << endl;
        }
};

int main() {
    // In polymorphism, one function could have multiple forms. 
    // Polymorphism can be of two type: Compile time and Run time

    // Compile Time Polymorphism, there are two types: Function overloading and operator overloading

    // Example of function overloading
    Human h1;
    h1.sayHello();          

    
}