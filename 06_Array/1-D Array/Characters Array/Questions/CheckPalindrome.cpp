#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;          
    cin >> n;       //Enter the size of string

    char arr[n + 1];
    cin >> arr;

    bool flag = true;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] != arr[n - 1 - i])
        {
            flag = false;
            break;
        }
    }

    /* Another Approach
        int i =0;
        while(arr[i] != '\0')
        {
            if(arr[i] != arr[n - 1 - i])
            {
                flag = false;
                break;
            }
            i++;
        }
    */

    if(flag == true)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}