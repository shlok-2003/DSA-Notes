#include <bits/stdc++.h>
using namespace std;

int minPath3(vector<vector<int>> grid, int n) {                                               //! Method3
    vector<int> prev(n, 0), curr(n, 0);

    for(int i = 0; i < n; i++)
    {
        curr[i] = 0;                        //! To make the current array to be all 0s --> you can write 
                                            //! curr = vector<int>(n, 0) or curr.assign(n, 0) or curr.resize(n, 0); 
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)    curr[j] = grid[i][j];
            else
            {
                int left = grid[i][j], up = grid[i][j];
                if(i > 0)   up += prev[j];
                else        up += 1e9;

                if(j > 0)   left += curr[j-1];
                else        left += 1e9;

                curr[j] = min(left, up);
            }
        }

        prev = curr;
    }

    return prev[n-1];
}

int minPath2(vector<vector<int>> &grid, vector<vector<int>> &dp, int n) {                     //! Method2
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(i == 0 && j == 0)    dp[i][j] = grid[i][j];
            else
            {
                int left = grid[i][j], up = grid[i][j];       //? If you add INT_MAX, then it will give you wrong answer, 
                //? as INT_MAX + anything gives you negative number which would be smaller than any path sum
                
                if(i > 0)   up += dp[i-1][j];
                else        up += 1e9;   

                if(j > 0)   left += dp[i][j-1];
                else        left += 1e9;

                dp[i][j] =  min(left, up);
            }
        }
    }

    return dp[n-1][n-1];
}

int minPath1(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp, int n) {   //! Method1
    if(row == 0 && col == 0)    return grid[0][0];
    if(row < 0 || col < 0)      return 1e9;     //? If you add INT_MAX, then it will give you wrong answer, 
                //? as INT_MAX + anything gives you negative number which would be smaller than any path sum
    
    if(dp[row][col] != -1)      return dp[row][col];
    
    int left = grid[row][col] + minPath1(row, col-1, grid, dp, n);
    int up = grid[row][col] + minPath1(row-1, col, grid, dp, n);

    return dp[row][col] = min(left, up);
}

int main() {
    int n;
    std::cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            std::cin >> grid[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    std::cout << "Memoization: " << minPath1(n-1, n-1, grid, dp, n) << endl;  //! Method 1 -> Memoization  TC: O(N^2)  SC: O(N^2 + (N-1) + (M-1)) 

    std::cout << "Tabulation: " << minPath2(grid, dp, n) << endl;             //! Method 2 -> Tabulation   TC: O(N^2)  SC: O(N^2)

    std::cout << "Space Optimized: " << minPath3(grid, n) << endl;            //! Method 2 -> Space Optimized  TC: O(N^2)  SC: O(N)
}