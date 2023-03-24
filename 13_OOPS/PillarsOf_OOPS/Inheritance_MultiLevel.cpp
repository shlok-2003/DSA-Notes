#include<iostream>
#include<cstring>
using namespace std;

class Animals{
    public:
        void barks() {
            cout << "Dog is barking" << endl;
        }
};

class Dogs: public Animals{
    public:
        void sit() {
            cout << "Dog is sitting" << endl;
        }
};

class GermanShepherd: public Dogs{
    public:
        void stand() {
            cout << "Stand" << endl;
        }
};

int main() {
    GermanShepherd obj;
    obj.barks();
    obj.sit();
    obj.stand();
}