#include<bits/stdc++.h>
using namespace std;

int numberOfBits(int n)
{
    int count = 0;
    while(n)
    {
        n = (n & (n - 1));
        count++;
    }

    return count;
}

int main(){
    int n;
    cin >> n;

    cout << numberOfBits(n) << endl;
    return 0;
}