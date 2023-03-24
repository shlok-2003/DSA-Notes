#include<bits/stdc++.h>
using namespace std;

//! Method 2
string moveStr2(string str) {
    if(str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    string Sub = moveStr2(str.substr(1));

    if(ch == 'x')
    {
        return (Sub + ch);
    }
    else
    {
        return (ch + Sub);
    }
}

//! Method 1
string moveStr(string str) {
    if(str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    if(ch == 'x')
    {
        return (moveStr(str.substr(1)) + ch);
    }
    else
    {
        return (ch + moveStr(str.substr(1)));
    }
}

int main(){
    string str;
    cin >> str;

    cout << moveStr(str) << endl;
    cout << moveStr2(str) << endl;
    return 0;
}