#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;

bool myCompare(pair<int, int> p1, pair<int, int> p2) {
    return p1.first < p2.first;
}

int main() {
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<pair<int, int>> pr;
    for(int i = 0; i < n; i++)
    {
        // Method 1
        /*
        pair<int, int> t;
        t.first = arr[i];
        t.second = i;
        pr.push_back(t);
        */

        // Method 2
        pr.push_back(make_pair(arr[i], i));     // C++ STL method
    }

    sort(pr.begin(), pr.end(), myCompare);
    for(int i = 0; i < pr.size(); i++)
    {
        arr[pr[i].second] = i;
    }

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}