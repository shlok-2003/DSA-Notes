#include<iostream>
using namespace std;

int main(){
    float n1, n2, n3;
    cout <<"Enter n1"<<endl;
    cin >> n1;
    cout <<"Enter n2"<<endl;
    cin >> n2;
    cout <<"Enter n3"<<endl;
    cin >> n3;

    if(n1 >=0 && n2 >=0 && n3 >=0){
    int average;
    average=(n1+n2+n3)/3;
    cout <<average<<endl;
    }
    else{
        goto jump;
    }

    jump:
    {
        int sum=(n1+n2+n3);
        cout << sum;
    }
    return 0;
}