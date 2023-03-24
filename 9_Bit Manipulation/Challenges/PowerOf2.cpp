#include<bits/stdc++.h>
using namespace std;

bool isPowerOf2(int n)
{
    return (n && !(n & (n - 1))) ? true : false;
}

int main(){
    int n;
    cin >> n;

    if(isPowerOf2(n))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}