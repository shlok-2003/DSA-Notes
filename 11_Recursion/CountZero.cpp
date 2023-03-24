#include <bits/stdc++.h>
using namespace std;

int zeros(int n, int count)
{
    if (n == 0)
    {
        return count;
    }

    if (n % 10 == 0)
    {
        count++;
    }

    return zeros(n / 10, count);
}

int main()
{
    int n;
    cin >> n;

    int count = 0;
    int ans = zeros(n, count);
    cout << ans << endl;
    return 0;
}