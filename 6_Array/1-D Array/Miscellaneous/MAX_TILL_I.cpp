#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int arr[n];
    int maxnum = INT_MIN;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxnum = max(maxnum, arr[i]);
        cout << maxnum << " ";
    }

    return 0;
}