#include <bits/stdc++.h>
using namespace std;

// 1432219 remove k = 3 digits = 1219 get smaller value

string func(string s, int k)
{
    stack<char> st;
    for (int i = 0; i < s.size(); i++)
    {
        while (!st.empty() && k > 0 && (st.top() - '0') > (s[i] - '0'))
        {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    while (k > 0)
    {
        st.pop();
        k--;
    }
    if (st.empty())
        return "0";
    string result = " ";
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }
    while (result.size() != 0 && result.back() == '0')
        result.pop_back();

    reverse(result.begin(), result.end());
    if (result.empty())
        return "0";
    return result;
}

int main()
{
    string s;
    cout << "Enter the string: ";
    cin >> s;
    cout << endl;
    int k;
    cout << "Enter the number remove: ";
    cin >> k;
    cout << endl;
    string ans = func(s, k);
    cout << "after removing k numbers of digit: " << ans << endl;
    return 0;
}