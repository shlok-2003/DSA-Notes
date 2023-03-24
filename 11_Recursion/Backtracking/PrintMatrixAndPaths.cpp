#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<bool>> maze, int r, int c, string ans, vector<vector<int>> path, int step) {
    if(r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        path[r][c] = step;
        for(int i = 0; i < maze.size(); i++)
        {
            for(int j = 0; j < maze[0].size(); j++)
            {
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
        cout << ans << "\n" << endl;

        path[r][c] = 0;
        return;
    }

    if(maze[r][c] == false)
    {
        return;
    }

    maze[r][c] = false;
    path[r][c] = step;

    if(r < maze.size() - 1)
    {
        print(maze, r + 1, c, ans + 'D', path, step + 1);
    }
    if(c < maze[0].size() - 1)
    {
        print(maze, r, c + 1, ans + 'R', path, step + 1);
    }
    if(r > 0)
    {
        print(maze, r - 1, c, ans + 'U', path, step + 1);
    }
    if(c > 0)
    {
        print(maze, r, c - 1, ans + 'L', path, step + 1);
    }
    
    maze[r][c] = true;
    path[r][c] = 0;

}

int main(){
    int n;
    cin >> n;

    vector<vector<bool>> maze(n, vector<bool>(n, true));
    vector<vector<int>> path(n, vector<int>(n, 0));

    print(maze, 0, 0, "", path, 1);
    return 0;
}