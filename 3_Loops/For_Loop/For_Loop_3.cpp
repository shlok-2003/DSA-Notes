#include<iostream>
using namespace std;

int main(){
    int x;
    cin >> x;
    int sum=0;

    for(x ; x >= 0 ;){
        sum +=x ;
        cin >> x;
    }
    
    cout << sum << endl;
    return 0;
}
   