#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

void CountSort(vector<int> &arr, int n) {
    int mx = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        mx = max(mx, arr[i]);
    }

    int count[mx + 1] = {0};
    for(int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    for(int i = 1; i <= mx; i++)
    {
        count[i] += count[i - 1];
    }

    int ans[n];
    for(int i = n - 1; i >= 0; i--)
    {
        ans[--count[arr[i]]] = arr[i];
    }

    for(int i = 0; i < n; i++)
    {
        arr[i] = ans[i];
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    CountSort(arr, n);
    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}