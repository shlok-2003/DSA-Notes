#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int optimized(vector<int> &arr, int sum) {                                                  //! Method 3
    vector<int> prev(sum+1, 0), curr(sum+1, 0);
    prev[0] = curr[0] = 1;

    if(arr[0] <= sum)
    {
        prev[arr[0]] = 1;
    }

    for(int i = 1; i < arr.size(); i++)
    {
        for(int target = 0; target <= sum; target++)
        {
            int not_take = prev[target];
            int take = 0;
            if (arr[i] <= target)
            {
                take = prev[target - arr[i]];
            }

            curr[target] = not_take + take;
        }

        prev = curr;
    }

    return prev[sum];
}

int tabulation(int target, vector<int> &arr, vector<vector<int>> &dp) {                     //! Method 2
    for(int i = 0; i < arr.size(); i++) 
    {
        dp[i][0] = 1;
    }

    if(arr[0] <= target) 
    {
        dp[0][arr[0]] = 1;
    }

    if(arr[0] == 0)
    {
        dp[0][arr[0]]++;
    }

    for (int i = 1; i < arr.size(); i++)
    {
        for (int j = 0; j <= target; j++)
        {
            int not_take = dp[i - 1][j];
            int take = 0;
            if (arr[i] <= j)
            {
                take = dp[i - 1][j - arr[i]];
            }

            dp[i][j] = not_take + take;
        }
    }

    return dp[arr.size()-1][target];
}

int memoization(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {            //! Method 1
    if(target == 0) {
        return arr[idx] == 0 ? 2 : 1;               //? If target is 0, then we can take the element with value 0
    }

    if(idx == 0) {
        return arr[idx] == target;
    }

    int not_take = memoization(idx - 1, target, arr, dp);
    int take = 0;
    if(arr[idx] <= target) {
        take = memoization(idx - 1, target - arr[idx], arr, dp);
    }

    return dp[idx][target] = not_take + take;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int &i : arr) {
        cin >> i;
    }

    int sum;
    cin >> sum;

    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    cout << "Memoization: " << memoization(n - 1, sum, arr, dp) << endl;                                    //! Method 1 -> TC: O(N*target)  SC: O(N*target + N)

    dp.resize(n, vector<int>(sum+1, 0));
    cout << "Tabulation: " << tabulation(sum, arr, dp) << endl;                                             //! Method 2 -> TC: O(N*target)  SC: O(N*target)

    cout << "Space Optimized: " << optimized(arr, sum) << endl;                                             //! Method 3 -> TC: O(N*target)  SC: O(target)
}