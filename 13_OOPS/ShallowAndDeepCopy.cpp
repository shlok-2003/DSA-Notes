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
            this -> health = health;
            this -> level = level;
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
            cout << "----------------------------------\n";
        }

};

class Vehicle{
    private:
        int health;
        char level;

    public:
        char *name;

    public:
        Vehicle() {
            this -> health = health;
            this -> level = level;
            name = new char[100];
        }

        Vehicle(Vehicle &temp) {
            char *ch = new char[strlen(temp.name) + 1];
            strcpy(ch, temp.name);
            this -> name = ch;

            this -> health = temp.health;
            this -> level = temp.level;
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
            cout << "----------------------------------\n";
        }
}; 

int main() {
    cout << "Shallow Copy example" << endl;
    Hero h1;
    char name[] = "Shlok";              // Initialized a block for storing name, this could have been done with string but, string is not
                                        // compatible with "this" keyword
    h1.setName(name);
    h1.setLevel('D');
    h1.setHealth(100);
    // Now print for h1
    h1.print();

    // Now using default copy constructor
    Hero h2(h1);
    // Print h2
    h2.print();

    // Now change h1 name;
    h1.name[0] = 'P';
    // Print h1
    h1.print();

    // But now if we print h2
    h2.print();
    // You can see that the data for the h2 object is also changed. This is shallow copy. Default copy constructor follows shallow copy
    // In shallow copy, as the data block for both the object is same, thus if we change data for any one of them, then the data would be
    // changed for all the data members
    // Definition of Shallow copy is
    /* 
    In shallow copy, an object is created by simply copying the data of all variables of the original object. This works well if none 
    of the variables of the object are defined in the heap section of memory. If some variables are dynamically allocated memory from 
    heap section, then the copied object variable will also reference the same memory location. This will create ambiguity and run-time 
    errors, dangling pointer. Since both objects will reference to the same memory location, then change made by one will reflect those
    change in another object as well. Since we wanted to create a replica of the object, this purpose will not be filled by Shallow copy. 
    */

    // Now we can resolve this by creating our own copy constructor
    // Lets make another class 
    cout << "Deep Copy example" << endl;
    Vehicle v1;
    char name2[] = "Rohit";
    v1.setName(name2);
    v1.setLevel('P');
    v1.setHealth(28);

    // Now lets print v1 and repeat the same process of printing
    v1.print();

    Vehicle v2(v1);
    v2.print();

    v1.name[0] = 'C';
    v1.print();

    v2.print();

    // Definition of Deep copy is
    /*
    In Deep copy, an object is created by copying data of all variables, and it also allocates similar memory resources with the same
    value to the object. In order to perform Deep copy, we need to explicitly define the copy constructor and assign dynamic memory as 
    well, if required. Also, it is required to dynamically allocate memory to the variables in the other constructors, as well.
    */
}