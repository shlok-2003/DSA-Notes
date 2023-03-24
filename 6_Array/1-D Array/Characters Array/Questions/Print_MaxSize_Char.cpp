#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

int main(){
    int n;              // Enter the size of string
    cin >> n;
    cin.ignore();

    char arr[n + 1];
    cin.getline(arr, n);

    int i = 0;
    int currLen = 0, maxLen = 0;
    int currPos = 0, maxPos = 0;

    while(true)
    {
        if(arr[i] == '\0' || arr[i] == ' ')
        {
            maxLen = max(currLen, maxLen);
            currLen = 0;
            maxPos = currPos;
            currPos = i + 1;
        }
        else{
            currLen++;

        }

        if(arr[i] == '\0')
        {
            break;
        }
        i++;
    }

    cout << maxLen << endl;
    for(int i = 0; i < maxLen; i++)
    {
        cout << arr[i + maxPos];
    }
    
    return 0;
}