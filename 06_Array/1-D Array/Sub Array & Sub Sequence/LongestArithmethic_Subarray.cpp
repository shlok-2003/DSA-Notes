#include <bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    cin >> t;

    while(t--)
    {
        cin >> n;

        int arr[n];
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int ans = 2;                //ans = 2 because the length of the arithmethic subarray will be atleast 2 
        int pd = arr[1] - arr[0];       //pd = previous diff
        int j = 2;                  // we have the common difference till the position 1, so start from 2
        int curr = 2;               //current length will be minimum 2

        while(j < n)
        {
            if(pd == arr[j] - arr[j - 1])
            {
                curr++;
            }
            else
            {
                pd = arr[j] - arr[j - 1];
                curr = 2;
            }
            ans = max(ans, curr);
            j++;
        }
        cout << ans << endl;
    }
    return 0;
}