#include<bits/stdc++.h>
using namespace std;

//! Method 2
string removeDup2(string str) {
    if(str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    string Sub = removeDup2(str.substr(1));
    if(ch == Sub[0])
    {
        return Sub;
    }
    else
    {
        return (ch + Sub);
    }
}

//! Method 1
bool helper(char ch, string Sub) {
    return ((Sub[0] == ch) ? true : false);
}

void removeDup(string str){
    if(str.length() == 0)
    {
        return;
    }

    if(helper(str[0], str.substr(1)))
    {
        removeDup(str.substr(1));
    }
    else{
        cout << str[0];
        removeDup(str.substr(1));
    }
}

int main(){
    string str;
    cin >> str;

    removeDup(str);
    cout << endl;
    cout << removeDup2(str) << endl;
    return 0;
}