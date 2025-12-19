#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter a num : ";
    cin >> n;

    if ((n & n - 1) == 0)
        cout << "true";

    else
        cout << "false";
    return 0;
}