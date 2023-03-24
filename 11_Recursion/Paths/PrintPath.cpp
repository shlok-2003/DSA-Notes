#include<bits/stdc++.h>
using namespace std;

void paths2(int n, int i, int j, string ans, vector<string> &display) {
    if(i == n - 1 && j == n - 1)
    {
        display.push_back(ans);
        return;
    }

    if(i < n - 1)
    {
        paths2(n, i + 1, j, ans + 'R', display);
    }
    if(j < n - 1)
    {
        paths2(n, i, j + 1, ans + 'D', display);
    }
}

void paths(int n, int i, int j, string ans) {
    if(i == n - 1 && j == n - 1)
    {
        cout << ans << endl;
        return;
    }

    if(i < n - 1)
    {
        paths(n, i + 1, j, ans + 'R');
    }
    if(j < n - 1)
    {
        paths(n, i, j + 1, ans + 'D');
    }
}

int main(){
    int n;
    cin >> n;

    paths(n, 0, 0, "");
    cout << endl;

    vector<string> display;
    paths2(n, 0, 0, "", display);
    for(int i = 0; i < display.size(); i++)
    {
        cout << display[i] << endl;
    }
    return 0;
}