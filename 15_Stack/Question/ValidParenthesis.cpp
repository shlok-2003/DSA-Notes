#include<bits/stdc++.h>
using namespace std;

bool valid(string str) {
    stack<char> s;

    for(char c : str)
    {
        if(c == '(' || c == '{' || c == '[')
        {
            s.push(c);
        }
        else
        {   
            if(s.empty())
                return false;
            if(c == ')' && s.top() != '(')  
                return false;
            if(c == '}' && s.top() != '{')
                return false;
            if(c == ']' && s.top() != '[')
                return false;

            s.pop();
        }
    }

    return (s.empty() ? true : false);
}

int main(){
    string str;
    cin >> str;

    if(valid(str))
    {
        cout << "Valid Parenthesis" << endl;
    }
    else
    {
        cout << "Not Valid Parenthesis" << endl;
    }
    return 0;
}