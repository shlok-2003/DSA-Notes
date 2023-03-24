#include<bits/stdc++.h>
using namespace std;

void reverse2(string str){
    if(str.length() == 0)
    {
        return;
    }

    string subStr = str.substr(1);
    reverse2(subStr);
    cout << str[0];
}

void reverse(string str, int i, int size){
    if(i == size)
    {
        return;
    }

    reverse(str, i + 1, size);
    cout << str[i] << " ";
}

int main(){
    string str;
    cin >> str;

    int n = str.size();
    reverse(str, 0, n);
    cout << endl;
    reverse2(str);
    return 0;
}