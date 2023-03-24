#include<bits/stdc++.h>
using namespace std;

void subSeq(string str, string ans) {
    if(str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    string rest = str.substr(1);

    subSeq(rest, ans);
    subSeq(rest, (ans + ch));
}

int main(){
    string str;
    cin >> str;

    subSeq(str, "");
    return 0;
}