#include<iostream>
#include<cstring>
using namespace std;

class Animals{
    public:
        void love() {
            cout << "Animals are cute" << endl;
        }
};

class Dogs: public Animals{
    public:


};

int main() {
    Dogs GermanShephard;
    GermanShephard.love();
}