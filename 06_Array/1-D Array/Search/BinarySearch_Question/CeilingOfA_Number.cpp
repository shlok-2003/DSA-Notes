#include<bits/stdc++.h>
using namespace std;

int solve(int *arr, int n, int target) {
    if(target > arr[n - 1])
    {
        return -1;
    }

    int start = 0, end = n - 1;
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    return arr[start];
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << solve(arr, n, target) << endl;
    return 0;
}