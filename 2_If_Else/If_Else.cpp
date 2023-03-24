#include<iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;

    int x = max(a, max(b, c));
    int y, z;
    if(x == a)
    {
        y = b;
        z = c;
    }
    else if(x == b)
    {
        y = a;
        z = c;
    }
    else{
        y = a;
        z = b;
    }

    if(y + z >= x)
    {
        if(x == y && x == z)
        {
            cout << "Equilateral Triangle" << endl;
        }
        else if(x == y || y == z || x == z)
        {
            cout << "Isosceles Triangle" << endl;
        }
        else
        {
            cout << "Scalene Triangle" << endl;
        }
    }
    else
    {
        cout << "Not a Triangle" << endl;
    }

    return 0;
}
