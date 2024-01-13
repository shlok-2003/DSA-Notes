#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x : arr) 
    {
        cin >> x;
    }

    int mini = arr[0];
    int maxProfit = 0;

    for(int i = 1; i < n; i++)
    {
        int profit = arr[i] - mini;
        maxProfit = max(maxProfit, profit);

        mini = min(mini, arr[i]);
    }

    cout << maxProfit << endl;
}