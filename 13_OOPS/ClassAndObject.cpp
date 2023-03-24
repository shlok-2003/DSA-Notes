#include<iostream>
using namespace std;

class Hero{
    //properties

    public:
        string name;
        int health;

    private:
        string name2;
        int level;

    public:
        int setLevel(int l) {       // To set the values to the private data members and access it in other functions
            level = l;
        }

        int setName(string n) {     // To set the values to the private data members and access it in other functions
            name2 = n;
        }

        int getLevel() {            // To get the values of the private data members
            return level;
        }

        string getName() {          // To get the values of the private data members
            return name2;
        }

};

int main() {
    Hero h1;

    // By default, the data members of the class are private, i.e it cannot be accessed outside its bound. To access it gere in made,
    // We can use access modifiers.

    // There are three types of access modifiers : Public, Private and Protected

    // To access data members, make the properties public
    h1.name = "Shlok";
    h1.health = 100;
    cout << h1.health << " " << h1.name << endl;


    // We can access it by another way also which is by getter and setter method
    // i.e by making functions as mentioned below

    h1.setLevel(75);
    h1.setName("Vikas");

    cout << h1.getName() << " " << h1.getLevel() << endl;

    // Dynamic allocation of Object
    Hero *h2 = new Hero;
    h2 -> setLevel(65);
    h2 -> setName("Rohit");     // Or use * operator as (*h2).setName();

    cout << h2 -> getName() << " " << h2 -> getLevel() << endl;

}