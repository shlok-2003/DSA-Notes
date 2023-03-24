#include <bits/stdc++.h>
using namespace std;

int DecimalToBinary(int n){
    int ans = 0;
    int base = 1;

    while(base <= n)
    {
        base *= 2;
    }
    base /= 2;

    while(base > 0)
    {
        int quotient = n / base;
        n -= base * quotient;
        ans = ans * 10 + quotient;
        base /= 2;
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    cout << DecimalToBinary(n) << endl;
    return 0;
}