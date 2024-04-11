#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int optimized(int n, int m, string &s, string &t) {                                                     //! Method 3
    vector<int> prev(m + 1, 0), curr(m+1, 0);

    for (int i = 0; i <= n; i++)
    {
        prev[0] = 0;
    }
    curr[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        curr[0] = 0;
        for (int j = 1; j <= m; j++)
        {
            if (s[i - 1] == t[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
            }
            else
            {
                curr[j] = max(prev[j], curr[j - 1]);
            }
        }

        prev = curr;
    }

    return prev[m];
}   

int tabulation(int n, int m, string &s, string &t, vector<vector<int>> &dp) {                            //! Method 2
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
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int memoization(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp) {                  //! Method 1
    if(idx1 == 0 || idx2 == 0)
    {
        return 0;
    }

    if(dp[idx1][idx2] != -1)
    {
        return dp[idx1][idx2];
    }

    if(s1[idx1 - 1] == s2[idx2 - 1])
    {
        return dp[idx1][idx2] = 1 + memoization(idx1 - 1, idx2 - 1, s1, s2, dp);
    }

    return dp[idx1][idx2] = max(
        memoization(idx1 - 1, idx2, s1, s2, dp),
        memoization(idx1, idx2 - 1, s1, s2, dp)
    );
}

int main() {
    int n, m;
    string s1, s2;

    cin >> n >> m >> s1 >> s2;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    cout << "Memoization: " << memoization(n, m, s1, s2, dp) << endl;                   //! Method 1 -> TC: O(N * M)  SC: O(N * M + (N + M))

    dp.resize(n + 1, vector<int>(m + 1, 0));
    cout << "Tabulation: " << tabulation(n, m, s1, s2, dp) << endl;                     //! Method 2 -> TC: O(N * M)  SC: O(N * M)

    cout << "Optimized: " << optimized(n, m, s1, s2) << endl;                           //! Method 3 -> TC: O(N * M)  SC: O(M)
}