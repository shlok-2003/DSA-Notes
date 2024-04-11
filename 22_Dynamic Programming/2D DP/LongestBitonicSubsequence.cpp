#include <bits/stdc++.h>
using namespace std;

vector<int> optimized(int n, vector<int> arr, bool direction) {
    if (direction == false)
    {
        reverse(arr.begin(), arr.end());
    }

    vector<int> dp(n, 1);
    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if(arr[idx] > arr[prev] && 1 + dp[prev] > dp[idx])
            {
                dp[idx] = 1 + dp[prev];
            }
        }
    }

    if(direction == false)
    {
        reverse(dp.begin(), dp.end());
    }
    return dp;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }

    vector<int> front = optimized(n, arr, true);
    vector<int> end = optimized(n, arr, false);

    int ans = 0;
    for(int i = 0; i < front.size(); i++)
    {
        int curr = front[i] + end[i] - 1;
        ans = max(ans, curr);
    }

    cout << "Longes Bitonic Subsequence: " << ans << endl;

    return 0;
}