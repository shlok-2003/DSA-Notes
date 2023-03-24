#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int start, int end) {
    int pivot = arr[start];
    int count = 0;

    for(int i = start + 1; i <= end; i++)
    {
        if(arr[i] <= pivot)
        {
            count++;
        }
    }
    int idx = start + count;
    swap(arr[start], arr[idx]);

    int i = start, j = end;
    while(i < idx && j > idx)
    {
        while(arr[i] <= pivot)
        {
            i++;
        }

        while(arr[j] > pivot)
        {
            j--;
        }

        if(i < idx && j > idx)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return idx;
}

void quickSort(int *arr, int start, int end) {
    if(start >= end)
    {
        return;
    }

    //! to bring the smaller element to the left side of pivot and bigger element to the right side
    int idx = partition(arr, start, end);

    //! recursively solve quickSort
    quickSort(arr, start, idx - 1);
    quickSort(arr, idx + 1, end);
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}