#include <iostream>
#include <vector>
using namespace std;

void heapify(int *arr, int n, int i) {
    int largest = i;
    int leftIdx = 2 * i;
    int rightIdx = 2 * i + 1;

    if(leftIdx <= n && arr[largest] < arr[leftIdx])
        largest = leftIdx;
    if(rightIdx <= n && arr[largest] < arr[rightIdx])
        largest = rightIdx;

    if(largest != i)
        swap(arr[i], arr[largest]), heapify(arr, n, largest);
}

void BuildHeap(int *arr, int n) {
    for(int i = n / 2; i > 0; i--)
        heapify(arr, n, i);
}

void HeapSort(int *arr, int n) {
    BuildHeap(arr, n);
    
    int size = n;
    while(size > 1) 
    {
        // Step 1 : swap last element with first element
        swap(arr[size], arr[1]);
        size--;
        
        // Step 2 : Call heapify
        heapify(arr, size, 1);
        
    }
}

int main() {
    int n;
    cin >> n;

    int arr[n + 1];     //! Sorting by Max heap
    for(int i = 1; i < n + 1; i++)
        cin >> arr[i];

    HeapSort(arr, n);

    for(int i = 1; i < n + 1; i++)
        cout << arr[i] << " ";
    cout << endl;
}