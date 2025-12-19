
#include <bits/stdc++.h>
using namespace std;

void print(int i, int x)
{
    if (i > x)
        return;

    cout << "raj" << "\n";

    print(i + 1, x);
}
int pow1(int n, int x)
{
    if (x == 0)
    {
        return 1;
    }
    n = n * pow1(n, x - 1);
    return n;
}
void f1(int i, int x)
{
    if (i < 0)
    {
        cout << x;
        return;
    }
    f1(i - 1, x + i);
}
bool parindrom(int i, string &s)
{
    if (i >= s.length() / 2)
        return true;
    if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }
    return parindrom(i + 1, s);
}
int fibonaci(int i)
{
    if (i == 0)
        return 0;
    if (i == 1)
        return 1;
    int last = fibonaci(i - 1);
    int slast = fibonaci(i - 2);
    int ans = last + slast;
    return ans;
}

int main()
{
    char arr[] = {"subha"};
    cout<<sizeof(arr); 
    return 0;
}