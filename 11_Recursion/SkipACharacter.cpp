#include<bits/stdc++.h>
using namespace std;

string skip2(string str, string ans, char skipChar) {
    if(str.length() == 0)
    {
        return ans;
    }

    char ch = str[0];
    if(ch == skipChar)
    {
        return skip2(str.substr(1), ans, skipChar);
    }
    else
    {
        return skip2(str.substr(1), (ans + ch), skipChar);
    }
}

string skip(string str, char skipChar) {
    if(str.length() == 0)
    {
        return "";
    }

    char ch = str[0];
    string Sub = skip(str.substr(1), skipChar);

    if(ch == skipChar)
    {
        return Sub;
    }
    else
    {
        return ch + Sub;
    }

}

int main(){
    string str;
    cin >> str;

    char skipChar;
    cin >> skipChar;

    cout << skip(str, skipChar) << endl;
    cout << skip2(str, "", skipChar) << endl;
    return 0;
}