#include<iostream>
#include<cstring>
using namespace std;

class Hero{
    public:
        char level;
        int health;
        static int timeToComplete;

    private:
        char *name;

    public:
        Hero() {
            name = new char[100];
        }

        static int random() {
            return timeToComplete;
        }
};

int Hero::timeToComplete = 69;

int main() {
    cout << "Static function returns only static data members: " << Hero::random() << endl;
    // Static function can also be accessed without the creation of Object. They cannot use "this" function, as this function is used to
    // point towards current object. As objects are not required for static function, "this" is not available for static function.
    // Even static function can only access static data members.
}