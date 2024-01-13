#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int optimized(int n, int m, string &s, string &t) {
    vector<int> prev(m+1, 0), curr(m+1, 0);
    
    for(int j = 0; j <= m; j++)
    {
        prev[j] = j;
    }

    for(int i = 1; i <= n; i++)
    {
        curr[i] = i;
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1])
            {
                curr[j] = prev[j-1];
            }
            else
            {
                curr[j] = 1 + min({ curr[j-1], prev[j], prev[j-1] });
            }
        }
        prev = curr;
    }

    return prev[m];
}

int tabulation(int n, int m, string &s, string &t, vector<vector<int>> &dp) {                   //! Method 2
    for(int j = 0; j <= m; j++)
    {
        dp[0][j] = j;
    }
    for(int i = 0; i <= n; i++)
    {
        dp[i][0] = i;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = 1 + min({ dp[i][j-1], dp[i-1][j], dp[i-1][j-1] });
            }
        }
    }

    return dp[n][m];
}

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
    cout << "Memoization: " << memoization(n, m, s, t, dp) << endl;                     //! Method 1 -> TC: O(N*M)  SC: O(N*M + N + M)

    dp.resize(n+1, vector<int>(m+1, 0));
    cout << "Tabulation: " << tabulation(n, m, s, t, dp) << endl;                       //! Method 2 -> TC: O(N*M)  SC: O(N*M)

    cout << "Optimized: " << optimized(n, m, s, t) << endl;                             //! Method 3 -> TC: O(N*M)  SC: O(M)
}