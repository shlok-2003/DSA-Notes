#include <iostream>
#include <vector>
using namespace std;

long long optimalClimbStair(int n) {                                //! Method 3 -> Optimized
    int prev1 = 1, prev2 = 1;
        
    for(int i = 1; i <= n; i++)
    {
        int curr = prev1 + prev2;
        prev1 = prev2;
        prev2 = curr;
    }

    return prev1;
}

long long climbStairs2(int n, vector<int> &dp) {                    //! Method 2 -> Tabulation
    dp[0] = 1, dp[1] = 1;

    for(int i = 2; i <= n; i++)
        dp[i] = dp[i-1] + dp[i-2];

    return dp[n];
}

long long climbStairs1(int n, vector<int> &dp) {                    //! Method 1 -> Memoization
    if(n <= 1)
        return 1;

    if(dp[n] == -1)
        dp[n] = climbStairs1(n-1, dp) + climbStairs1(n-2, dp);

    return dp[n];
}

int main() {
    int stair;
    cin >> stair;

    vector<int> dp(stair + 1, -1);
    cout << "Memoization: " << climbStairs1(stair, dp) << endl;             //! Method 1

    dp.resize(stair + 1, 0);
    cout << "Tabulation: " << climbStairs2(stair, dp) << endl;             //! Method 2

    cout << "Space Optimized Solution: " << optimalClimbStair(stair) << endl;   //! Method 3
}