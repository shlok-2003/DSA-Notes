#include<bits/stdc++.h>
using namespace std;

void subSeq(string str, string ans) {
    if(str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    int ascii = ch;

    subSeq(str.substr(1), (ans + ch));
    subSeq(str.substr(1), (ans + to_string(ascii)));
    subSeq(str.substr(1), ans);
}

int main(){
    string str;
    cin >> str;

    subSeq(str, "");
    return 0;
}