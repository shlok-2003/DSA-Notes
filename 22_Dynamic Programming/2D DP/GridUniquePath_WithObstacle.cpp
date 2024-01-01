#include <bits/stdc++.h>
using namespace std;

int countPath3(vector<vector<int>> &grid, int n) {                                              //! Method3
    vector<int> prev(n, 0), curr(n, 0);

    for(int i = 0; i < n; i++)
    {
        curr[i] = 0;                        //! To make the current array to be all 0s --> you can write 
                                            //! curr = vector<int>(n, 0) or curr.assign(n, 0) or curr.resize(n, 0); 
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)    curr[j] = grid[i][j];
            else if(grid[i][j] == 0)    curr[j] = 0;
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

int countPath2(vector<vector<int>> &grid, vector<vector<int>> &dp, int n) {                     //! Method2
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)    dp[i][j] = grid[i][j];
            else if(grid[i][j] == 0)    dp[i][j] = 0;
            else
            {
                int up = 0, left = 0;
                if(i > 0)   up = dp[i-1][j];
                if(j > 0)   left = dp[i][j-1];

                dp[i][j] = up + left;
            }
        }
    }

    return dp[n-1][n-1];
}

int countPath1(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp, int n) {   //! Method1
    if(row == 0 && col == 0)    return grid[row][col] == 1 ? 1 : 0;
    if(row < 0 || col < 0)      return 0;
    if(grid[row][col] == 0)     return 0;

    if(dp[row][col] != -1)      return dp[row][col];

    int left = countPath1(row, col-1, grid, dp, n);
    int right = countPath1(row-1, col, grid, dp, n);

    return dp[row][col] = left + right;
}

int main() {
    int n;
    std::cin >> n;

    //! 1 -> walkable and 0 -> non-walkable
    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    std::cout << "Memoization: " << countPath1(n-1, n-1, grid, dp, n) << endl;  //! Method 1 -> Memoization  TC: O(N^2)  SC: O(N^2 + (N-1) + (M-1)) 

    dp.assign(n, vector<int>(n, 0));
    std::cout << "Tabulation: " << countPath2(grid, dp, n) << endl;             //! Method 2 -> Tabulation   TC: O(N^2)  SC: O(N^2)

    std::cout << "Space Optimized: " << countPath3(grid, n) << endl;           //! Method 3 -> Space Optimized  TC: O(N^2)  SC: O(N)
}