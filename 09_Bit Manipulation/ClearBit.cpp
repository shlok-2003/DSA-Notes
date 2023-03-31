#include<bits/stdc++.h>
using namespace std;

int clearBit(int n, int pos){
    int mask = ~(1 << pos);

    return (n & mask);
}

int main(){
    int n;
    cin >> n;

    int pos;
    cin >> pos;

    cout << clearBit(n, pos) << endl;

    return 0;
}