#include<bits/stdc++.h>
using namespace std;

void decrement(int n){
    if(n == 0)
    {
        return;
    }

    cout << n << " ";
    decrement(n - 1);

    return;
}

void increment(int n){
    if(n == 0)
    {
        return;
    }

    increment(n - 1);
    cout << n << " ";

    return;
}

int main(){
    int n;
    cin >> n;

    increment(n);
    cout << endl;
    decrement(n);
    return 0;
}