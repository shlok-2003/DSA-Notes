#include <bits/stdc++.h>
using namespace std;

int helper(int n, int digit)
{
    if (n % 10 == n)
    {
        return n;
    }

    return (n % 10) * (int)round(pow(10, digit)) + helper(n / 10, digit - 1);
}

int rev(int n)
{
    int digit = round((int)(log10(n)));
    return helper(n, digit);
}
int main()
{
    int n;
    cin >> n;

    cout << rev(n) << endl;
    return 0;
}