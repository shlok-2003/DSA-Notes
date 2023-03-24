#include<iostream>
#include<cmath>
using namespace std;

int fact(int num){
    int factorial = 1;
    for(int z=2;z<=num;z++){
        factorial *=z;
    }
    return factorial;
}

int main(){
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            cout << fact(i)/(fact(j)*fact(i-j));
        }
        cout << endl;
    }

    return 0;
}