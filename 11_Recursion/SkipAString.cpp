#include <bits/stdc++.h>
using namespace std;

string skip2(string str, string skipStr, string ans) {
    if(str.length() == 0)
    {
        return ans;
    }

    if(str.find(skipStr) == 0)
    {
        return skip2(str.substr(skipStr.length()), skipStr, ans);
    }
    else
    {
        return skip2(str.substr(1), skipStr, (ans + str[0]));
    }
}

string skip(string str, string skipStr, int n, string ans) {
    if(str.length() == 0)
    {
        return ans;
    }

    if(n <= str.length())
    {
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            if(str[i] != skipStr[i])
            {
                flag = false;
                break;
            }
        }

        if(!flag)
        {
            return skip(str.substr(1), skipStr, n, ans + str[0]);
        }
        else
        {
            return skip(str.substr(n), skipStr, n, ans);
        }
    }
    else
    {
        return skip(str.substr(str.length()), skipStr, n, (ans + str));
    }
}

int main() {
    string str;
    cin >> str;

    string skipStr;
    cin >> skipStr;

    cout << skip(str, skipStr, skipStr.size(), "") << endl;
    cout << skip2(str, skipStr, "") << endl;

    return 0;
}