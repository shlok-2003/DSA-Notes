#include <bits/stdc++.h>
using namespace std;

//! Similar to LongestCommonSubsequence.cpp, but here we have to sort the words first

int optimized(int n, vector<string> &words) {
    sort(words.begin(), words.end(), [&](string a, string b)
         { return a.size() < b.size(); });

    vector<int> dp(n, 1);
    int ans = 0;
    for (int idx = 0; idx < n; idx++)
    {
        for (int prev = 0; prev < idx; prev++)
        {
            int k = 0;
            for (auto &ch : words[idx])
            {
                if (ch == words[prev][k])
                {
                    k++;
                }
            }

            if (k == words[prev].size() && words[prev].size() + 1 == words[idx].size())             //? Only one new element should be there
            {
                dp[idx] = max(dp[idx], 1 + dp[prev]);
            }
        }

        ans = max(ans, dp[idx]);
    }

    return ans;
}

int main() {
    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    int len = optimized(n, words);

    cout << "The longest string chain is: " << len << endl; 
    return 0;
}