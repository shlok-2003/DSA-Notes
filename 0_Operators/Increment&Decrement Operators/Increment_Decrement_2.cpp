#include<iostream>
using namespace std;

int main(){
    int i, j, k;
    i=10;
    j=20;
    k=i++ + --j - ++i + ++j - i++ + --i;
    cout <<i<<endl;
    cout <<j<<endl;
    cout <<k<<endl;

}