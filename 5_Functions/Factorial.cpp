#include<iostream>
#include<cmath>
using namespace std;

void fac(int n){
    int nextTerm=(n-1);
    int ans = n;
    for(int i=nextTerm;i>=1;i--){
        ans *=nextTerm;
        nextTerm--;

    }
    cout << ans;
    return;
}

int main(){
    int n;
    cin >> n;

    fac(n);
    return 0;
}