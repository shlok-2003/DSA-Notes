#include <bits/stdc++.h>
using namespace std;

int optimized(int n, vector<int> &arr) {
    vector<int> dp(n, 1), count(n, 1);

    int ans = 0, mx = 0;
    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[idx] > arr[prev])
            {
                if (dp[idx] == 1 + dp[prev])
                {
                    count[idx] += count[prev];
                }
                else if (1 + dp[prev] > dp[idx])
                {
                    dp[idx] = 1 + dp[prev];
                    count[idx] = count[prev];
                }
            }
        }
        mx = max(mx, dp[idx]);
    }

    for(int i = 0; i < n; i++)
    {
        if (dp[i] == mx)
        {
            ans += count[i];
        }
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int &i : arr)
    {
        cin >> i;
    }

    int ans = optimized(n, arr);

    cout << "Number of longest increasing subsequence is: " << ans << endl;
    return 0;
}