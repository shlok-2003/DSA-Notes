#include <bits/stdc++.h>
using namespace std;

int frogJump2(vector<int> &arr, int step, vector<int> &dp) {
    dp[0] = 0;
    for(int i = 1; i < arr.size(); i++)
    {
        int tmp = INT_MAX;
        for(int k = 1; k <= step; k++)
        {
            if(i - k >= 0)
                tmp = min(tmp, dp[i-k] + abs(arr[i] - arr[i-k]));
            else    break;
        }

        dp[i] = tmp;
    }

    return dp.back();
}

int frogJump1(int idx, vector<int> &arr, int step, vector<int> &dp) {
    if(idx == 0)    return 0;
    if(dp[idx] != -1)   return dp[idx];

    int mnStep = INT_MAX;
    for(int i = 1; i <= step; i++)
    {
        int tmp = INT_MAX;
        if(idx - i >= 0)
            tmp = frogJump1(idx - i, arr, step, dp) + abs(arr[idx] - arr[idx - i]);
        else   break;

        mnStep = min(mnStep, tmp);
    }

    return dp[idx] = mnStep;
}

int main() {
    int n;
    cin >> n;

    int step;
    cin >> step;

    vector<int> arr(n);
    for(int &i : arr)   cin >> i;

    vector<int> dp(n, -1);
    cout << "Memoization: " << frogJump1(n-1, arr, step, dp) << endl;       //! Method 1 -> Memoization  TC: O(N * K)  SC: O(N + K)

    dp.resize(n, 0);
    cout << "Tabulation: " << frogJump2(arr, step, dp) << endl;             //! Method 2 -> Tabulation  TC: O(N * K)  SC: O(N)

    //! Method 3 -> Space Optimization is not needed here as, when K = N, then overall Space Complexity will be O(N).
}