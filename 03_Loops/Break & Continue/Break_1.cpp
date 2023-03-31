#include<iostream>
using namespace std;

int main(){
    
    int n; 
    cin >> n;
    int x;
    
    if(n > 1){
        for(x=2 ; x <= n ; x++){
            if(n % x==0){
                cout << "Not a Prime Number" << endl;
                break;
            }        
        }
        if(x == n){
            cout << "Prime Number" << endl;
        }
    }
    else{
        cout << "Not a Prime Number" << endl;
    }
    return 0;
}