#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<bool>> maze, int r, int c, string ans) {
    if(r == maze.size() - 1 && c == maze[0].size() - 1)
    {
        cout << ans << endl;
        return;
    }

    if(maze[r][c] == false)
    {
        return;
    }

    maze[r][c] = false;

    if(r < maze.size() - 1)
    {
        print(maze, r + 1, c, ans + 'D');
    }
    if(c < maze[0].size() - 1)
    {
        print(maze, r, c + 1, ans + 'R');
    }
    if(r > 0)
    {
        print(maze, r - 1, c, ans + 'U');
    }
    if(c > 0)
    {
        print(maze, r, c + 1, ans + 'L');
    }

    maze[r][c] = true;
}

int main(){
    int n;
    cin >> n;

    vector<vector<bool>> maze(n, vector<bool>(n, true));

    print(maze, 0, 0, "");
    return 0;
}