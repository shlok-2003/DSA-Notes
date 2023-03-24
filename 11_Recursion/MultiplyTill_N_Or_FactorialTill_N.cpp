#include<bits/stdc++.h>
using namespace std;

int power(int n){
    if(n == 0)
    {
        return 1;
    }

    return n * power(n - 1);
}

int main(){
    int n;
    cin >> n;

    cout << power(n) << endl;
    return 0;
}