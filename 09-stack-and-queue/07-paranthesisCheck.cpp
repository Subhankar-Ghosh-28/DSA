#include <bits/stdc++.h>
using namespace std;

bool paranthesis(string arr)
{
    stack<char> st;
    int n = arr.size();

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == '(' || arr[i] == '{' || arr[i] == '[')
        {
            st.push(arr[i]);
        }

        else
        {
            if (st.empty())
                return false;

            char ch = st.top();
            st.pop();

            if ((arr[i] == ')' && ch == '(') ||
                (arr[i] == '}' && ch == '{') ||
                (arr[i] == ']' && ch == '['))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

int main()
{
    string s = "()[{}()]";
    if (paranthesis(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;
    return 0;
}