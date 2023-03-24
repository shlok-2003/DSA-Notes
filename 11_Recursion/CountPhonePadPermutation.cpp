#include<bits/stdc++.h>
using namespace std;

string keyPad[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int pad(string str, string ans) {
    if(str.length() == 0)
    {
        return 1;
    }

    long long count = 0;

    char ch = str[0];
    string code = keyPad[ch - '0' - 1];
    for(int i = 0; i < code.length(); i++)
    {
        count += pad(str.substr(1), (ans + code[i]));
    }

    return count;
}

int main(){
    string str;
    cin >> str;

    cout << pad(str, "") << endl;

    return 0;
}

