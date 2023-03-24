#include<bits/stdc++.h>
using namespace std;

int search(int arr[], int s, int e, int target) {
    if(s > e)
    {
        return -1;
    }

    int mid = s + (e - s) / 2;
    if(arr[mid] == target)
    {
        return mid;
    }
    else if(arr[mid] > target)
    {
        return search(arr, s, mid - 1, target);
    }
    else
    {
        return search(arr, mid + 1, e, target);
    }
}

int main(){
    int n;
    cin >> n;

    cout << "Enter sorted array" << endl;
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    cout << search(arr, 0, n - 1, target) << endl;
    return 0;
}