#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int subsetSum3(vector<int> &arr, int k, int n) {                                       //! Method 3
    vector<bool> prev(k+1, 0), curr(k+1, 0);
    prev[0] = curr[0] = 1;
    if(arr[0] <= k)    prev[arr[0]] = 1;                //? Base Condition

    for(int i = 1; i < n; i++)
    {
        curr.assign(k+1, 0);
        curr[0] = 1;                //? Base Condition  for every row, the first element is true, as per line 16
        for(int target = 1; target <= k; target++)
        {
            int not_take = prev[target];
            int take = 0;
            if(target >= arr[i])    take = prev[target-arr[i]];

            curr[target] = not_take | take;
        }

        prev = curr;
    }

    return prev[k];
}

int subsetSum2(vector<int> &arr, int k, int n) {              //! Method 2
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    
    for(int i = 0; i < n; i++)  dp[i][0] = 1;   //? Base Condition
    if(arr[0] <= k) dp[0][arr[0]] = 1;                          //? Base Condition

    for(int idx = 1; idx < n; idx++)
    {
        for(int target = 1; target <= k; target++)
        {
            int not_take = dp[idx-1][target];
            int take = 0;
            if(target >= arr[idx])  take = dp[idx-1][target-arr[idx]];

            dp[idx][target] = not_take | take;
        }
    }

    return dp[n-1][k];
}

int subsetSum1(int idx, int target, vector<int> &arr, vector<vector<int>> &dp) {            //! Method 1
    if(target == 0) return 1;
    if(idx == 0)    return arr[0] == target;

    if(dp[idx][target] != -1)   return dp[idx][target];

    int not_take = subsetSum1(idx-1, target, arr, dp);
    int take = 0;
    if(target >= arr[idx])  take = subsetSum1(idx-1, target-arr[idx], arr, dp);

    return dp[idx][target] = not_take | take;
}

int main() {
    int n;
    std::cin >> n;                  //? 0 <= n <= 10^3

    int target;
    std::cin >> target;             //? 0 <= target <= 10^3

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }

    //! 0 means no subArray is found and 1 means subArray is found with target

    vector<vector<int>> dp(n, vector<int>(target+1, -1));
    std::cout << "Memoization: " << subsetSum1(n-1, target, arr, dp) << std::endl;       //! Method 1 -> TC: O(N*target)  SC: O(N*target + N)

    std::cout << "Tabulation: " << subsetSum2(arr, target, n) << std::endl;         //! Method 2 -> TC: O(N*target)  SC: O(N*target)

    std::cout << "Space Optimized: " << subsetSum3(arr, target, n) << std::endl;        //! Method 3 -> TC: O(N*target)  SC: O(N)
}