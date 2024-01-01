#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;

int mostOptimized(int n, int maxWeight, vector<int> &weight, vector<int> &value) {
    vector<int> prev(maxWeight+1, 0);
    
    for (int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int remWeight = maxWeight; remWeight >= 0; remWeight--)
        {
            int not_pick = prev[remWeight];
            int pick = INT_MIN;

            if(weight[i] <= remWeight)
            {
                pick = value[i] + prev[remWeight - weight[i]];
            }

            prev[remWeight] = max(pick, not_pick);
        }
    }

    return prev[maxWeight];
}

int optimized(int n, int maxWeight, vector<int> &weight, vector<int> &value) {                                          //! Method 3
    vector<int> prev(maxWeight+1, 0), curr(maxWeight+1, 0);

    for(int i = weight[0]; i <= maxWeight; i++)
    {
        prev[i] = value[0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int remWeight = 0; remWeight <= maxWeight; remWeight++)
        {
            int not_pick = prev[remWeight];
            int pick = INT_MIN;

            if (weight[i] <= remWeight)
            {
                pick = value[i] + prev[remWeight - weight[i]];
            }

            curr[remWeight] = max(pick, not_pick);
        }

        prev = curr;
    }

    return prev[maxWeight];
}

int tabulation(int n, int maxWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {                //! Method 2
    for(int i = weight[0]; i <= maxWeight; i++)
    {
        dp[0][i] = value[0];
    }

    for(int i = 1; i < n; i++)
    {
        for(int remWeight = 0; remWeight <= maxWeight; remWeight++)
        {
            int not_pick = dp[i-1][remWeight];
            int pick = INT_MIN;

            if(weight[i] <= remWeight)
            {
                pick = value[i] + dp[i-1][remWeight-weight[i]];
            }

            dp[i][remWeight] = max(pick, not_pick);
        }
    }

    return dp[n-1][maxWeight];
}

int memoization(int idx, int remWeight, vector<int> &weight, vector<int> &value, vector<vector<int>> &dp) {             //! Method 1
    if(idx == 0) 
    {
        return weight[idx] <= remWeight ? value[idx] : 0;
    }

    if(dp[idx][remWeight] != -1) 
    {
        return dp[idx][remWeight];
    }

    int not_pick = memoization(idx-1, remWeight, weight, value, dp);
    int pick = INT_MIN;

    if(weight[idx] <= remWeight)
    {
        pick = value[idx] + memoization(idx-1, remWeight-weight[idx], weight, value, dp);
    }

    return dp[idx][remWeight] = max(pick, not_pick);
}

int main() {
    int n;
    cin >> n;

    vector<int> weight(n), value(n);
    for(int i = 0; i < n; i++)  
    {
        cin >> weight[i];
    }
    
    for(int i = 0; i < n; i++)  
    {
        cin >> value[i];    
    }

    int maxWeight;
    cin >> maxWeight;

    vector<vector<int>> dp(n+1, vector<int>(maxWeight+1, -1));
    cout << "Memoization: " << memoization(n - 1, maxWeight, weight, value, dp) << endl;    //! Method 1 -> TC: O(N*maxWeight)  SC: O(N*maxWeight + N)

    dp.resize(n, vector<int>(maxWeight+1, 0));
    cout << "Tabulation: " << tabulation(n, maxWeight, weight, value, dp) << endl;          //! Method 2 -> TC: O(N*maxWeight)  SC: O(N*maxWeight)

    cout << "More optimized: " << optimized(n, maxWeight, weight, value) << endl;           //! Method 3 -> TC: O(N*maxWeight)  SC: O(2 * maxWeight)
    
    cout << "Most optimized: " << mostOptimized(n, maxWeight, weight, value) << endl;       //! Method 4 -> TC: O(N*maxWeight)  SC: O(maxWeight)
}