#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool optimized(int n, int m, string &s, string &t) {                                                            //! Method 3    
    vector<bool> prev(m+1, 0), curr(m+1, 0);
    
    prev[0] = true;
    for (int j = 1; j <= m; j++)
    {
        bool flag = true;
        for (int idx = 1; idx <= j; idx++)
        {
            if (t[idx - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        prev[j] = flag;
    }

    for(int i = 1; i <= n; i++)
    {
        curr[0] = false;
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1] || t[j-1] == '?')
            {
                curr[j] = prev[j-1];
            }
            else if(t[j-1] == '*')
            {
                curr[j] = curr[j-1] || prev[j];
            }
            else
            {
                curr[j] = false;
            }
        }
        prev = curr;
    }

    return prev[m];
}

bool tabulation(int n, int m, string &s, string &t, vector<vector<int>> &dp) {                                  //! Method 2
    dp[0][0] = true;                //? i == 0 and j == 0
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = false;
    }
    for(int j = 1; j <= m; j++)
    {
        bool flag = true;
        for(int idx = 1; idx <= j; idx++)
        {
            if(t[idx-1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(s[i-1] == t[j-1] || t[j-1] == '?')
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else if(t[j-1] == '*')
            {
                dp[i][j] = dp[i-1][j] || dp[i][j-1];
            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[n][m];
}

bool memoization(int i, int j, string &s, string &t, vector<vector<int>> &dp) {                             //! Method 1
    if(i == 0 && j == 0)
    {
        return true;
    }
    if (j == 0)
    {
        return false;
    }
    if(i == 0)
    {
        for(int idx = 1; idx <= j; idx++)
        {
            if(t[idx-1] != '*')
            {
                return false;
            }
        }

        return true;
    }

    if(dp[i][j] != -1)
    {
        return dp[i][j];
    } 

    if(s[i-1] == t[j-1] || t[j-1] == '?')
    {
        return memoization(i-1, j-1, s, t, dp);
    }
    else if(t[j-1] == '*')
    {
        return memoization(i, j-1, s, t, dp) || memoization(i-1, j, s, t, dp);
    }

    return false;
}

int main(){
    int n, m;
    string s, t;
    cin >> n >> m >> s >> t;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    cout << "Memoization: " << memoization(n, m, s, t, dp) << endl;                     //! Method 1 -> TC: O(N*M)  SC: O(N*M + N + M)

    dp.resize(n+1, vector<int>(m+1, 0));
    cout << "Tabulation: " << tabulation(n, m, s, t, dp) << endl;                       //! Method 2 -> TC: O(N*M)  SC: O(N*M)

    cout << "Optimized: " << optimized(n, m, s, t) << endl;                                                     //! Method 3 -> TC: O(N*M)  SC: O(M)
    return 0;
}