#include <bits/stdc++.h>
using namespace std;

int with_four_variable(vector<int> &arr) {
    int ahead_not_buy, ahead_buy, curr_not_buy, curr_buy;
    ahead_buy = ahead_not_buy = curr_buy = curr_not_buy = 0;

    int n = arr.size();

    for (int i = n - 1; i >= 0; i--)
    {
        curr_not_buy = max({
            arr[i] + ahead_buy,
            0 + ahead_not_buy
        });

        curr_buy = max({
            -arr[i] + ahead_not_buy,
            0 + ahead_buy
        });

        ahead_not_buy = curr_not_buy;
        ahead_buy = curr_buy;
    }

    return ahead_buy;
}

int optimized(vector<int> &arr) {                                                  //! Method 3
    int n = arr.size();
    vector<int> ahead(2, 0), curr(2, 0);

    ahead[0] = ahead[1] = 0;

    for (int i = n - 1; i >= 0; i--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;

            if (buy)
            {
                profit = max({
                    -arr[i] + ahead[0],
                    0 + ahead[1],
                });
            }
            else
            {
                profit = max({
                    arr[i] + ahead[1],
                    0 + ahead[0],
                });
            }

            curr[buy] = profit;
        }

        ahead = curr;
    }

    return ahead[1];
}

int tabulation(vector<int> &arr, vector<vector<int>> &dp) {                                                 //! Method 2
    int n = arr.size();

    dp[n][0] = dp[n][1] = 0;

    for(int i = n-1; i >= 0; i--)
    {
        for(int buy = 0; buy <= 1; buy++)
        {
            long profit = 0;

            if(buy)
            {   
                profit = max({
                    -arr[i] + dp[i + 1][0],
                    0 + dp[i + 1][1],
                });
            }
            else
            {
                profit = max({
                    arr[i] + dp[i + 1][1],
                    0 + dp[i + 1][0],
                });
            }

            dp[i][buy] = profit;
        }
    }

    return dp[0][1];
}

int memoization(int idx, int transaction, vector<int> &arr, vector<vector<int>> &dp) {                      //! Method 1
    if(idx == arr.size())
    {
        return 0;
    }

    if(dp[idx][transaction] != -1)
    {
        return dp[idx][transaction];
    }

    long profit = 0;
    if(transaction)
    {
        profit = max({
            -arr[idx] + memoization(idx + 1, 0, arr, dp),
            0 + memoization(idx + 1, 1, arr, dp)
        });
    }
    else
    {   
        profit = max({
            arr[idx] + memoization(idx + 1, 1, arr, dp),
            0 + memoization(idx + 1, 0, arr, dp)
        });
    }

    return dp[idx][transaction] = profit;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &x : arr) 
    {
        cin >> x;
    }
    
    vector<vector<int>> dp(n, vector<int>(2, -1));                                      //? 1 - buy | 0 - sell
    cout << "Memoization: " << memoization(0, 1, arr, dp) << endl;                      //! Method 1 -> TC: O(N*2)  SC: O(N * 2 + N)

    dp.resize(n+1, vector<int>(2, 0));
    cout << "Tabulation: " << tabulation(arr, dp) << endl;                              //! Method 2 -> TC: O(N*2)  SC: O(N * 2)

    cout << "Optimized: " << optimized(arr) << endl;                                    //! Method 3 -> TC: O(N)    SC: O(1)

    return 0;
}