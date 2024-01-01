#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

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
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    return dp[n][m];
}

int main() {
    int n, m;
    string s, t;

    cin >> n >> m >> s >> t;

    vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
    int len = n + m - tabulation(n, m, s, t, dp);

    cout << "Length of Shortest Common SuperSequence: " << len << endl;

    string ans(len, '$');
    int i = n, j = m, idx = len-1;

    while(i > 0 && j > 0)
    {
        if(s[i-1] == t[j-1])
        {
            ans[idx] = s[i-1];
            i--, j--, idx--;
        }
        else if(dp[i-1][j] > dp[i][j-1])
        {
            ans[idx] = s[i-1];
            i--, idx--;
        }
        else
        {
            ans[idx] = t[j-1];
            j--, idx--;
        }
    }

    while(i > 0)
    {
        ans[idx] = s[i-1];
        i--, idx--;
    }

    while(j > 0)
    {
        ans[idx] = t[j-1];
        j--, idx--;
    }

    cout << "Shortest Common SuperSequence: " << ans << endl;

    return 0;
}