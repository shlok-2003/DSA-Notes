#include <iostream>
#include <vector>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;
    
    if(left < n && arr[largest] < arr[left])
        largest = left;
    if(right < n && arr[largest] < arr[right])
        largest = right;
        
    if(largest != i)
        swap(arr[largest], arr[i]), heapify(arr, n, largest);
}

void buildHeap(int arr[], int n) { 
    for(int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

void heapSort(int arr[], int n) {
    buildHeap(arr, n);
    
    int size = n-1;
    while(size > 0)
    {
        swap(arr[size], arr[0]);
        heapify(arr, size, 0);
        size--;
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n];     //! Sorting by Max heap
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    heapSort(arr, n);

    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}