#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int tabulation(int n, int m, string &s, string &t, vector<vector<long long>> &dp) {
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 1;
    }
    for(int i = 1; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
            else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[n][m];
}

int memoization(int i, int j, string &s, string &t, vector<vector<long long>> &dp) {                              //! Method 1
    if(j == 0)
    {
        return 1;
    }
    if(i == 0)
    {
        return 0;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    if(s[i-1] == t[j-1])
    {
        return dp[i][j] = memoization(i-1, j-1, s, t, dp) + memoization(i-1, j, s, t, dp);
    }
    else
    {
        return memoization(i-1, j, s, t, dp);
    }
}

int main() {
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<vector<long long>> dp(n+1, vector<long long>(m+1, -1));
    cout << "Memoization: " << memoization(n, m, s, t, dp) << endl;                 //! Method 1 -> TC: O(N * M)  SC: O(N * M + (N + M))

    dp.resize(n+1, vector<long long>(m+1, 0));
    cout << "Tabulation: " << tabulation(n, m, s, t, dp) << endl;                 //! Method 2 -> TC: O(N * M)  SC: O(N * M)

    return 0;
}