#include<bits/stdc++.h>
using namespace std;

char solve(vector<char> &arr, char target) {
    int start = 0, end = arr.size() - 1;

    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] <= target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    return arr[start % arr.size()];
}

int main(){
    int n;
    cin >> n;

    vector<char> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    char target;
    cin >> target;

    cout << solve(arr, target) << endl;
    return 0;
}