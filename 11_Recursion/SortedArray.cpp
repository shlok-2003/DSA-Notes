#include <bits/stdc++.h>
using namespace std;

bool sorted(int arr[], int i, int n)
{
    if (n == 1)
    {
        return true;
    }

    return (arr[i] < arr[i + 1]) && sorted(arr, i + 1, n - 1);
}

int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    if (sorted(arr, 0, n))
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}