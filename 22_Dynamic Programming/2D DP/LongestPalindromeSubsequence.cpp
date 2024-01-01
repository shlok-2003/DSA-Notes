#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
//! This question is an extension of Longest Common Subsequence

int tabulation(int n, int m, string &s, string &t, vector<vector<int>> &dp)
{ //! Method 2
    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = 0;
    }
    for (int i = 0; i <= m; i++)
    {
        dp[0][i] = 0;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string t = s;
    reverse(t.begin(), t.end());

    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    cout << "Longest Palindrome Subsequence: " << tabulation(n, n, s, t, dp) << endl;
}