#include <bits/stdc++.h>
using namespace std;

int optimized(vector<int> &arr) {                                                                               //! Method 3
    int n = arr.size();
    vector<vector<int>> ahead(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

    for(int j = 0; j <= 1; j++)
    {
        for(int k = 0; k <= 2; k++)
        {
            ahead[j][k] = 0;
        }
    }

    for(int idx = n-1; idx >= 0; idx--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            curr[buy][0] = 0;
            for(int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;

                if(buy)
                {
                    profit = max({
                        -arr[idx] + ahead[0][cap],
                        0 + ahead[1][cap]
                    });
                }
                else
                {
                    profit = max({
                        arr[idx] + ahead[1][cap - 1],
                        0 + ahead[0][cap]
                    });
                }

                curr[buy][cap] = profit;
            }
        }
        
        ahead = curr;
    }

    return ahead[1][2];
}

int tabulation(vector<int> &arr, vector<vector<vector<int>>> &dp) {                                             //! Method 2
    int n = arr.size();

    for(int j = 0; j <= 1; j++)
    {
        for(int k = 0; k <= 2; k++)
        {
            dp[n][j][k] = 0;
        }
    }

    for(int i = 0; i <= n; i++)
    {
        for(int j = 0; j <= 1; j++)
        {
            dp[i][j][0] = 0;
        }
    }

    for(int idx = n-1; idx >= 0; idx--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            for(int cap = 1; cap <= 2; cap++)
            {
                int profit = 0;

                if(buy)
                {
                    profit = max({
                        -arr[idx] + dp[idx + 1][0][cap],
                        0 + dp[idx + 1][1][cap]
                    });
                }
                else
                {
                    profit = max({
                        arr[idx] + dp[idx + 1][1][cap - 1],
                        0 + dp[idx + 1][0][cap]
                    });
                }

                dp[idx][buy][cap] = profit;
            }
        }
    }

    return dp[0][1][2];
}

int memoization(int idx, int buy, int cap, vector<int> &arr, vector<vector<vector<int>>> &dp) {                 //! Method 1
    if(idx == arr.size() || cap == 0) 
    {
        return 0;
    }

    if(dp[idx][buy][cap] != -1) 
    {
        return dp[idx][buy][cap];
    }

    int profit = 0;
    if(buy)
    {
        profit = max({
            -arr[idx] + memoization(idx + 1, 0, cap, arr, dp),
            0 + memoization(idx + 1, 1, cap, arr, dp)
        });
    }
    else
    {
        profit = max({
            arr[idx] + memoization(idx + 1, 1, cap - 1, arr, dp),
            0 + memoization(idx + 1, 0, cap, arr, dp)
        });
    }

    dp[idx][buy][cap] = profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x : arr) 
    {
        cin >> x;
    }
    
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));          //? 1 - buy | 0 - sell
    cout << "Memoization: " << memoization(0, 1, 2, arr, dp) << endl;                       //! Method 1 -> TC: O(N*2*3)  SC: O(N * 2 * 3 + N)

    dp.resize(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    cout << "Tabulation: " << tabulation(arr, dp) << endl;                                  //! Method 2 -> TC: O(N*2*3)  SC: O(N * 2 * 3)

    cout << "Optimized: " << optimized(arr) << endl;                                        //! Method 3 -> TC: O(N*2*3)      SC: O(2*3)

    return 0;
}