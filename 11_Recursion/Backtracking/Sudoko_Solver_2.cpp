#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<int>> &board) {
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool isSafe(vector<vector<int>> &board, int row, int col, int num) {
    for(int i = 0; i < board.size(); i++)
    {
        if(board[i][col] == num)
        {
            return false;
        }
    }

    for(int i = 0; i < board.size(); i++)
    {
        if(board[row][i] == num)
        {
            return false;
        }
    }

    int N = (int)(sqrt(board.size()));
    int r = row - (row % N);
    int c = col - (col % N);

    for(int i = r; i < r + N; i++)
    {
        for(int j = c; j < c + N; j++)
        {
            if(board[i][j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

bool solver(vector<vector<int>> &grid) {
    for(int i = 0; i < grid.size(); i++)
    {
        for(int j = 0; j < grid.size(); j++)
        {
            if(grid[i][j] == 0)
            {
                
                for(int num = 1; num <= 9; num++)
                {
                    if(isSafe(grid, i, j, num))
                    {
                        grid[i][j] = num;
                        if(solver(grid))
                        {
                            return true;
                        }
                        else
                        {
                            grid[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> grid[i][j];
        }
    }

    if(solver(grid))
    {
        cout << endl;
        display(grid);
    }
    else
    {
        cout << "Sudoko cannot be solved" << endl;
    }
    return 0;
}