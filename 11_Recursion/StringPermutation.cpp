#include<bits/stdc++.h>
using namespace std;

void permutation2(string str, string ans) {
    if(str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    for(int i = ans.length(); i >= 0; i--)
    {
        string first = ans.substr(0, i);
        string second = ans.substr(i);
        permutation2(str.substr(1), (first + ch + second));
    }
}

void permutation(string str, string ans) {
    if(str.length() == 0)
    {
        cout << ans << endl;
        return;
    }

    char ch = str[0];
    for(int i = 0; i <= ans.length(); i++)
    {
        string first = ans.substr(0, i);
        string second = ans.substr(i);
        permutation(str.substr(1), (first + ch + second));
    }
}

int main(){
    string str;
    cin >> str;

    permutation(str, "");
    cout << endl;
    permutation2(str, "");
    return 0;
}