#include <bits/stdc++.h>
using namespace std;

bool isKthBitSet(int n, int k)
{
    if ((n & (1 << (k - 1))) != 0)
        return true;
    else
        false;
}

int main()
{
    cout << isKthBitSet(13, 3);
    return 0;
}