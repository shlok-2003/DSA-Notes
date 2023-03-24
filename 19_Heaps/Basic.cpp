#include <iostream>
using namespace std;

class Heap {
    private:
        int *arr;
        int size;

    public:
        Heap() {
            arr = new int[100];
            size = 0;
        }

        void Insertion(int val) {
            // increase size by 1
            size = size + 1;
            int idx = size;

            arr[idx] = val;

            while(idx > 1)
            {
                int parentIdx = idx / 2;
                if(arr[parentIdx] < arr[idx])
                    swap(arr[parentIdx], arr[idx]), idx = parentIdx;
                else    
                    break;
            }
        }

        void Deletion() {
            if(size == 0)
                cout << "Empty" << endl;
            else
            {
                // Swap the last and first element
                int idx = 1;
                swap(arr[idx], arr[size]);        //! or just make arr[1] = arr[size]; --> very efficient
                size = size - 1;

                
                while(idx < size)
                {
                    int leftIdx = 2 * idx;
                    int rightIdx = 2 * idx + 1;

                    if(leftIdx < size && arr[idx] < arr[leftIdx])
                        swap(arr[idx], arr[leftIdx]), idx = leftIdx;
                    else if(rightIdx < size && arr[idx] < arr[rightIdx])
                        swap(arr[idx], arr[rightIdx]), idx = rightIdx;
                    else    
                        break;
                }
            }
        }

        void print() {
            for(int i = 1; i <= size; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
};

void heapify(int arr[], int n, int i) {
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

int main() {
    // Implementation of Max Heap
    Heap h;
    h.Insertion(50);
    h.Insertion(55);
    h.Insertion(51);
    h.Insertion(65);
    h.Insertion(70);
    h.Insertion(50);
    // Print
    h.print();

    h.Deletion();   //! Deletion can be done acc. to complete binary tree's rule.
    cout << "After deletion: ";
    h.print();

    // Heapify Program
    cout << "After Heapify" << endl;
    int arr[] = {-1, 54, 53, 55, 52, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    for(int i = size / 2; i > 0; i--)
        heapify(arr, size, i);
    
    // Print Heap
    for(int i = 1; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

}