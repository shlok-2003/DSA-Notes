#include <bits/stdc++.h>
using namespace std;

//! Problem link: https://www.codingninjas.com/codestudio/problems/ninja-and-his-friends_3125885?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos

int maxPath3(vector<vector<int>> &arr, int n, int m) {                                      //! Method 3
    vector<vector<int>> front(m, vector<int>(m, 0)), curr(m, vector<int>(m, 0));

    for(int col1 = 0; col1 < m; col1++)             //? Base Condition
    {
        for(int col2 = 0; col2 < m; col2++)
        {
            if(col1 == col2)    front[col1][col2] = arr[n-1][col1];
            else                front[col1][col2] = arr[n-1][col1] + arr[n-1][col2];
        }
    }

    for(int row = n-2; row >= 0; row--)
    {
        curr.assign(m, vector<int>(m, 0));

        for(int col1 = 0; col1 < m; col1++)
        {
            for(int col2 = 0; col2 < m; col2++)
            {
                int maxi = -1e8;
                for(int delta1 = -1; delta1 <= 1; delta1++)
                {
                    for(int delta2 = -1; delta2 <= 1; delta2++)
                    {
                        int value = 0;
                        if(col1 == col2)    value += arr[row][col1];
                        else                value += arr[row][col1] + arr[row][col2];

                        if(col1+delta1 >= 0 && col1+delta1 < m && col2+delta2 >= 0 && col2+delta2 < m)
                            value += front[col1+delta1][col2+delta2];
                        else    
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }

                curr[col1][col2] = maxi;
            }
        }

        front = curr;
    }

    return front[0][m-1];
}

int maxPath2(vector<vector<int>> &arr, vector<vector<vector<int>>> &dp, int n, int m) {     //! Method 2
    for(int col1 = 0; col1 < m; col1++)             //? Base Condition
    {
        for(int col2 = 0; col2 < m; col2++)
        {
            if(col1 == col2)    dp[n-1][col1][col2] = arr[n-1][col1];
            else                dp[n-1][col1][col2] = arr[n-1][col1] + arr[n-1][col2];
        }
    }

    for(int row = n-2; row >= 0; row--)
    {
        for(int col1 = 0; col1 < m; col1++)
        {
            for(int col2 = 0; col2 < m; col2++)
            {
                int maxi = -1e8;
                for(int delta1 = -1; delta1 <= 1; delta1++)
                {
                    for(int delta2 = -1; delta2 <= 1; delta2++)
                    {
                        int value = 0;
                        if(col1 == col2)    value += arr[row][col1];
                        else                value += arr[row][col1] + arr[row][col2];

                        if(col1+delta1 >= 0 && col1+delta1 < m && col2+delta2 >= 0 && col2+delta2 < m)
                            value += dp[row+1][col1+delta1][col2+delta2];
                        else    
                            value += -1e8;

                        maxi = max(maxi, value);
                    }
                }

                dp[row][col1][col2] = maxi;
            }
        }
    }

    return dp[0][0][m-1];
}

int maxPath1(int row, int col1, int col2, vector<vector<int>> &arr, 
vector<vector<vector<int>>> &dp, int n, int m) {                                            //! Method 1

    if(col1 < 0 || col2 < 0 || col1 >= m || col2 >= m) return -1e8;
    if(row == n-1)
    {
        if(col1 == col2)    return arr[row][col1];
        else                return arr[row][col1] + arr[row][col2];
    }

    if(dp[row][col1][col2] != -1)   return dp[row][col1][col2];

    int maxi = -1e8;
    for(int delta1 = -1; delta1 <= 1; delta1++)             //? Each move of alice will have 3 choices for Bob, thus making 9 choices of moves for Bob
    {
        for(int delta2 = -1; delta2 <= 1; delta2++)
        {
            int value = 0;
            if(col1 == col2)    value += arr[row][col1];
            else                value += arr[row][col1] + arr[row][col2];

            value += maxPath1(row+1, col1+delta1, col2+delta2, arr, dp, n, m);

            maxi = max(maxi, value);
        }
    }

    return dp[row][col1][col2] = maxi;
}

int main() {
    int n, m;
    std::cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            std::cin >> arr[i][j];
        }
    }

    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    std::cout << "Memoization: " << maxPath1(0, 0, m-1, arr, dp, n, m) << std::endl;    //! Method 1 -> TC: O(N*M*M)  SC: O(N*M*M + N) 

    dp.resize(n, vector<vector<int>>(m, vector<int>(m, 0)));
    std::cout << "Tabulation: " << maxPath2(arr, dp, n, m) << std::endl;                //! Method 2 -> TC: O(N*M*M)  SC: O(N*M*M)

    std::cout << "Space Optimized: " << maxPath3(arr, n, m) << std::endl;               //! Method 3 -> TC: O(N*M*M)  SC: O(M*M)
}