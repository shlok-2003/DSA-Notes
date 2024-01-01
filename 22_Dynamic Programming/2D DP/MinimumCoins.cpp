#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

int optimized(int n, int x, vector<int> &arr) {                                                             //! Method 3
    vector<int> curr(x+1, 0), prev(x+1, 0);

    for(int curr = 0; curr <= x; curr++)
    {
        if(curr % arr[0] == 0)
        {
            prev[curr] = curr / arr[0];
        }
        else
        {
            prev[curr] = 1e9;
        }
    }

    for (int idx = 1; idx < n; idx++)
    {
        for (int current = 0; current <= x; current++)
        {
            int not_pick = prev[current];
            int pick = INT_MAX;

            if (arr[idx] <= current)
            {
                pick = 1 + curr[current - arr[idx]];
            }

            curr[current] = min(pick, not_pick);
        }

        prev = curr;
    }

    return prev[x];
}

int tabulation(int n, int x, vector<int> &arr, vector<vector<int>> &dp) {                                   //! Method 2
    for(int curr = 0; curr <= x; curr++)
    {
        if(curr % arr[0] == 0)
        {
            dp[0][curr] = curr / arr[0];
        }
        else
        {
            dp[0][curr] = 1e9;
        }
    }

    for(int idx = 1; idx < n; idx++)
    {
        for(int curr = 0; curr <= x; curr++)
        {
            int not_pick = dp[idx - 1][curr];
            int pick = INT_MAX;

            if(arr[idx] <= curr)
            {
                pick = 1 + dp[idx][curr - arr[idx]];
            }

            dp[idx][curr] = min(pick, not_pick);
        }
    }

    return dp[n - 1][x];
}

int memoization(int idx, int curr, vector<int> &arr, vector<vector<int>> &dp) {                             //! Method 1
    if(idx == 0) {
        return curr % arr[idx] == 0 ? curr / arr[idx] : 1e9;
    }

    if(dp[idx][curr] != -1) {
        return dp[idx][curr];
    }

    int not_pick = 0 + memoization(idx - 1, curr, arr, dp);
    int pick = INT_MAX;

    if(arr[idx] <= curr) {
        pick = 1 + memoization(idx, curr - arr[idx], arr, dp);
    }

    return dp[idx][curr] = min(pick, not_pick);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr)
    {
        cin >> i;
    }

    int x;
    cin >> x;

    vector<vector<int>> dp(n, vector<int>(x+1, -1));
    cout << "Memoization: " << memoization(n - 1, x, arr, dp) << endl;          //! Method 1 -> TC: O(N * X)  SC: O(N * X + N)

    dp.resize(n, vector<int>(x+1, 0));
    cout << "Tabulation: " << tabulation(n, x, arr, dp) << endl;                //! Method 2 -> TC: O(N * X)  SC: O(N * X)

    cout << "Optimized: " << optimized(n, x, arr) << endl;                      //! Method 3 -> TC: O(N * X)  SC: O(X)
}