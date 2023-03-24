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

bool solver(vector<vector<int>> &board) {
    bool flag = true;
    int row = -1;
    int col = -1;
    int n = board.size();

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == 0)
            {
                row  = i;
                col = j;
                flag = false;
                break;
            }
        }
        if(flag == false)
        {
            break;
        }
    }

    if(flag == true)
    {
        return true;
    }

    for(int num = 1; num <= 9; num++)
    {
        if(isSafe(board, row, col, num))
        {
            board[row][col] = num;
            if(solver(board))
            {
                return true;
            }
            else
            {
                board[row][col] = 0;
            }
        }
    }

    return false;
}

int main(){
    int n;
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, -1));
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    if(solver(board))
    {
        cout << endl;
        display(board);
    }
    else
    {
        cout << "Sudoko cannot be solved" << endl;
    }
    return 0;
}