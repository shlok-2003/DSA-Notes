#include<bits/stdc++.h>
using namespace std;

void printPath(int n, int i, int j, string ans) {
    if(i == n - 1 && j == n - 1)
    {
        cout << ans << endl;
        return;
    }

    if(i < n - 1 && j < n - 1)
    {
        printPath(n, i + 1, j + 1, ans + 'D');      //Diagonal
    }
    if(i < n - 1)
    {
        printPath(n, i + 1, j, ans + 'H');          //Horizontal
    }
    if(j < n - 1)
    {
        printPath(n, i, j + 1, ans + 'V');          //Vertical
    }
}

int main(){
    int n;
    cin >> n;

    printPath(n, 0, 0, "");
    return 0;
}