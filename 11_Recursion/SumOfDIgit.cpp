#include <bits/stdc++.h>
using namespace std;

int power(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 10 + power(n / 10));
}

int main()
{
    int n;
    cin >> n;

    cout << power(n) << endl;
    return 0;
}