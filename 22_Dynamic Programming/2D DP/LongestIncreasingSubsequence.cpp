#include <bits/stdc++.h>
using namespace std;

int tabulation(int n, vector<int> &arr, vector<vector<int>> &dp) {                                      //! Method 2
    for(int i = 0; i <= n; i++)
    {
        dp[n][0] = 0;
    }

    for(int i = n-1; i >= 0; i--)
    {
        for(int prev = i - 1; i >= -1; i--)
        {
            int not_take = dp[i+1][prev+1];
            int take = 0;

            if(prev == -1 || arr[i] > arr[prev])
            {
                take = 1 + dp[i+1][i+1];
            }

            dp[i][prev+1] = max(take, not_take);
        }
    }

    return dp[0][0];
}

int memoization(int idx, int prev_idx, vector<int> &arr, vector<vector<int>> &dp) {                     //! Method 1
    if(idx == arr.size())
    {
        return 0;
    }

    if(dp[idx][prev_idx + 1] != -1)
    {
        return dp[idx][prev_idx + 1];
    }

    int not_take = memoization(idx + 1, prev_idx, arr, dp);
    int take = 0;

    if(prev_idx == -1 || arr[idx] > arr[prev_idx])
    {
        take = 1 + memoization(idx + 1, idx, arr, dp);
    }

    return dp[idx][prev_idx + 1] = max(take, not_take);

    //? why prev_idx + 1?? ----> because prev_idx can be -1, and we cannot access dp[idx][-1] as it is out of bounds, so we will be doing
    //? coordinate shifting here, i.e. we will be shifting the prev_idx by 1, so -1 will become 0, 0 will become 1, and so on.
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr)
    {
        cin >> i;
    }

    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));                          // !for case idx == n ----> thats why n + 1 size
    cout << "Memoization: " << memoization(0, -1, arr, dp) << endl;             //! Method 1 -> TC: O(N * N)  SC: O(N * N + N)

    dp.resize(n+1, vector<int>(n+1, 0));
    cout << "Tabulation: " << tabulation(n, arr, dp) << endl;                   //! Method 2 -> TC: O(N * N)  SC: O(N * N)

    return 0;
}