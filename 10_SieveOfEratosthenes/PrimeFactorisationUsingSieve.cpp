#include<bits/stdc++.h>
using namespace std;

void primeFactorisation(int n){
    int spf[100] = {0};
    for(int i = 2; i <= n; i++)
    {
        spf[i] = i;
    } 

    for(int i = 2; i * i<= n; i++)
    {
        if(spf[i] == i)
        {
            for(int j = i * i; j <= n; j += i)
            {
                if(spf[j] == j)
                {
                    spf[j] = i;
                }
            }
        }
    }

    int ans = 0;
    while(spf[n] != n)
    {
        int tmp = n;
        int sum = 0;

        while(tmp != 1)
        {
            sum += spf[tmp];
            tmp /= spf[tmp];
        }
        n = sum;
        ans = sum;
    }

    cout << ans << endl;
}

int main(){
    int t;
    cin >>t;

    while(t--)
    {
        int n;
    cin >> n;

    primeFactorisation(n);
    return 0;
    }
}