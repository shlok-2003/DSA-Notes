#include <bits/stdc++.h>
using namespace std;

int rev(int n, int digit)
{
    if (n % 10 == n)
    {
        return n;
    }

    return (n % 10) * (int)round(pow(10, digit)) + rev(n / 10, digit - 1);
}

bool Palin(int n)
{
    int digit = (int)(log10(n));

    return (n == rev(n, digit)) ? true : false;
}

int main()
{
    int n;
    cin >> n;

    if (Palin(n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}