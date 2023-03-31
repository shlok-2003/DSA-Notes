#include <iostream>
using namespace std;

int main()
{
    int a;  // declaration
    a = 20; // initialisation

    cout << "size of the integer " << sizeof(a) << endl;

    float b;
    cout << "size of the float " << sizeof(b) << endl;

    char c;
    cout << "size of the character " << sizeof(c) << endl;

    bool d;

    cout << "size of the boolean " << sizeof(d) << endl;
    return 0;
}