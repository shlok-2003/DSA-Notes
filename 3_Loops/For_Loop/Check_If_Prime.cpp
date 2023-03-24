#include <iostream> 
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool flag=0;

    for(int x=2;x<=sqrt(n);x++){
        if(n % x == 0){
            cout << "Not a Prime No" << endl;
            flag=1;
            break;
        }
    }
    if(flag==0){
        cout << "Prime Number";
    }
    
    
    return 0;
}