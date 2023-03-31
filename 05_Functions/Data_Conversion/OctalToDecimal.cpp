#include <bits/stdc++.h>
using namespace std;

int OctalToDecimal(int n){
    int ans = 0;
    int base = 1;

    while(n > 0)
    {
        int temp = n % 10;
        ans += temp * base;
        base *= 8;
        n /= 10;
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    cout << OctalToDecimal(n) << endl;
    return 0;
}