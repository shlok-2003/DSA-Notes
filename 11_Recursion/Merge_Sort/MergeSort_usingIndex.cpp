#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int start, int mid, int end) {
    int len1 = mid - start + 1;
    int len2 = end - mid;

    int *first = new int[len1];
    int *second = new int[len2];

    for(int i = 0; i < len1; i++)
    {
        first[i] = arr[start + i];
    }

    for(int i = 0; i < len2; i++)
    {
        second[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0;
    int k = start;
    while(i < len1 && j < len2)
    {
        if(first[i] < second[j])
        {
            arr[k] = first[i++];
        }
        else
        {
            arr[k] = second[j++];
        }
        k++;
    }

    while(i < len1)
    {
        arr[k++] = first[i++];
    }

    while(j < len2)
    {
        arr[k++] = second[j++];
    }

    delete []first;
    delete []second;
}

void mergeSort(int *arr, int start, int end) {
    if(start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    mergeSort(arr, 0, n - 1);

    for(int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}