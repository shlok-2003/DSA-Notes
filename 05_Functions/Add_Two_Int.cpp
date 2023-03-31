#include<iostream>
using namespace std;

int add(int n1, int n2){
    int ans = n1 + n2;
   
    return ans;
}

int main(){
    int n1, n2;
    cin >> n1 >> n2;

    cout << add(n1, n2) << endl;
    return 0;
}