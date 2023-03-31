#include <bits/stdc++.h>
using namespace std;

int DecimalToOctal(int n){
    int ans = 0;
    int base = 1;

    while(base <= n)
    {
        base *= 8;
    }
    base /= 8;

    while(base > 0)
    {
        int quotient = n / base;
        ans = ans * 10 + quotient;
        n -= quotient * base;
        base /= 8;
    }

    return ans;
}

int main(){
    int n;
    cin >> n;

    cout << DecimalToOctal(n) << endl;
    return 0;
}