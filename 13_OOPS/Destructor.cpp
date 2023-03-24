#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    public:
        char level;
        int health;

    private:
        char *name;

    public:
        Hero() {
            cout <<"Constructor is called" << endl;
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

        char getName() {
            return health;
        }

        char getLevel() {
            return level;
        }

        int getHealth() {
            return health;
        }

        // Now we will create a destructor. It starts with ~ (Dilda sign)
        ~Hero() {
            cout << "Destructor is called" << endl;
        }
};

int main() {
    cout << "For h1" << endl;
    Hero h1;            // Static allocation


    cout << "For h2" << endl;
    Hero *h2 = new Hero;    // Dynamic allocation

    cout << endl;
    // Note, destructor is called automatically for static object. But for dynamic allocation, we have to manually call destructor
    delete h2;
}   