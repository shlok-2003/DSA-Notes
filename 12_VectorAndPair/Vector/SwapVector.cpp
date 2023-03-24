#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> arr(5, 10);
    cout << "Before" << endl;
    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> brr(6, 50);
    for(auto i : brr)
    {
        cout << i << " ";
    }
    cout << endl;

    cout << "After" << endl;
    swap(arr, brr);

    for(auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    for(auto i : brr)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}