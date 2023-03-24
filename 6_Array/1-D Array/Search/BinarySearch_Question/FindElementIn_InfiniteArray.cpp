#include<bits/stdc++.h>
using namespace std;

int binarySearch(int *arr, int start, int end, int target) {
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

    return -1;
}

int solve(int *arr, int n, int target) {
    int start = 0, end = 1;

    while(target > arr[end])
    {
        int newS = end + 1;
        end = end + (end - start + 1) * 2;

        start = newS;
    }

    return binarySearch(arr, start, end, target);
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