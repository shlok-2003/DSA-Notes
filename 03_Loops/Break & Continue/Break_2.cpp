#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;
    int x;

    for(x=a;x<=b;x++){
        int i;
        for(i=2;i<b;i++){
            if(x%i==0){
                break;
            }
        }
        if(x==i){
            cout << x <<endl;
        }
    }

    return 0;
}