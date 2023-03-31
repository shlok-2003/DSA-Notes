#include <bits/stdc++.h>
using namespace std;

/*  O(n ^ 2) solution

bool pairsum(int arr[], int n, int k){
    for(int i = 0; i < n; i++)
    {
        for(int j = i + 1; j < n; j++)
        {
            if(arr[i] + arr[j] == k)
            {
                cout << i << " " << j << endl;
                return 1;
            }
        }
    }

    return 0;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int k;                  // Sum equal to K
    cin >> k;

    cout << pairsum(arr, n, k) << endl;

    return 0;
}

*/

/* O(n) solution  */

bool pairsum(int arr[], int n, int k){
    int low = 0, high = n - 1;

    while(low < high)
    {
        if(arr[low] + arr[high] == k)
        {
            cout << low << " " << high << endl;
            return 1;
        }
        else if(arr[low] + arr[high] < k)
        {
            low++;
        }
        else
        {
            high--;
        }
    }
    
    return 0;
}

int main(){
    int n;
    cin >> n;

    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    // for this algo to work we have to sort the array first
    sort(arr, arr + n);


    int k;
    cin >> k;

    cout << pairsum(arr, n, k) << endl;

    return 0;
}

