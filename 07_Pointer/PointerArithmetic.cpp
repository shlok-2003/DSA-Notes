#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    int *nptr = &n;
    cout << nptr << endl;

    /* We can do only 4 operation on pointer: ++, --, + and - */

    nptr++;
    cout << nptr << endl;

    return 0;
}