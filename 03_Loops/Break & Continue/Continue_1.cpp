#include<iostream>
using namespace std;

int main(){

    int a=1, b=100;
    int x;
    for(x=a; x<=b; x++){
        if(x%3==0){
            continue;
        }
        cout << x << endl;
    }

    return 0;
}