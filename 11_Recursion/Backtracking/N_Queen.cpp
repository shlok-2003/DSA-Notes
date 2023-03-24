#include<bits/stdc++.h>
using namespace std;

void display(vector<vector<bool>> &board) {
    for(int i =  0; i < board.size(); i++)
    {
        for(int j = 0; j < board.size(); j++)
        {
            if(board[i][j])
            {
                cout << "Q" << " ";
            }
            else{
                cout << "X" << " ";
            }
        }
        cout << endl;
    }

    cout << endl;
}

bool isSafe(vector<vector<bool>> &board, int row, int col) {
    //vertical check
    for(int i = 0 ; i < row; i++)
    {
        if(board[i][col])
        {
            return false;
        }
    }

    //left diagonal check
    int minLeft = min(row, col);
    for(int i = 1; i <= minLeft; i++)
    {
        if(board[row - i][col - i])
        {
            return false;
        }
    }

    //right diagonal check
    int minRight = board.size() - col - 1;
    minRight = min(row, minRight);
    for(int i = 1; i <= minRight; i++)
    {
        if(board[row - i][col + i])
        {
            return false;
        }
    }

    return true;
}

int queen(vector<vector<bool>> &board, int row) {
    if(row == board.size())
    {
        display(board);
        return 1;
    }

    int count = 0;
    for(int col = 0; col < board.size(); col++)
    {
        if(isSafe(board, row, col))
        {
            board[row][col] = true;
            count += queen(board, row + 1);
            board[row][col] = false;
        }
    }

    return count;
}

int main(){
    int n;
    cin >> n;

    vector<vector<bool>> board(n, vector<bool>(n, false));
    cout << queen(board, 0) << endl;
    return 0;
}