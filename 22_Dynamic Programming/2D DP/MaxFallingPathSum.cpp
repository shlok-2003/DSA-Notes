#include <bits/stdc++.h>
using namespace std;

int maxPath3(vector<vector<int>> &grid, int n, int m) {            //! Method3
    vector<int> prev(m, 0), curr(m, 0);

    for(int i = 0; i < m; i++)
        prev[i] = grid[0][i];

    for(int i = 1; i < n; i++)
    {
        curr.assign(m, 0);
        for(int j = 0; j < m; j++)
        {
            int up = grid[i][j] + prev[j];
            int leftDiag = grid[i][j], rightDiag = grid[i][j];
            
            if(j > 0)   leftDiag += prev[j-1];
            else        leftDiag += -1e9;

            if(j < m-1) rightDiag += prev[j+1];
            else        rightDiag += -1e9;

            curr[j] = max({ leftDiag, up, rightDiag });
        }

        prev = curr;
    }

    int ans = INT_MIN;
    for(int i = 0; i < m; i++)
        ans = max(ans, prev[i]);

    return ans;
}

int maxPath2(vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m) {            //! Method2
    for(int j = 0; j < m; j++)
        dp[0][j] = grid[0][j];

    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            int up = grid[i][j] + dp[i-1][j];
            int leftDiag = grid[i][j], rightDiag = grid[i][j];
            
            if(j > 0)   leftDiag += dp[i-1][j-1];
            else        leftDiag += -1e9;

            if(j < m-1) rightDiag += dp[i-1][j+1];
            else        rightDiag += -1e9;

            dp[i][j] = max({ leftDiag, up, rightDiag });
        }
    }

    int ans = INT_MIN;
    for(int i = 0; i < m; i++)
        ans = max(ans, dp[n-1][i]);

    return ans;
}

int helper1(int row, int col, vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m) {   //! Method1
    if(row < 0 || col < 0 || col >= m)  return -1e9;
    if(row == 0)    return grid[row][col];

    if(dp[row][col] != -1)  return dp[row][col];
    int leftDiag = grid[row][col] + helper1(row-1, col-1, grid, dp, n, m);
    int up = grid[row][col] + helper1(row-1, col, grid, dp, n, m);
    int rightDiag = grid[row][col] + helper1(row-1, col+1, grid, dp, n, m);

    return dp[row][col] = max({ leftDiag, up, rightDiag });
}

int maxPath1(vector<vector<int>> &grid, vector<vector<int>> &dp, int n, int m) {            //! Method1
    int ans = -1e9;
    for(int i = 0; i < m; i++)
    {
        ans = max(ans, helper1(n-1, i, grid, dp, n, m));
    }

    return ans;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> grid[i][j];
        }
    } 

    vector<vector<int>> dp(n, vector<int>(m, -1));
    std::cout << "Memoization: " << maxPath1(grid, dp, n, m) << std:: endl;     //! Method1 -> Memoization  TC: O(N * M)  SC: O(N^M + (N-1) + (M-1)) 

    dp.resize(n, vector<int>(m, 0));
    std::cout << "Tabulation: " << maxPath2(grid, dp, n, m) << std::endl;       //! Method2 -> Tabulation   TC: O(N * M)  SC: O(N * M)

    std::cout << "Space Optimized: " << maxPath3(grid, n, m) << std::endl;  //! Method3 -> Space Optimized  TC: O(N * M)  SC: O(M)
}