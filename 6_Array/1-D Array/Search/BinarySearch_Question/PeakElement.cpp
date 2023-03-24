#include<bits/stdc++.h>
using namespace std;

int solve(int arr[], int n) {
    int start = 0, end = n-1;
    while(start < end)
    {
        int mid = start + (end - start) / 2;

        if(arr[mid] > arr[mid + 1] && mid + 1 < n)
        {
            end = mid;
        }
        else{
            start = mid + 1;
        }
    }

    return arr[start]; // Or return end as both are equal
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << solve(arr, n) << endl;
    return 0;
}