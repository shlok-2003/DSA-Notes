#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    private:
        string name;
        char level;
        int health;

    public:
        Hero() {
            cout << "Constructor is called" << endl;
        }

        void setName(string name) {
            this -> name = name;
        }

        void setLevel(char level) {
            this -> level = level;
        }

        void setHealth(int health) {
            this -> health = health;
        }

        string getName() {
            return name;
        }

        char getLevel() {
            return level;
        }

        int getHealth() {
            return health;
        }

        void print() {
            cout << "Name is: " << name << endl;
            cout << "Level is: " << level << endl;
            cout << "Health is: " << health << endl;
        }

        ~Hero() {
            cout << "Destructor is called" << endl;
        }
};

int main() {
    // The process of grouping data members and corresponding methods into a single unit is known as Encapsulation. It is an important 
    // part of object-oriented programming. We can create a fully encapsulated class by making all the data members private. If the data 
    // members are private, it can only be accessible within the class; no other class can access that class’s data members.

    Hero h1;
    h1.setName("Shlok");
    h1.setLevel('A');
    h1.setHealth(79);

    h1.print();
}