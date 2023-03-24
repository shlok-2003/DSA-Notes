#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }

    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(){
    int n;          // Enter the number to print nth fibonacci number
    cin >> n;

    cout << fibonacci(n) << endl;
    return 0;
}