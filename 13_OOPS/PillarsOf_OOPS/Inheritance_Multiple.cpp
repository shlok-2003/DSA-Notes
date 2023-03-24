#include<iostream>
using namespace std;

class Dad{
    public:
        void gender() {
            cout << "Dad" << endl;
        }
};

class Mom{
    public:
        void gender() {
            cout << "Mom" << endl;
        }
};

class Children: public Dad, public Mom{
    public:
        void siblings() {
            cout << "Brother" << endl;
        }
};

int main() {
    Children daughter;
    daughter.Dad::gender();     // If two of the super class has same function name, then it 
                                // would be hard for compiler to decide which function is being called, so we use "::" operator
    daughter.Mom::gender();
    daughter.siblings();
}