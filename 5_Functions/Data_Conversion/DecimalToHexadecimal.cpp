#include <bits/stdc++.h>
using namespace std;

string DecimalToHexadecimal(int n){
    int base = 1;
    string ans = "";
    
    while(base <= n)
    {
        base *= 16;
    }
    base /= 16;

    while(base > 0)
    {
        int quotient = n / base;
        if(quotient >= 0 && quotient <= 9)
        {
            ans = ans + to_string(quotient);
        }
        else if(quotient >= 10 && quotient <= 15)
        {
            char str = 'A' + quotient - 10;
            ans.push_back(str);
        }
        n -= quotient * base;
        base /= 16;
    }
    return ans;
}

int main(){
    int n;
    cin >> n;

    cout << DecimalToHexadecimal(n) <<endl;
    return 0;
}