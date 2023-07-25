#include <bits/stdc++.h>
using namespace std;

int maxSum3(vector<int> &arr) {                    //! Method 3
    int prev1 = arr[0];
    int prev2 = 0;

    for(int i = 1; i < arr.size(); i++)
    {
        int pick = arr[i];
        if(i > 1)   pick += prev2;

        int notPick = prev1;

        int curr = max(pick, notPick);
        prev2 = prev1;
        prev1 = curr;
    }   

    return prev1;
}

int maxSum2(vector<int> &arr, vector<int> &dp) {                    //! Method 2
    dp[0] = arr[0];

    for(int i = 1; i < arr.size(); i++)
    {
        int pick = arr[i];
        if(i > 1)   pick += dp[i-2];

        int notPick = dp[i-1];

        dp[i] = max(pick, notPick);
    }

    return dp.back();
}

int maxSum1(int idx, vector<int> &arr, vector<int> &dp) {           //! Method 1
    if(idx == 0)    return arr[idx];
    if(idx < 0)     return 0;

    if(dp[idx] != -1)   return dp[idx];

    int pick = arr[idx] + maxSum1(idx-2, arr, dp);
    int notPick = maxSum1(idx-1, arr, dp);

    return dp[idx] = max(pick, notPick);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr)   cin >> i;

    vector<int> dp(n, -1);
    cout << "Memoization: " << maxSum1(n-1, arr, dp) << endl;       //! Method 1 -> Memoization  TC: O(N)  SC: O(N + N)

    dp.resize(n, 0);
    cout << "Tabulation: " << maxSum2(arr, dp) << endl;             //! Method 2 -> Tabulation  TC: O(N)  SC: O(N)

    cout << "Space Optimized: " << maxSum3(arr) << endl;            //! Method 3 -> Space Optimized  TC: O(N)  SC: O(1)
}