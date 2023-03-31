#include <iostream>
#include<cmath>
using namespace std;

bool prime(int n){

    for(int j=2;j<=sqrt(n);j++){
        if(n%j==0){
            return false;
        }
        
    }
    return true;   
    
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;

    for(int i=n1;i<=n2;i++){
        if(prime(i)){
            cout << i << endl;
        }
    }
    return 0;
}