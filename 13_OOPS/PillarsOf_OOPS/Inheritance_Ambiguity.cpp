#include<iostream>
using namespace std;

class Dad{
    public:
        void g1() {
            cout << "Dad" << endl;
        }
};

class Mom{
    public:
        void g2() {
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
    daughter.g1();
    daughter.g2();
    daughter.siblings();
}