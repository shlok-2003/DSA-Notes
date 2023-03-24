#include<bits/stdc++.h>
using namespace std;

bool MyCompare(pair<int, int> p1, pair<int, int> p2) {
    if(p1.first != p2.first)
    {
        return p1.first < p2.first;
    }
    else
    {
        return p1.second > p2.second;
    }
}

int main() {
    int n;
    cin >> n;
    
    vector<pair<int, int>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    cout << endl;
    sort(arr.begin(), arr.end(), MyCompare);
    
    cout << "Ans" << endl;
    for(int i = 0; i < n; i++)
    {
        cout << arr[i].first << " " << arr[i].second << endl;
    }
}