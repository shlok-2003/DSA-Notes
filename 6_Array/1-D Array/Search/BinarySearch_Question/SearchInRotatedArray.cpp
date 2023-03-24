#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int target, int start, int end) {
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

int findPivot(int arr[], int n) {
    int start = 0, end = n - 1;
    
    while(start <= end)
    {
        int mid = start + (end - start) / 2;
        
        if(arr[mid] > arr[mid + 1] && mid + 1 < n)
        {
            return mid;
        }
        if(arr[mid] < arr[mid - 1] && mid - 1 >= 0)
        {
            return mid - 1;
        }
        if(arr[start] >= arr[mid])
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

int solve(int arr[], int n, int target) {
    int pivot = findPivot(arr, n);
    
    if(pivot == -1)
    {
        binarySearch(arr, target, 0, n - 1);
    }
    
    if(arr[pivot] == target)
    {
        return pivot;
    }
    
    int phase1 = binarySearch(arr, target, 0, pivot - 1);
    if(phase1 != -1)
    {
        return phase1;
    }
    
    return binarySearch(arr, target, pivot + 1, n - 1);
}

int main() {
    int n = 10;
    
    int arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
    
    int target = 1;
    
    cout << solve(arr, n, target) << endl;
}