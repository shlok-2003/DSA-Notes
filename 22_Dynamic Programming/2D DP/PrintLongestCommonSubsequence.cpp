#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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

int main() {
    int n, m;
    string s1, s2;

    cin >> n >> m >> s1 >> s2;

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    int size = tabulation(n, m, s1, s2, dp);
    string ans(size, '$');

    int i = n, j = m;
    size -= 1;
    while(i > 0 && j > 0)
    {
        if(s1[i-1] == s2[j-1])
        {
            ans[size] = s1[i-1];
            i--, j--, size--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            i--;
        }
        else
        {
            j--;
        }
    } 

    cout << ans << endl;
}