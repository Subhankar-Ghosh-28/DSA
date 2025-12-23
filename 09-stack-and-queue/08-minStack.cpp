#include <bits/stdc++.h>
using namespace std;

class minStack
{

public:
    stack<pair<int, int>> st;

    void push(int val)
    {
        if (st.empty())
            st.push({val, val});

        else
        {
            st.push({val, min(val, st.top().second)});
        }
    }

    void pop()
    {
        if (st.empty())
            cout << "stack is empty.";
        st.pop();
    }

    void gettop()
    {
        if (st.empty())
            cout << "stack is empty.";
        cout << "Top element is : " << st.top().first << endl;
    }

    void Getmin()
    {
        if (st.empty())
            cout << "stack is empty.";
        cout << "Min: " << st.top().second << endl;
    }

    void display()
    {
        if (st.size() == 0)
            cout << "stack is empty.";
        cout << "Stack elements: ";
        stack<pair<int, int>> temp = st;
        while (!temp.empty())
        {
            cout << temp.top().first << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// optimal

class MinStack
{

public:
    stack<int> st;
    int mini = LONG_MIN;
    void push(int val)
    {
        if (st.empty())
        {
            mini = val;
            st.push(val);
        }

        else
        {
            if (val >= mini)
                st.push(val);
            else
            {

                st.push(2 * val - mini);
                mini = val;
            }
        }
    }

    void pop()
    {
        if (st.empty())
            cout << "stack is empty.\n";
        return;

        int x = st.top();
        st.pop();
        if (x < mini)
        {
            mini = 2 * mini - x;
        }
    }

    void Top()
    {
        if (st.empty())
            cout << "stack is empty.\n";

        int x = st.top();
        if (mini < x)
            cout << "Top: " << x << endl;

        cout << "Top: " << mini << endl;
    }

    void Getmin()
    {
        if (st.empty())
            cout << "stack is empty.\n";
        cout << "Min: " << mini << endl;
    }

    void display()
    {
        if (st.empty())
        {
            cout << "stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        stack<int> temp = st;
        int curMini = mini;
        while (!temp.empty())
        {

            int x = temp.top();
            temp.pop();

            int actual;
            if (x < curMini)
            {
                actual = curMini;
                curMini = 2 * curMini - x;
            }
            else
            {
                actual = x;
            }
            cout << actual << " ";
        }
        cout << endl;
    }
};

int main()
{
    MinStack st;

    st.push(5);
    st.push(7);
    st.push(3);

    st.Top();
    st.display();

    st.pop();

    st.display();
    st.Getmin();
    return 0;
}