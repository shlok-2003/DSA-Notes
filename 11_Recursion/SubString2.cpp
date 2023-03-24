#include<bits/stdc++.h>
using namespace std;

void subSeq2(string str, string ans) {
    if(str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    int ascii = ch;
    string rest = str.substr(1);

    subSeq2(rest, ans);
    subSeq2(rest, (ans + ch));
    subSeq2(rest, (ans + to_string(ascii)));
}

int main() {
    string str;
    cin >> str;

    subSeq2(str, "");
    return 0;
}