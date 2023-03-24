//! Method 2
#include<bits/stdc++.h>
using namespace std;

string KeyPad[] = {"", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void pad(string digit, string ans, vector<string> &display) {
    if(digit.length() == 0)
    {
        display.push_back(ans);
        return;
    }

    char ch = digit[0];
    string code = KeyPad[ch - '0'];

    for(int i = 0; i < code.length(); i++)
    {
        pad(digit.substr(1), (ans + code[i]), display);
    }
}

int main(){
    string digit;
    cin >> digit;

    vector<string> display;
    pad(digit, "", display);

    for(int i = 0; i < display.size(); i++)
    {
        cout << display[i] << endl;
    }
    return 0;
}