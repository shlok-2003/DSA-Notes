#include<bits/stdc++.h>
using namespace std;

string skip(string str, string skipStr, string AnotherIfNotReqStr, string ans) {
    if(str.length() == 0)
    {
        return ans;
    }

    if(str.find(skipStr) != 0 && str.find(AnotherIfNotReqStr) == 0)
    {
        return skip(str.substr(AnotherIfNotReqStr.length()), skipStr, AnotherIfNotReqStr, ans);
    }
    else
    {
        return skip(str.substr(1), skipStr, AnotherIfNotReqStr, (ans + str[0]));
    }
}

int main(){
    string str;
    cin >> str;

    string skipStr, AnotherIfNotReqStr;    
    //! Dont skip a Skip String if its present but if its not present the skip the smaller version of if frome the main string.
    //! Ex, if apple is not present the skip app. Also if apple is present then dont skip "app"
    cin >> skipStr >> AnotherIfNotReqStr;

    cout << skip(str, skipStr, AnotherIfNotReqStr, "");

    return 0;
}