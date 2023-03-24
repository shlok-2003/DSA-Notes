#include <bits/stdc++.h>
using namespace std;

bool Palin(string str, int s, int e)
{
    if (s >= e)
    {
        return true;
    }

    if (str[s] != str[e])
    {
        return false;
    }

    return Palin(str, s + 1, e - 1);
}

int main()
{
    string str;
    cin >> str;

    if (Palin(str, 0, str.size() - 1))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}