#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int memoization(int i, int j, string &s, string &t, vector<vector<int>> &dp) {                  //! Method 1
    if(i == 0)
    {
        return j;
    }
    if(j == 0)
    {
        return i;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(s[i-1] == t[j-1])
    {
        return memoization(i-1, j-1, s, t, dp);
    }
    else
    {
        return 1 + min({
            memoization(i, j-1, s, t, dp),      //? INSERT Operation
            memoization(i-1, j, s, t, dp),      //? REMOVE Operation
            memoization(i-1, j-1, s, t, dp)     //? REPLACE Operation 
        });
    }
}

int main() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << "Memoization: " << memoization(n, m, s, t, dp);                     //! Method 1 -> TC: O(N*M)  SC: O(N*M + N + M)
}