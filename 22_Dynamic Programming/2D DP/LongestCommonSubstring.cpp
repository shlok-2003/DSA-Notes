#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//! This question is an extension of Longest Common Subsequence

int tabulation(int n, int m, string &s, string &t, vector<vector<int>> &dp) {
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }
    
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    string s, t;

    cin >> n >> m >> s >> t;

    int ans = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            ans = max(ans, tabulation(i, j, s, t, dp));
        }
    }

    cout << ans << endl;
    return 0;
}