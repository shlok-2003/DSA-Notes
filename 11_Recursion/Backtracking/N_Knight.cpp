#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> &board) {
    for(int i = 0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j])
            {
                cout << "K" << " ";
            }
            else{
                cout << "X" << " ";
            }
        }
        cout << endl;
    }
}

bool isValid(int row, int col, int n) {
    return (row >= 0 && row < n && col >= 0 && col < n) ? true : false;
}

bool isSafe(vector<vector<bool>> &board, int row, int col) {
    if(isValid(row - 1, col - 2, board.size()))
    {
        if(board[row - 1][col - 2])
        {
            return false;
        }
    }

    if(isValid(row - 1, col + 2, board.size()))
    {
        if(board[row - 1][col + 2])
        {
            return false;
        }
    }

    if(isValid(row - 2, col - 1, board.size()))
    {
        if(board[row - 2][col - 1])
        {
            return false;
        }
    }

    if(isValid(row - 2, col + 1, board.size()))
    {
        if(board[row - 2][col + 1])
        {
            return false;
        }
    }

    return true;
}

void maze(vector<vector<bool>> &board, int row, int col, int knight) {
    if(knight == 0)
    {
        display(board);
        cout << endl;
        return;
    }

    if(row == board.size() - 1 && col == board.size())
    {
        return;
    }

    if(col == board.size())
    {
        maze(board, row + 1, 0, knight);
        return;
    }

    if(isSafe(board, row, col))
    {
        board[row][col] = true;
        maze(board, row, col + 1, knight - 1);
        board[row][col] = false;
    }

    maze(board, row, col + 1, knight);
}

int main(){
    int n;
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    int knight;
    cin >> knight;

    maze(board, 0, 0, knight);
    return 0;
}