#include <bits/stdc++.h>
using namespace std;

int optimized(int n, vector<int> &arr)
{ //! Method 3
    vector<int> curr(n + 1, 0), ahead(n + 1, 0);
    for (int i = 0; i <= n; i++)
    {
        ahead[i] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int not_take = ahead[j + 1]; //? position shift for index j
            int take = 0;

            if (j == -1 || arr[i] > arr[j])
            {
                take = 1 + ahead[i + 1]; //? position shift for index j
            }

            curr[j + 1] = max(take, not_take);
        }
        ahead = curr;
    }

    return curr[-1 + 1]; //? position shift for index j
}

int tabulation(int n, vector<int> &arr, vector<vector<int>> &dp) {                                      //! Method 2
    for(int i = 0; i <= n; i++)
    {
        dp[n][i] = 0;
    }

    for(int i = n-1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int not_take = dp[i + 1][j + 1]; //? position shift for index j
            int take = 0;

            if (j == -1 || arr[i] > arr[j])
            {
                take = 1 + dp[i + 1][i + 1]; //? position shift for index j
            }

            dp[i][j + 1] = max(take, not_take);
        }
    }

    return dp[0][-1 + 1]; //? position shift for index j
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

int optimized(int n, vector<int> &arr) {                                                               //! Method 3
    vector<int> dp(n, 1);

    int ans = 1;                                    //? ans == 1 because the length of the longest increasing subsequence can be 1 at least
    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            if (arr[idx] > arr[prev])
            {
                dp[idx] = max(dp[idx], 1 + dp[prev]);
            }
        }
        ans = max(ans, dp[idx]);
    }

    // int ans = *max_element(dp.begin(), dp.end());                             // this is also a way to find the max element in the dp array

    return ans;
}

int bin_optimized(int n, vector<int> &arr) {                                                            //! Method 4
    vector<int> dp;
    int len = 0;

    for(int i = 0; i < n; i++)
    {
        if(i == 0 || arr[i] > dp.back())
        {
            dp.push_back(arr[i]);
            len++;
        }
        else
        {
            int idx = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
            dp[idx] = arr[i];
        }
    }

    return len;             //! Keep in mind that this method only returns the correct length of subsequence, 
    //! VERY IMPORTANT      //! but it may not be the correct subsequence itself
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

    cout << "Optimized: " << optimized(n, arr) << endl;                         //! Method 3 -> TC: O(N * log(N))  SC: O(N)

    cout << "Optimized with Binary Search: " << bin_optimized(n, arr) << endl;  //! Method 4 -> TC: O(N * log(N))  SC: O(N)
    return 0;
}