#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int *nptr = &n;

    /* For printing the address */
    cout << &n << endl;
    cout << nptr << endl;

    /* For printing the value of n */
    cout << n << endl;

    *nptr = 2 * n;
    cout << *nptr << endl;
    cout << n << endl;

    return 0;
}