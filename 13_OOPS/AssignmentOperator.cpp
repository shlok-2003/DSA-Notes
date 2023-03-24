#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    private:
        int health;
        char level;
    
    public:
        char *name;
    
    public:
        Hero() {
            name = new char[100];
        }

        void setName(char *name) {
            strcpy( this -> name, name);
        }

        void setLevel(char level) {
            this -> level = level;
        }

        void setHealth(int health) {
            this -> health = health;
        }

        void print() {
            cout << "----------------------------------\n";
            cout << "Name is: " << this -> name << endl;
            cout << "Level is: " << this -> level << endl;
            cout << "Health is: " << this -> health << endl;
            cout << "-----------------------------------\n";
        }

};

int main() {
    Hero h1;
    char name[] = "Shlok";
    h1.setName(name);
    h1.setLevel('A');
    h1.setHealth(100);
    h1.print();

    // Now you can assign the values of h1 to another object by assignment operator
    Hero h2;
    char name2[] = "Rohit";
    h2.setName(name2);
    h2.setLevel('B');
    h2.setHealth(69);
    h2.print();

    // Now assign the value of h2 to h1
    cout << "Answer would be: " << endl;
    h1 = h2;
    h1.print();
}