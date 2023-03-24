#include<bits/stdc++.h>
using namespace std;

void print(int** maze, int r, int c, int n, int m, vector<vector<int>> &path) {
    if(r == n - 1 && c == m - 1)
    {
        path[r][c] = 1;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        path[r][c] = 0;
        return;
    }

    if(maze[r][c] == 0)
    {
        return;
    }

    maze[r][c] = 0;
    path[r][c] = 1;

    if(r < n - 1)
    {
        print(maze, r + 1, c, n, m, path);
    }
    if(c < m - 1)
    {
        print(maze, r, c + 1, n, m, path);
    }
    if(r > 0)
    {
        print(maze, r - 1, c, n, m, path);
    }
    if(c > 0)
    {
        print(maze, r, c - 1, n, m, path);
    }

    path[r][c] = 0;
    maze[r][c] = 1;
}

int main(){
    int n;
    cin >> n;

    int** maze = new int *[n];
    for(int i = 0; i < n; i++)
    {
        maze[i] = new int[n];
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }
    }
    cout << endl << "Ans is:" << endl;

    vector<vector<int>> path(n, vector<int>(n, 0));

    print(maze, 0, 0, n, n, path);
    
    for(int i = 0; i < n; i++)
    {
        delete[] *maze;
    }

    return 0;
}