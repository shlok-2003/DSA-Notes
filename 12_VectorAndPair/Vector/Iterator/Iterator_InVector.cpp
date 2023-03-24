#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int>::iterator it;
    for(it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}