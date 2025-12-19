#include <bits/stdc++.h>
using namespace std;

/*
Prefic = +-abc-/mn
Infix = (p+q)*(m-n)
Postfix = pq+mn-*
*/

int priority(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string reverse(string s)
{
    int start = 0;
    int end = s.size() - 1;
    while (start < end)
    {
        int temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
    return s;
}

string infixToPostfix(string s)
{
    int n = s.size();
    int i = 0;
    stack<char> st;
    string ans = "";

    while (i < n)
    {
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9'))
        {
            ans += s[i];
        }
        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        // for oparator
        else
        {
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

string infixToPrefix(string s)
{

    // step 1 -> reverse the infix
    s = reverse(s);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ')')
            s[i] = '(';
        else if (s[i] == '(')
            s[i] = ')';
    }

    // step 2 -> infix to postfix
    //  after this same as infix  to postfix;
    stack<char> st;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isalnum(s[i]))
        {
            ans += s[i];
        }

        else if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else
        {
            //  if(!st.empty() && !isalpha(st.top()) && !isdigit(st.top())){
            //     if(s[i] == '^'){
            //         while( priority(s[i]) <= priority(st.top())){
            //             ans += st.top();
            //             st.pop();
            //         }
            //     }
            //     else {
            //         while( priority(s[i]) < priority(st.top())){
            //             ans += st.top();
            //             st.pop();
            //         }
            //     }
            //     st.push(s[i]);
            // }
            while (!st.empty() && priority(s[i]) <= priority(st.top()))
            {
                if (s[i] == '^' && st.top() == '^')
                    break; // right-associative
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // step 3 -> reverse the final ans
    ans = reverse(ans);

    return ans;
}

string postfixToInfix(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string t2 = st.top();
            st.pop();
            string t1 = st.top();
            string cov = "(" + t1 + c + t2 + ")";
            st.pop();
            st.push(cov);
        }
    }
    return st.top();
}

string prefixToInfix(string s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        char c = s[i];
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            string cov = "(" + t1 + c + t2 + ")";
            st.pop();
            st.push(cov);
        }
    }
    return st.top();
}

string postfixToPrefix(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        char c = s[i];
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string t2 = st.top();
            st.pop();
            string t1 = st.top();
            st.pop();
            st.push(c + t1 + t2);
        }
    }
    return st.top();
}

string prefixToPostfix(string s)
{
    stack<string> st;
    for (int i = s.size() - 1; i >= 0; --i)
    {
        char c = s[i];
        if (isalnum(c))
        {
            st.push(string(1, c));
        }
        else
        {
            string t1 = st.top();
            st.pop();
            string t2 = st.top();
            st.pop();
            st.push(t1 + t2 + c);
        }
    }
    return st.top();
}

int main()
{
    string s = "(m+n)*(p+q)";
    cout << "Infix expression: " << s << endl;
    cout << "Postfix expression: " << infixToPostfix(s) << endl;

    cout << "Postfix expression: " << infixToPostfix(s) << endl;
    cout << "Infix expression: " << postfixToInfix(infixToPostfix(s)) << endl
         << endl;

    cout << "Infix expression: " << s << endl;
    cout << "Prefix expression: " << infixToPrefix(s) << endl;

    cout << "Prefix expression: " << infixToPrefix(s) << endl;
    cout << "Infix expression: " << prefixToInfix(infixToPrefix(s)) << endl
         << endl;

    cout << "Postfix expression: " << infixToPostfix(s) << endl;
    cout << "Prefix expression: " << postfixToPrefix(infixToPostfix(s)) << endl
         << endl;

    cout << "Prefix expression: " << infixToPrefix(s) << endl;
    cout << "Postfix expression: " << prefixToPostfix(infixToPrefix(s)) << endl
         << endl;
    return 0;
}