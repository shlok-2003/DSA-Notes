#include <bits/stdc++.h>
using namespace std;

int countPath3(int n) {
    vector<int> prev(n, 0), curr(n, 0);
    
    for(int i = 0; i < n; i++)
    {
        curr[i] = 0;                    //! To make the current array to be all 0s --> you can write 
                                        //! curr = vector<int>(n, 0) or curr.assign(n, 0) or curr.resize(n, 0);
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)    curr[j] = 1;
            else
            {
                int up = 0, left = 0;
                if(i > 0)   up = prev[j];
                if(j > 0)   left = curr[j-1];

                curr[j] = up + left;
            }
        }
        prev = curr;
    }

    return prev[n-1];
}

int countPath2(int n, vector<vector<int>> &dp) {                    //! Method 2
    dp[0][0] = 1;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)    continue;  //? Already initialized to 1

            int up = 0, left = 0;
            if(i > 0)   up = dp[i-1][j];
            if(j > 0)   left = dp[i][j-1];

            dp[i][j] = up + left;
        }
    }

    return dp[n-1][n-1];
}

int countPath1(int row, int col, vector<vector<int>> &dp) {        //! Method 1
    if(row == 0 && col == 0)    return 1;
    if(row < 0 || col < 0)      return 0;

    if(dp[row][col] != -1)  return dp[row][col];

    int left = countPath1(row, col-1, dp);
    int up = countPath1(row-1, col, dp);

    return dp[row][col] = left + up;
}

int main() {
    int n;
    cin >> n;

    //? Count Paths from (0, 0) to (n-1, n-1) in a n*n grid assuming you can only move right or down
    vector<vector<int>> grid(n, vector<int>(n, 1));     //? Initialize grid with 1 meaning all boxes can be visited

    vector<vector<int>> dp(n, vector<int>(n, -1));
    cout << "Memoization: " << countPath1(n-1, n-1, dp) << endl;    //! Method 1 -> Memoization  TC: O(N^2)  SC: O(N^2 + (N-1) + (M-1)) 

    dp.resize(n, vector<int>(n, 0));
    cout << "Tabulation: " << countPath2(n, dp) << endl;            //! Method 2 -> Tabulation   TC: O(N^2)  SC: O(N^2)

    cout << "Space Optimized: " << countPath3(n) << endl;           //! Method 3 -> Space Optimized  TC: O(N^2)  SC: O(N)
}