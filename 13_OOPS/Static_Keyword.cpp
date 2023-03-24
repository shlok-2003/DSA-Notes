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
            name =new char[100];
        }
};

int Hero::timeToComplete = 10;

int main() {
    // We can create a data member which can be accessed without the need of creation of an object. This can be achieved with static keyword;
    cout << "Static data member is accessed as: " << Hero::timeToComplete << endl;

    // It is not favourable to access static data members with objects. It can be done, but! when a data member is static, it is
    // designed for the class and not for the object. So keep this in mind.
}