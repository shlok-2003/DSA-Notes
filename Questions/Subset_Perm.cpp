#include<bits/stdc++.h>
using namespace std;

void subset(string str, string ans) {
    if(ans.length() == 3 && str.length() == 0)
    {
        do{
            cout << ans << endl;
        }
        while(next_permutation(ans.begin(), ans.end()));
        return;
    }

    if(str.length() == 0)
    {
        return;
    }

    char ch = str[0];
    subset(str.substr(1), ans + ch);
    subset(str.substr(1), ans);
}

int main(){
    string str;
    cin >> str;

    subset(str, "");
    return 0;
}