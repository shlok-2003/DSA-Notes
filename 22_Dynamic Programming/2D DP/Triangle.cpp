#include <bits/stdc++.h>
using namespace std;

int minPath3(vector<vector<int>> &triangle, int n) {
    vector<int> front(n, 0), curr(n, 0);
    for(int i = n-1; i >= 0; i--)
    {
        curr.assign(n, 0);
        for(int j = i; j >= 0; j--)
        {
            if(i == n-1)    curr[j] = triangle[i][j];
            else
            {
                int down = triangle[i][j] + front[j];
                int right = triangle[i][j] + front[j+1];

                curr[j]= min(down, right);
            }
        }
        front = curr;
    }

    return front[0];
}

int minPath2(vector<vector<int>> &triangle, vector<vector<int>> &dp, int n) {                       //! Method2
    for(int i = n-1; i >= 0; i--)
    {
        for(int j = i; j >= 0; j--)
        {
            if(i == n-1)    dp[i][j] = triangle[i][j];
            else
            {
                int down = triangle[i][j] + dp[i+1][j];
                int right = triangle[i][j] + dp[i+1][j+1];

                dp[i][j] = min(down, right);
            }
        }
    }

    return dp[0][0];
}

int minPath1(int row, int col, vector<vector<int>> &triangle, vector<vector<int>> &dp, int n) {     //! Method1
    if(row == n-1)  return triangle[row][col];
    if(dp[row][col] != -1)  return dp[row][col];

    int down = triangle[row][col] + minPath1(row+1, col, triangle, dp, n);
    int right = triangle[row][col] + minPath1(row+1, col+1, triangle, dp, n);

    return dp[row][col] = min(down, right);
}

int main() {
    int n;
    std::cin >> n;

    vector<vector<int>> triangle(n);
    for(int i = 0; i < n; i++)
    {
        triangle[i].resize(i+1, 0);
        for(int j = 0; j <= i; j++)
        {
            std::cin >> triangle[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n, -1));
    std::cout << "Memoization: " << minPath1(0, 0, triangle, dp, n) << endl; //! Method 1 -> Memoization  TC: O(N^2)  SC: O(N^2 + N) 

    dp.resize(n, vector<int>(n, 0));
    std::cout << "Tabulation: " << minPath2(triangle, dp, n) << endl;        //! Method 2 -> Tabulation   TC: O(N^2)  SC: O(N^2)

    std::cout << "Space Optimized: " << minPath3(triangle, n) << endl;   //! Method 3 -> Space Optimized  TC: O(N^2)  SC: O(N)
}