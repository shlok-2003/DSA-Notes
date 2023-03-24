#include <bits/stdc++.h>
using namespace std;

int findIdx(int arr[], int i, int n, int key)
{
    if (i >= n)
    {
        return false;
    }

    if (arr[i] == key)
    {
        return i;
    }
    else
    {
        findIdx(arr, i + 1, n, key);
    }
}

bool find(int arr[], int i, int n, int key)
{
    if (i == n)
    {
        return false;
    }

    return (arr[i] == key) || find(arr, i + 1, n, key);
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
    int key;
    cin >> key;

    if (find(arr, 0, n, key))
    {
        cout << "Yes" << endl;
        cout << findIdx(arr, 0, n, key) + 1 << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}