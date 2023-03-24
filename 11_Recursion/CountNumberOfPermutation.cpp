#include<bits/stdc++.h>
using namespace std;

long long permutation2(string str, string ans) {
    if(str.length() == 0)
    {
        return 1;
    }

    char ch = str[0];
    int count = 0;
    for(int i = 0; i <= ans.length(); i++)
    {
        string first = ans.substr(0, i);
        string second = ans.substr(i);
        count += permutation2(str.substr(1), (second + ch + first));
    }

    return count;
}

void permutation(string str, string ans, long long *count) {
    if(str.length() == 0)
    {
        *count += 1;
        return;
    }

    char ch = str[0];
    for(int i = 0; i <= ans.length(); i++)
    {
        string first = ans.substr(0, i);
        string second = ans.substr(i);
        permutation(str.substr(1), (second + ch + first), count);
    }
}

int main(){
    string str;
    cin >> str;

    long long count = 0;
    permutation(str, "", &count);

    cout << count << endl;

    //! Method 2

    cout << permutation2(str, "") << endl;
    return 0;
}