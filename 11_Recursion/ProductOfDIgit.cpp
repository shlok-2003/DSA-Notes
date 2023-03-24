#include<bits/stdc++.h>
using namespace std;

int product(int n)
{
    if(n % 10 == n)
    {
        return n;
    }

    return (n % 10 * product(n / 10));
}

int main(){
    int n;
    cin >> n;

    cout << product(n) << endl;
    return 0;
}