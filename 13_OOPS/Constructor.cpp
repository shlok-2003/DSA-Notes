#include<iostream>
using namespace std;

class Vehicle{
    // By default when we initiate a class, a default constructor is made for it.
    // This default constructor is created when object is invoked
    // It has not return type and it has not input/output parameter.

    // Now we create our own constructor. Making it in public domain
    private:
        int health;
        char level;

    public: 
        Vehicle () {
            cout << "Constructor is called" << endl;
        }
    // Once you create a constructor, then the inbuilt constructor is deleted

        Vehicle(int health) {
            // This is the keyword which points at the entry level data member. It points at the data member. To show that 
            // "this" is the pointer, lemme cout the address for both the entity, i.e for constructor and object below.
            cout << "Constructor address is " << this << endl;
            this -> health = health;
        }

        Vehicle(int health, char level) {
            this -> health = health;
            this -> level = level;
        }

        int setHealth(int h) {
            health = h;
        }

        char setLevel(char c) {
            level = c;
        }

        int getHealth() {
            return health;
        }

        char getLevel() {
            return level;
        }
};

class Hero{
    private:
        string name;
        int power;

    public:
        Hero(string name, int power) {
            this -> name = name;
            this -> power = power;
        }

        // Copy Constructor
        /*
            Hero(Hero &another) {                       // By this the default copy constructor is deleted 
                this -> health = another.health;
                this -> power = another.power;
            }
        */

        string setName(string n) {
            name = n;
        }

        int setPower(int p) {
            power = p;
        }

        string getName() {
            return name;
        }

        int getPower() {
            return power;
        }

        // Print function
        void print() {
            cout << this -> name << endl;
            cout << this -> power << endl;
            return;
        }
};

int main() {
    Vehicle v1;         // This is showing error as the parameterized constructor is created and the constructor with no parameter is
                        // Commented. If you uncomment that constructor, the error is removed.

    Vehicle v2(70);
    cout << "Object Address is " << &v2 << endl;

    Vehicle v3(100, 'A');
    cout << v3.getHealth() << endl;
    cout << v3.getLevel() << endl;

    Vehicle *v4 = new Vehicle(50, 'C');             // Dynamic allocation of parameterized object

    // Now we will be seeing copy in constructors
    Hero h1("Shlok", 100);
    h1.print();                                     // To print the value of h1 data members

    // Now we would be copying to h2 object
    Hero h2(h1);
    cout << h2.getName() << endl;                   // Parameter values will also be copied to new constructor
    cout << h2.getPower() << endl;

    /* This copying parameters could have been done in thi way also
        Hero h2("ABC", 0)       // Any default value is stored

        h2.name = h1.name
        h2.power = h1.power
    */ 

}