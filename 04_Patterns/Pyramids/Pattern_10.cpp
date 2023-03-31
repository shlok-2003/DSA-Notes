#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 4;              // number of rows
    
    for(int i = 1; i <= n; i++)
    {
        int j;
        for(j = 1; j <= (n - i); j++)
        {
            cout << "  ";
        }

        int k = 1;
        for(; j <= n; j++)
        {
            cout << k++ << " ";
        }

        k = 0;

        for(; j <= (n + i - 1); j++)
        {
            cout << char(65 + k++) << " ";
        }
        cout << endl;

    }
}