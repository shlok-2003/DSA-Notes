#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<bool>> &maze, int i, int j, string ans) {
    if(i == maze.size() - 1 && j == maze[0].size() - 1)
    {
        cout << ans << endl;
        return;
    }

    if(!maze[i][j])
    {
        return;
    }

    if(i < maze.size() - 1)
    {
        print(maze, i + 1, j, ans + 'H');
    }
    if(j < maze[0].size() - 1)
    {
        print(maze, i, j + 1, ans + 'V');
    }
}

int main(){
    int grid;
    cin >> grid;

    vector<vector<bool>> maze(grid, vector<bool>(grid, true));
    
    int x, y;
    cin >> x >> y;
    maze[x][y] = false;

    print(maze, 0, 0, "");
    return 0;
}