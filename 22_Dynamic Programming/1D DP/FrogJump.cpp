#include <bits/stdc++.h>
using namespace std;

int optimalFrogJump(vector<int> &arr) {   //! Method 3 -> Space Optimization
    int n = arr.size();

    int prev1 = 0, prev2 = 0;
    for(int i = 1; i < n; i++)
    {
        int left = prev1 + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i > 1)   right = prev2 + abs(arr[i] - arr[i-2]);

        int curr = min(left, right);
        prev2 = prev1;
        prev1 = curr; 
    }

    return prev1;
}

int frogJump2(vector<int> arr) {        //! Method 2 -> Tabulation
    int n = arr.size();
    vector<int> dp(n, 0);

    dp[0] = 0;

    for(int i = 1; i < n; i++)
    {
        int left = dp[i-1] + abs(arr[i] - arr[i-1]);
        int right = INT_MAX;
        if(i > 1)   right = dp[i-2] + abs(arr[i] - arr[i-2]);

        dp[i] = min(left, right);
    }

    return dp[n-1];
}

int helper1(int idx, vector<int> &arr, vector<int> &dp) {
    if(idx == 0)    return 0;
    if(dp[idx] != -1)   return dp[idx];

    int left = helper1(idx-1, arr, dp) + abs(arr[idx] - arr[idx-1]);
    int right = INT_MAX;
    
    if(idx > 1) right = helper1(idx-2, arr, dp) + abs(arr[idx] - arr[idx-2]);

    return dp[idx] = min(left, right);
}

int frogJump1(vector<int> arr) {        //! Method 1 -> Memoization
    int n = arr.size();
    vector<int> dp(n, -1);

    return helper1(n-1, arr, dp);
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr)   cin >> i;

    cout << "Memoization: " << frogJump1(arr) << endl;                          //! Method 1 -> Memoization TC: O(N)  SC: O(N + K)
    cout << "Tabulation: " << frogJump2(arr) << endl;                           //! Method 2 -> Tabulation  TC: O(N)  SC: O(N)
    cout << "Space Optimized Solution: " << optimalFrogJump(arr) << endl;       //! Method 3 -> Space Optimization  TC: O(N)  SC: O(1)
}