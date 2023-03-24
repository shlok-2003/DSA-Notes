#include<bits/stdc++.h>
using namespace std;

int paths(int n, int i, int j) {
    if(i == n - 1 || j == n - 1)
    {
        return 1;
    }

    return paths(n, i + 1, j) + paths(n, i, j + 1);
}

int main(){
    int n;
    cin >> n;

    cout << paths(n, 0, 0) << endl;
    return 0;
}