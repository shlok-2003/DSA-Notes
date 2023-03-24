#include<bits/stdc++.h>
using namespace std;

int Sqrt(int n) {
    long start = 1, end = n;

    while(start <= end)
    {
        long mid = start + (end - start) / 2;
        
        if(mid*mid == n)
            return mid;
        else if(mid*mid > n)
            end = mid - 1;
        else    
            start = mid + 1;
    }

    return end;
}

int main(){
    int n;
    cin >> n;

    cout << Sqrt(n) << endl;
    return 0;
}