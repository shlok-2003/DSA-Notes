#include <bits/stdc++.h>
using namespace std;

int reverse(int ans)
{
    int rev = 0;
    while(ans > 0)
    {
        int temp = ans % 10;
        rev = rev * 10 + temp;
        ans /= 10;
    }
    return rev;
}

int addBinary(int a, int b){
    int ans = 0;
    int prevCarry = 0;

    while(a > 0 && b > 0)
    {
        if(a % 2 == 0 && b % 2 == 0)
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 0;
        }
        else if((a % 2 == 1 && b % 2 == 0) || (a % 2 == 0 && b % 2 == 1))
        {
            if(prevCarry == 1)
            {
                ans = ans * 10 + prevCarry;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + prevCarry;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + prevCarry;
            prevCarry = 1;
        }
        a /= 10;
        b /= 10;
    }

    while(a > 0)
    {
        if(prevCarry == 1)
        {
            if(a % 2 == 1)
            {
                ans = ans * 10 + prevCarry;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + prevCarry;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (a % 2);
        }
        a /= 10;
    }

    while(b > 0)
    {
        if(prevCarry == 1)
        {
            if(b % 2 == 1)
            {
                ans = ans * 10 + prevCarry;
                prevCarry = 1;
            }
            else
            {
                ans = ans * 10 + prevCarry;
                prevCarry = 0;
            }
        }
        else
        {
            ans = ans * 10 + (b % 2);
        }
        b /= 10;
    }

    if(prevCarry == 1)
    {
        ans = ans *10 + prevCarry;
        prevCarry = 0;
    }

    ans = reverse(ans);
    return ans;
}

int main(){
    int n1, n2;
    cout << "Enter Two Binary Numbers\n"; 
    cin >> n1 >> n2;

    cout << addBinary(n1, n2) << endl;
    return 0;
}